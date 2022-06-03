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
    //Animate PUCIT New Campus
    for (y=10;y<20;y++)
        for (x=12;x<=65;x=x+2){
            printf("\033[%d;%dH\033[; PUCIT\n",y,x);
            printf("\033[%d;%dH\033[; New Campus\n",y,130-x);
            delay(50000);//modify this number to increase / decrease speed
            printf("\033[%d;%dH     \n",y,x);
            printf("\033[%d;%dH          \n",y,130-x);
        }
    printf("\033[15;50H\033[5;31mPUCIT\n");
    printf("\033[15;60H\033[5;32mNew Campus\n");
    printf("\n\033[0m");
    return 0;
}
