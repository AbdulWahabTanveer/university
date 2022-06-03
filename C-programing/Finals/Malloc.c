#include <stdio.h>
#include<stdlib.h>
void print(int a[], const int SIZE){
    for (int i=0;i<SIZE;i++)
        printf("Element %d is %d\n",i, a[i]);
    printf("\n\n");
}
int main(){
    int n,*p,i;
    printf("Enter the size of DynamicArray:");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        p[i]=rand()%20;
    }
    print(p,n);
    return 0;
}
