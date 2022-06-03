#include<stdio.h>

void printarray(int x[]){
    int i;
for(i=0;i<10;i++){
        printf("%d ",x[i]);}
}


int main(){

int x[10],i,*p;

printf("%X %X",x,&x[0]);

for(i=0;i<10;i++){
        x[i]=555;}
    p=&x[0];
    printarray(p);

return 0;
}
