/*Process synchronization using Semaphore to access a common resource*/
        #include<stdio.h>
        #include<sys/sem.h>
        #include <sys/types.h>
        #include <sys/stat.h>
        #include <fcntl.h>
        #include<unistd.h>
  void main()
  {
      int fd,i=0,id;
      char a[20]="123456";
      struct sembuf v;
      id=semget(8,1,IPC_CREAT|0664); // semaphore created
 
         if(id<0)
          {
            perror("semget");
            return;
          }
      fd=open("temp",O_WRONLY|O_CREAT|O_APPEND,0664);//temp file is resource
   
        if(fd<0)
          {
             perror("open");
             return;
          }
      v.sem_num=0;
      v.sem_op=0;   //if sem_op=0,and semaphore value is 0 then resource is free
      v.sem_flg=0;
     printf("waiting for signal..\n");
     semop(id,&v,1);
     semctl(id,0,SETVAL,1);  //resource locked by setting semaphore value to 1
     printf("P1 process writng into file\n");
      for(int k=25;k>0;k--)
        {
          while(a[i])
            {
                 write(fd,a+i,1);
                 //sleep(1);
                 i++;
            }
            i=0;
        }

    printf("P1 process writing completed\n");
     //  sleep(8);
     printf("P1 process will release resource\n");
     semctl(id,0,SETVAL,0);  //resource released by setting semaphore value to 0
  }






















