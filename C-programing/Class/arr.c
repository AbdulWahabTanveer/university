#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int n1,n2,i,a1[10],a2[10],a3[10],a4[10],a5[10],a6[10],a7[10],choice,table,ans;
    int correct=0;
    int incorrect=0,state;
do{
    incorrect=0;
    correct=0;
    printf("1.Single Table\n");
    printf("2.Multiple Table\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice==1)
      {
          printf("Enter Table No: ");
          scanf("%d",&table);
       for (i=0;i<10;i++)
             {
                  n1=rand()%10+1;
                  a7[i]=n1;
                  printf("%d x %d\t=\t", table,n1);
                  scanf("%d", &a5[i]); /*a5[] ans of single table*/
                  a6[i]=table*n1;
              }
       for (i=0;i<10;i++)
           {
             if (a5[i]==a6[i])
              {
                correct++;
              }
             else
              {
                incorrect++;
              }
           }
                                      printf("    \t\t\t\tYour Answer\t\tCorrect Answer\n");
              for(i=0;i<10;i++)
                    {
                       printf("%d x %d\t\t= \t\t\t%d\t\t\t%d\t\t\t \n", table,a7[i],a5[i],a6[i]);}
        printf("Correct Answers: %d\n",correct);
       printf(" Incorrect Answers: %d",incorrect);
    }
    else
      {
                 srand(time(0));
              for(i=0;i<10;i++)
                  {
                     n1=rand()%10+1;
                     n2=rand()%19+2;
                    /*printf("%d \n", n1);
                     printf("%d \n", n2);*/
                     a1[i]=n2*n1;
                   /*printf("%d \n",a1[i]);*/
                     a3[i]=n1;
                     a4[i]=n2;
                     printf("%d x %d\t=\t",n2,n1);
                     scanf("%d",&a2[i]);
                   }
              for(i=0;i<10;i++)
                   {
                     if (a1[i]==a2[i])
                       {
                          correct++;
                       }
                     else
                        {
                          incorrect++;
                       }
                     }
                                 printf("   \t\t\t\tYour Answer\t\tCorrect Answer\n");
              for(i=0;i<10;i++)
                    {
                       printf("%d x %d\t\t= \t\t\t%d\t\t\t%d\t\t\t \n", a4[i],a3[i],a2[i],a1[i]);}

       printf("Correct Answers: %d\n",correct);
       printf("Incorrect Answers: %d",incorrect);
      }
      printf("enter 1 to repeat");
      scanf("%d",&state);
}while (state==1);
return 0;
}
