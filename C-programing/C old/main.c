#include<stdio.h>
int main()
{int max,num,itr,a;
max = 0;
scanf("%d",&num);
itr=1;
p:
scanf("%d",&a);
if(max<=a)
    max=a;
itr++;
if(itr<=num)
    goto p;
printf("%d",max);
return 0;
}
