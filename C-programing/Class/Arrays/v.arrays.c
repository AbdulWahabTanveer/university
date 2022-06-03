#include <stdio.h>
int main()
{
    int n,i;
    printf("Enter The length of Array\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("Enter %d Number\n",i+1);
        scanf("%d",&a[i]);
        }
    for(i=0;i<n;i++){
        printf("\n%d Number is = %d",i+1,a[i]);
        }
    return 0;
}

