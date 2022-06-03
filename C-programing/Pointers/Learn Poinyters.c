#include<stdio.h>
void in(int *p,int *p1);
void sum(int *p,int *p1,int *p2);
void prin(int *p);
int main(){
int a,b,c;
in(&a,&b);
sum(&a,&b,&c);
prin(&c);
return 0;}

void in(int *p,int *p1){
scanf("%d",p);
scanf("%d",p1);
}
void sum(int *p,int *p1,int *p2){
*p2=*p1+*p;
}
void prin(int *p){
printf("sum;%d",*p);
}
