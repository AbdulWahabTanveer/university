#include <stdio.h>

void print(int a[], const int SIZE){
    for (int i=0;i<SIZE;i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main(){
    int m[3][2]={{2,6},{3,1},{4,5}},*p;

    print (m, 6);
    p=m;
    print (p, 2);
    print (p+2, 2);
    print (p+4, 2);
    printf("\n");
    print (m[0], 6);
    printf("\n");

    int x=45;

    printf("\n\nValue of X is:");
    print(&x,1);
    return 0;
}
