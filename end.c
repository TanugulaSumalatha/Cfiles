#include<stdio.h>
 union little
 {
  int i;
  char c;
 }u;
 int conversion(int);
void main()
{
 u.i=1;
 int d=0x12345678;
 if(u.c==1)
 {
  printf("little endian\n");
  int x=conversion(d);
   printf("%x\n",x);
 }
 else
  printf("big endian\n");
}
int conversion(int d)
{
 d=((0x000000ff&d)<<24)|((0x0000ff00&d)<<8)|((0x00ff0000&d)>>8)|((0xff000000&d)>>24);
 printf("\n%x\n",d);
 return d;
}























