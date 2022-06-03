#include<stdio.h>
#include<time.h>

struct GPA{
float    PF;
float    LA;
float    BE;
float    DLD;
float    CAL2;
};

struct Hassan{
float Height;
int salary;
struct GPA cGPA;
}h1;



int main(){
int i;

srand(time(0));

h1.Height=5.10;
h1.salary=50000;
printf("\n\nHeight of Hassan is %.2f\n",h1.Height);
printf("Salary of Hassan is %d\n",h1.salary);

h1.cGPA.PF=3.7;
h1.cGPA.LA=4;
h1.cGPA.BE=4;
h1.cGPA.DLD=3.7;
h1.cGPA.CAL2=3.7;
printf("\n\nPF GPA of Hassan is %.2f\n",h1.cGPA.PF);
printf("LA GPA of Hassan is %.0f\n",h1.cGPA.LA);
printf("BE GPA of Hassan is %.0f\n",h1.cGPA.BE);
printf("DLD GPA of Hassan is %.2f\n",h1.cGPA.DLD);
printf("CAL2 GPA of Hassan is %.2f\n",h1.cGPA.CAL2);
return 0;
}
