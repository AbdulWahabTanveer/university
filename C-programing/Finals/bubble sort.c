#include <stdio.h>
#include <time.h>
void printarray(int x[]);

int main(){
int x[10],i,temp=0,k;
srand(time(0));

for(i=0;i<10;i++){
        x[i]=1+rand()%10;//1-10
        printf("%d ",x[i]);
}
printf("\n\n");
for(k=0;k<10;k++){
        for(i=0;i<9;i++){//0-8
        if(x[i]>x[i+1]){//0th-1st
            temp=x[i];
            x[i]=x[i+1];
            x[i+1]=temp;
        }
    }}

printarray(x);
return 0;
}
void printarray(int age[]){
    int i;
for(i=0;i<10;i++){
        printf("%d ",age[i]);}
}
