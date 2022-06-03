#include<stdio.h>
int main(){

    char name[50],first[50],second[50];
    int i,j,temp;

    printf("\n\nPlease Enter Your First Name:");
    gets(first);
    printf("\n\nPlease Enter Your Second Name:");
    gets(second);

    for(i=0;first[i]!=0;i++){
        name[i]=first[i];
    }
    name[i++]=' ';
    for(j=0;second[j]!=0;j++){
        name[i++]=second[j];
    }
    name[i++]=0;
    printf("\n\nYour Full Name is: %s",name);
    return 0;
}

