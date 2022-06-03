#include <stdio.h>

#define COLUMNSIZE 4
#define ROWSIZE 4
#define SIZE ROWSIZE*COLUMNSIZE

void initBoard(char b[]);
void printBoard(char b[]);
void inputAndPlace(char b[], int playerNo);
int checkWin(char b[]);

int main(){
    char board[SIZE];
    initBoard(board);
    int countCells=0, playerNo=1;
    printBoard(board);
    do{
        inputAndPlace(board, playerNo);
        printBoard(board);
        if (checkWin(board))		break;
        if (playerNo==1)		playerNo=2;
        else					playerNo=1;
        countCells++;
    }while (countCells<9);
    if (countCells==9)		printf("\n\n\tGame Draw!\n\n");
    else					printf("\n\n\tPlayer %d Won the Game!\n\n",playerNo);
    return 0;
}
void initBoard(char b[]){
    for (int i=0;i<SIZE;i++)
        b[i]='-';
}
void printBoard(char b[]){
    for (int i=0;i<SIZE;i++){
        printf(" %c ",b[i]);
        if ((i+1)%COLUMNSIZE==0)
            printf("\n");
    }
}
void inputAndPlace(char b[], int playerNo){
    int cellNo, continueFlag=1;
    do{
        printf("Player %d: Enter Some Empty Cell #:", playerNo);
        scanf("%d", &cellNo);
        if (cellNo<1 || cellNo>SIZE)
            printf("Wrong input, give cell no in range\n");
        else if (b[cellNo-1]!='-')
            printf("Select empty cell!\n");
        else
            continueFlag=0;
    }while (continueFlag==1);
    if (playerNo==1)		b[cellNo-1]='A';
    else					b[cellNo-1]='B';
}
//hardcode for board of 3x3
int checkWin(char b[]){
    int i, row, col;
    //check all rows
    for (row=0;row<ROWSIZE;row++){
        for (i=row*COLUMNSIZE+1;i<row*COLUMNSIZE+COLUMNSIZE;i++)
            if (b[row*COLUMNSIZE]!=b[i])	break;
        if (i==row*COLUMNSIZE+COLUMNSIZE && b[row*COLUMNSIZE]!='-')  return 1;
    }
    //check all columns
    for (col=0;col<COLUMNSIZE;col++){
        for (i=col;i<SIZE;i+=COLUMNSIZE)
            if (b[col]!=b[i])	break;
        if (i>=SIZE && b[col]!='-')  return 1;
    }
    for (i=0;i<SIZE;i+=COLUMNSIZE+1)
        if (b[0]!=b[i])	break;
    if (i>=SIZE && b[0]!='-')  return 1;
    //check second diagonal
    for (i=COLUMNSIZE-1;i<(SIZE-COLUMNSIZE+1);i+=(COLUMNSIZE-1))
        if (b[COLUMNSIZE-1]!=b[i])	break;
    if (i>=(SIZE-COLUMNSIZE+1) && b[COLUMNSIZE-1]!='-')  return 1;
    return 0;
}
