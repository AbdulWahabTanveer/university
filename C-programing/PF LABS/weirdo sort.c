#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int i,j,l,k,temp;
    int a[4][4];

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            scanf("%d",&a[i][j]);
        }
    }

    scanf("%d",&l);

    for(j=1;j<=4;j++){
        for(i=0;i<=2;i++){
            if(a[i][l-1]>a[i+1][l-1]){
            for(k=0;k<=3;i++){
                temp=a[i][k];
                a[i][k]=a[i+1][k];
                a[i+1][k]=temp;
                }
            }
        }
    }

     for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ",a[i][j]);
        }
    printf("\n");
    }
    return 0;
}
