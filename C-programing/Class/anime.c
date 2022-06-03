#include <stdio.h>
// To use time library of C
#include <time.h>

void delay(int t){
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + t);
}
int main(){
    int x, y;
    printf("\033[2J");//clear screen
    //Move PUCIT from two directions
    for (y=6,x=12;y<=22;y++,x=x+3){
        printf("\033[%d;%dH\033[PUCIT\n",y,x);
        printf("\033[%d;%dH\033[PUCIT\n",y,130-x);
        delay(100000);//modify this number to increase / decrease speed
        printf("\033[%d;%dH     \n",y,x);
        printf("\033[%d;%dH     \n",y,130-x);
    }
    printf("\n\033[0m");
    return 0;
}
