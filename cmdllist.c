/***single linked list program using cmdline arguments***/
	#include<stdio.h>
	#include<stdlib.h>
      typedef struct Node
       {
         int data;
	 struct Node *next;
       }node;
      void add_node(node ** ,int);
      void print(node*); 
      int main(int argc,char *argv[])
       {
          node *hptr=0;
          for(int i=1;i<argc;add_node(&hptr,atoi(argv[i++])));
          print(hptr);
          return 0;
       }
      void add_node(node **ptr,int n)/**to insert nodes into linkedlist***/
      {
         node *temp=(node*) malloc(sizeof(node));
         temp->data=n;
         temp->next=(*ptr),*ptr=temp;
      }
      void print(node *ptr) /***********print function to print linkedlist****/
       {
           /* while(ptr!=NULL)  
              {
                 printf("%d  ",ptr->data);
                 ptr=ptr->next;
              }*/
           for(;ptr!=NULL;printf("%d ",ptr->data),ptr=ptr->next);
       }
       
