#include <stdio.h>
#include <stdlib.h>
int main()
{   int a[100],i,g1=0,g2=0,g3=0,g4=0;
    /*core concept
      variables
      control structures
      (
            Sequence
            selection
            loop
      )
      data structures etc
    */
    for(i=0;i<100;i++){
        a[i]=100+(rand()%399);
    }
    for(i=0;i<100;i++){
       if(a[i]<200)
       g1++;
       else if(a[i]<300)
       g2++;
       else if(a[i]<400)
       g3++;
       else if(a[i]<500)
       g4++;
 }
    printf("Group        Count        T_count\n");
    printf("1             %d             %d\n",g1,g1);
    printf("2             %d             %d\n",g2,g1+g2);
    printf("3             %d             %d\n",g3,g1+g2+g3);
    printf("4             %d             %d\n",g4,g1+g2+g3+g4);
    return 0;
}
