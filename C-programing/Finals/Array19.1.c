#include <stdio.h>
#include <time.h>
#include <math.h>
void printarray(int x[]);

int main(){
    int x[10],i,temp=0,k,j;
    srand(time(0));

    for(i=0;i<10;i++){
            x[i]=1+rand()%10;
            for(j=0;j<i;j++){
            if(x[i]==x[j])
                {i--;
                break;}
            }
    }

    printarray(x);
    printf("\n\n");

    for(i=0;i<10;i++){
        for(k=i+1;k<10;k++)
        if(x[k]<x[i]){
        temp=x[k];
        x[k]=x[i];
        x[i]=temp;
        }
    }

    printarray(x);
    printf("\n\n\n%u",abs(-5));
    return 0;
    }
void printarray(int x[]){
        int i;
    for(i=0;i<10;i++){
            printf("%d ",x[i]);}
}
