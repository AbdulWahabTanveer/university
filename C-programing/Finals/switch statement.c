#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Deleted= -999999
void showMenu(){
    printf("\t\t1. Add New Element\n");
    printf("\t\t2. Delete Existing Element\n");
    printf("\t\t3. Insert New Element\n");
    printf("\t\t4. Modify Existing Element\n");
    printf("\t\t5. Print Array Elements\n");
    printf("\t\t6. Terminate Program\n");
    printf("\t\tEnter Choice:");
}

int main(){
    int choice,i,count=0,value,index;
    do{
        showMenu();
        scanf("%d",&choice);
        int count,x[100];
        switch(choice){
            case 1:
                printf ("\t\tAdd Element At The End:");
                scanf("%d",&x[count]);
                count++;
                break;
            case 2:
                printf ("\t\tDelete Existing Element:");

                break;
            case 3:
                printf ("\t\tInsert New Element:");
                scanf("%d",&value);
                scanf("%d",&index);
                for(i=count;i>index-1;i--){
                x[i]=x[i-1];
                }
                x[index-1]=value;
                count++;
                break;
            case 4:
                printf ("\t\tModify Existing Element:");
                break;
            case 5:
                printf ("\t\tPrint Array Elements\n");
                for(i=0;i<count;i++){
                    printf("%d\n",x[i]);}
                break;
            case 6:
                printf ("\t\tTerminating Program\n");
                break;
            default:
                printf ("\t\tInvalid Option\n");
        }
    }while (choice!=6);
    return 0;
}
