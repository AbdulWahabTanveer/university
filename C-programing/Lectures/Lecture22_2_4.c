#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITEMCOUNT 6
#define QUARTERS 4

void initByZero(int x[], const int SIZE){
	for (int i=0;i<SIZE;i++)
		x[i]=0;
}

int main(){
    srand(time(0));
    //Array qty represents sales of 6 items in 4 quarters of a year
    int qty[ITEMCOUNT][QUARTERS], i , j, total, total_quarters[QUARTERS], total_items[ITEMCOUNT];
    initByZero(total_quarters, QUARTERS);
    initByZero(total_items, ITEMCOUNT);    
    //code to initialize and print quantities
    printf ("\n\t\t  I\t  II\t  III\t  IV\n");
    for (i=0;i<ITEMCOUNT;i++){
	total=0;
        printf("\tItem %d\t", i+1);
        for (j=0;j<QUARTERS;j++){
            qty[i][j]=rand()%20+30;
            printf("  %d\t", qty[i][j]);
	    total+=qty[i][j];
	    total_quarters[j]+=qty[i][j];//Adding to relevant total of column
        }
        printf("\t%d\n", total);
    }
    //printing column totals
    printf("\t\t");
    for (i=0;i<QUARTERS;i++)
	printf(" %d\t", total_quarters[i]);
    printf("\n\n");
    //code to print item in columns & quarters in rows
    printf ("\n\t\t\tItem 1\tItem 2\tItem 3\tItem 4\tItem 5\tItem 6\n");
    for (i=0;i<QUARTERS;i++){
	total=0;
        printf("\tQuarter %d\t", i+1);
        for (j=0;j<ITEMCOUNT;j++){
            printf("  %d\t", qty[j][i]);
	    total+=qty[j][i];
	    total_items[j]+=qty[j][i];
	}
        printf("\t%d\n",total);
    }
    //Printing column totals	
    printf("\t\t\t");
    for (i=0;i<ITEMCOUNT;i++)
	printf(" %d\t",total_items[i]);
    printf("\n\n");
    return 0;
}
