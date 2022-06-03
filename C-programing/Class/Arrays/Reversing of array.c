#include<stdio.h>
void pa(int a[],int n);
int main(){
int a[5]={2,3,4,5,6},i,temp,n;
n=5;
//type name[size]
//pa takes (array,size of array) prints
pa(a,n);
printf("\n");//5
//here n shows total number of elements in array
//temp is used for swapping "temporary"
//when the size is odd one element will not be swapped
//for example 1 2 3 4 5,reverse 5 4 (3) 2 1
// here 3 did not moved
for(i=0;i<n/2;i++){
    temp=a[n-1-i];//0 first value max last value
    a[n-1-i]=a[i];
    a[i]=temp;
}
pa(a,n);
return 0;
}
//type name(array,size)
void pa(int abcd[],int n){
int i;
for(i=0;i<n;i++){
    printf("%d ",abcd[i]);}}
