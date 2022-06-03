#include <stdio.h>
int main()
{
    int i;
    printf("Enter The length of Array\n");
    int a[10];
    for(i=0;i<10;i++){
        printf("Enter %d Number\n",i+1);
        scanf("%d",&a[i]);
        }
    for(i=0;i<10;i++){
        printf("\n%d Number is = %d",i+1,a[i]);
        }
    return 0;
}

