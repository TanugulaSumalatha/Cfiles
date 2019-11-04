 /***full duplex communication b/n 2 processes using namedpipe(fifo) with the help of threads***/
	#include<stdio.h>
	#include<pthread.h>
	#include<fcntl.h>
	#include<string.h>
        #include<unistd.h>
        #include <sys/types.h>
        #include <sys/stat.h>
    void * thread1(void *p)
      {
          int fd;
          char buf[128];
          fd=open("pipe1",O_WRONLY);
           if(fd<0)
             {
                 perror("open");
		 return;
             }
	   while(1)
	     {
		//scanf("%s",buf); //reads string without spaces
                gets(buf); //to read string with spaces
		write(fd,buf,strlen(buf)+1);
	     }
      }
    void * thread2(void *p)
      {
          int fd;
          char buf[128];
          fd=open("pipe2",O_RDONLY);
           if(fd<0)
             {
                 perror("open");
                 return;
             }
           while(1)
             {
                read(fd,buf,sizeof(buf));
                printf("received:%s\n",buf);
             }
      }
    void main()
     {
       pthread_t t1,t2;
       mkfifo("pipe1",0664);  //fifo creates,named pipe
       mkfifo("pipe2",0664);
       pthread_create(&t1,0,thread1,0);
       pthread_create(&t2,0,thread2,0);
       while(1);
     }


