#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define over 5

void sumarray(int n[]);

int main(){
int a[5],b,c,i;
for(i=0;i<5;i++){
    printf("enter a number\n %d");
    scanf("%d",&a[i]);}
    sumarray(a);
return 0;
}
//a =12  12=n1
//b =5   5=n2


void sumarray(int n[]){
int i,sum=0;
for(i=0;i<5;i++){
    sum=sum+n[i];
}
printf("sum= %d",sum);
}
