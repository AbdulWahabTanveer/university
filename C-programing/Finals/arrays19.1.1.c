#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    #define SIZE 50
    int x[SIZE], minIndex, temp, i, j;
    srand(time(0));//set new seed

    //Initialize & print array values
    for(i=0;i<SIZE;i++){
        x[i] = 100 + rand()%400; //random value between 100 to 500
        printf("%d ", x[i]);
    }
    printf("\n\n");
    //selection sort
    for(i=0;i<SIZE-1;i++){
        //Find position of smallest element starting from ith position to last position
        minIndex=i;//let us say that i is the smallest element
        for (j=i+1;j<SIZE;j++)//Compare ith value with other values
            if (x[j]<x[minIndex])
                minIndex=j;
        //swap ith element with smallest element [Smallest element ith position to last position]
        if (i!=minIndex){   //Don't swap, if i is the smallest element
            temp=x[minIndex];
            x[minIndex]=x[i];
            x[i]=temp;
        }
    }
    for(i=0;i<SIZE;i++)
        printf("%d ", x[i]);
    printf("\n");
    return 0;
