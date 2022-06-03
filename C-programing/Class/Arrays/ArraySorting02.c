#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
srand(time(0));
int a[10],i,j,temp,min,index;
for(i=0;i<10;i++)
    a[i]=(rand()%500);
for(i=0;i<10;i++)
    printf("%d  ",a[i]);

for(i=0;i<9;i++){
    min=a[i];
    index=i;
    for(j=i;j<10;j++)
        if(min<a[j]){
        min=a[i];
        index=i;
        }
        temp=a[i];
        a[i]=min;
        a[index]=temp;
}
printf("\n\n");
for(i=0;i<10;i++)
    printf("%d  ",a[i]);
}
