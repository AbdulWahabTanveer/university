#include <stdio.h>

void print(int a[], const int SIZE){
    for (int i=0;i<SIZE;i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main(){
    int m[3][2]={{2,6},{3,1},{4,5}};
    print (m, 6);
    print (m[0], 2);
    print (m[1], 2);
    print (m[2], 2);
    printf("\n");
    print (m[0], 6);
    printf("\n");
    return 0;
}
