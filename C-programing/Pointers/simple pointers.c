#include<stdio.h>
int main(){
int a,b,c;
int *p=&c;
int *p1=&a;
int *p2=&b;
scanf("%d%d",p1,p2);
*p=*p1+*p2;
printf("Sum:%d",*p);
return 0;}
