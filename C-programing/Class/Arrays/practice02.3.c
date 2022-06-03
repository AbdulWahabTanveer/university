#include <stdio.h>
#include <stdlib.h>
int main()
{   int a[100],i,g1=0,g2=0,g3=0,g4=0;
    float s1=0,s2=0,s3=0,s4=0,sum=0,avg=0,var=0,x=0;
    float d1=0,d2=0,d3=0,d4=0;
    for(i=0;i<100;i++){
        a[i]=100+(rand()%401);
    }
    for(i=0;i<100;i++){
       if(a[i]<200)
       {g1++;
        s1=s1+a[i];}
       else if(a[i]<300)
       {g2++;
       s2=s2+a[i];}
       else if(a[i]<400)
       {g3++;
       s3=s3+a[i];}
       else if(a[i]<500)
       {g4++;
       s4=s4+a[i];}
 }

        printf("\x1b[34m Group        Count        T_count\n");
        printf("\x1b[32m  1             %d             %d\n",g1,g1);
        printf("\x1b[33m  2             %d             %d\n",g2,g1+g2);
        printf("\x1b[35m  3             %d             %d\n",g3,g1+g2+g3);
        printf("\x1b[31m  4             %d             %d\n",g4,g1+g2+g3+g4);

        printf("\x1b[36mGroup        Average     \n");
        printf("\x1b[0m  1             %.3f      \n",s1/g1);
        printf("  2             %.3f             \n",s2/g2);
        printf("  3             %.3f             \n",s3/g3);
        printf("  4             %.3f             \n",s4/g4);

        for(i=0;i<100;i++){
       if(a[i]<200)
       {d1=d1+(a[i]-(s1/g1));}
       else if(a[i]<300)
       {g2++;
       d2=d2+(a[i]-(s2/g2));}
       else if(a[i]<400)
       {g3++;
       d3=d3+(a[i]-(s3/g3));}
       else if(a[i]<500)
       {g4++;
       d4=d4+(a[i]-(s4/g4));}
 }

        printf("\n\x1b[0mTotal Variance: %f\n",var);

        printf("\n\x1b[36mGroup        variance     \n");
        printf("\x1b[0m  1             %.3f      \n",d1/g1);
        printf("  2             %.3f             \n",d2/g2);
        printf("  3             %.3f             \n",d3/g3);
        printf("  4             %.3f             \n",d4/g4);

    return 0;
}
