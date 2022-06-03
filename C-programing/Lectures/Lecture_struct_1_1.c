#include <stdio.h>


int main(){
    struct Point{
        int x;
        int y;
    };
    struct Point p1;
    struct Point p2;
    p1.x=5;
    p1.y=8;
    printf("\tPoint 1: X=%d , Y=%d\n", p1.x, p1.y);
    p2.x=7;
    p2.y=4;
    printf("\n\tPoint 2: X=%d , Y=%d\n", p2.x, p2.y);
    return 0;
}
