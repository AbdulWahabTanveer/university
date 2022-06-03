#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int sum1(int n1,int n2);

int main(){
int a,b,c;
printf("enter a number\n");
scanf("%d",&a);
printf("enter second number\n");
scanf("%d",&b);
c=sum1(a,b);
printf("sum= %d",c);
return 0;
}
//a =12  12=n1
//b =5   5=n2


int sum1(int n1,int n2){
int a;
a=n1+n2;
return a;
}
