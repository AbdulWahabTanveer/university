#include<stdio.h>
int main(){

    char name[50];
    printf("\n\nPlease Enter Your Full Name:");
    gets(name);
    printf("\nHi! %s. Good to See you back.",name);
    printf("\nLength of String is %d",stringlength(name));
    return 0;
}

int stringlength(char string[]){
    int length=0;
    for(;string[length]!=0;length++);
    return length;

}
