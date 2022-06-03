#include <stdio.h>
void prin(int a[]);
int main(){
int i, count=0;
printf("\n\n");//just to leave some space will printing the rest
int x[10]={23, 10, 20, 40, 50, 29, 35, 42, 26, 38};
float avg=0;
prin(x);
for (i=0;i<10;i++){
avg=avg+(x[i]-avg)/(i+1);
}
printf("\nAverage:%.2f\n", avg);
for (i=0;i<10;i++)
if (x[i]<avg)
count++;//I haven't used a block so the loop will only work
//on the count statement and the print statement will only
//run once
printf("%d elements are smaller than average.\n", count);
return 0;
 }
//here is the function that i have defined for printing of array
//You can use functions to apply any task on array
void prin(int a[]){
int i;
for (i=0;i<9;i++){
printf("\x1b[36m%d\n",a[i]);
}}
