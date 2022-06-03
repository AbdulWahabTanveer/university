#include <stdio.h>
#include <time.h>
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
for(k=0;k<10;k++){
        for(i=0;i<9;i++){
        if(x[i]>x[i+1]){
            temp=x[i];
            x[i]=x[i+1];
            x[i+1]=temp;
        }
    }}

printarray(x);
return 0;
}
void printarray(int x[]){
    int i;
for(i=0;i<10;i++){
        printf("%d ",x[i]);}
}
