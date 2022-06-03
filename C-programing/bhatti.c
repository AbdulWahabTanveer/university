#include<stdio.h>
#include<stdlib.h>
#include<time.h>







int main(){
srand(time(0));
int n, stn, i,j,q, a,temp,count=0,t ;
int x[10],y[10],z[10];
do{
    printf("1. Single Table\n");
    printf("2. Multiple Table\n");

    printf("Enter Your Choice:");
    scanf("%d",&n);


if(n==1){

         printf("Enter Your Table(2-8) :");
         scanf("%d",&stn);



    //Taking unique random values
    for(q=0;q<10;q++){
            z[q] =  rand()%10+1; //random value between 1 to 10

        //Check if this value already exist on left side of current index
        
            for (j=q-1;j>=0;j--)
                   if (z[j]==z[q])
                          q--;//repeat for same index, if value already exist
    }
 
         
         
         for(i=0;i<10;i++){

            
                            printf("%d X %d\t = ",stn,z[i]);
                            scanf("%d",&  x[i]);
                             y[i] = stn *z[i];
                          
                            
                               
         }
  
printf("\n\n");
printf("\t\t\t   Answer\t\tYour Answer\n");

        for(int j=0;j<10;j++){
                              printf("\t\t%d X %d\t = %d\t\t\t%d\n",stn,z[j],y[j],x[j]);
       
        }

        for(int k=0;k<10;k++){
                              if(x[k]==y[k])
                                             count++;                           
        }

printf("Correct Answer :%d\n",count);
printf("Incorrect Answer :%d\n",(10-count));                                     

}

 
if(n==2){
       
    int n1 ,n2;
    int m[10],n[10],o[10];




    printf("Enter Starting Table\nEnter Your Table Number(2-10):");
    scanf("%d",&n1);

    printf("Enter Ending Table Number\nnter Your Table Number(2-10):");
    scanf("%d",&n2);
    

for(int l=0;l<10;l++){
                      m[l] = 2 + rand()%(n2-1);
                      n[l] = 1 + rand()%10 ;
                      printf("%d X %d = ",m[l], n[l]);
                      scanf("%d",&o[l]);
                        
}



printf("\n\n");
printf("\t\t\t   Answer\t\tYour Answer\n");


        for(int j=0;j<10;j++)
                              printf("\t\t%d X %d\t = %d\t\t\t%d\n",m[j],n[j],(m[j]*n[j]),o[j]);
       
       
         for(int k=0;k<10;k++){
                              if(o[k]==(m[k]*n[k]))
                                             count++;                           
        }



     printf("Correct Answer :%d\n",count);
     printf("Incorrect Answer :%d\n",(10-count));                                     



}


    printf("Enter do you want to repeat, Press 1 to repeat:");
    scanf("%d",&t);
}
while(t==1);
    printf("Thanks for using the program.\n");

return 0;
}