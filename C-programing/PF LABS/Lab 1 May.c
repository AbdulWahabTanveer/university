/*Special Sort*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,i,j,temp;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(j=1;j<=n;j++){
        
        for(i=0;i<n-1;i++){
               if(a[i]>a[i+2] && (i%2==0 ||i==0)){
            temp=a[i];
            a[i]=a[i+2];
            a[i+2]=temp;}

               if(a[i]<a[i+2] && i%2!=0){
            temp=a[i];
            a[i]=a[i+2];
            a[i+2]=temp;}
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
