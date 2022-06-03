#include <stdio.h>

int main(){
    FILE *file;
    file=fopen("output.txt","w");//Opening file for reading
    char ch;
    while ((ch=getchar())!=EOF)//Reading characters from keyboard till Ctrl+d pressed by user
        putc(ch, file);    //Writing character in file
    printf("File created & all the characters written in file\n");
    fclose(file);
    return 0;
}
