//******checking fo cow mechanism (copy on write)**********
#include<stdio.h>
#include<unistd.h>
 int x=10; //global variable definied
void main()
 {
      if(fork())   //child process creation
        {        //parent process
            printf("IN parent:x=%d\n",x);
            x+=100;
            printf("in parent process x value afetr modification :%d \n",x);
        }
     else   
 	{
   	   printf("in child process x=%d\n",x);  
           sleep(5);                               
           printf("in child after delay x=%d \n",x);
           printf("in child x=%d;\n",x+=20);
        }
    

 }

//upon success fork() returns child pid to parent process,zero to child process
//cow:
// two processes child&parent acesses global varible from common place ,if any process wants to modify that variable value for that process a seperate copy is created,that value of variable not affects to other process
