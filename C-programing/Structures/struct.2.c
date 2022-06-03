#include<stdio.h>
#include<time.h>

struct Hassan{
int employee;
float Height;
int salary;
char performance;
};

int main(){
int i;
struct Hassan h1;

srand(time(0));

h1.Height=5.10;
h1.salary=50000;
h1.marks[0]=12312;
printf("\n\nHeight of Hassan is %.2f\n",h1.Height);
printf("Salary of Hassan is %d\n",h1.salary);
printf("marks of Hassan is %d\n",h1.marks[0]);

return 0;
}

