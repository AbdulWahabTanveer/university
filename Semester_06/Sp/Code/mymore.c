#include<stdio.h>
#define LineLength 100
#define PageLength 24

void do_more(char* fname);
int myopen(char* name);

int main(int argc,char* argv){
if(argc==1){
    printf("please enter a parameter");
    return 0;
}
for(int i = 1 ; i < argc; i++){
    do_more(argv[1]);
    printf("Now Showing %s \n\n",argv[i+1]);
}
return 0 ;
}

void do_more(char* fname){
    char* buff[LineLength];
    int linecount=0;
    char choice;
    int fd = myopen(fname);
    while(1){
        if(linecount==PageLength-1){
            scanf("%c",choice);
            if(choice==' '){
                linecount=0;
            }
            else if (choice == '\n'){
                linecount=linecount-1;
            }
            else
                break;
        }
        fgets(fd,buff,LineLength);
        fputs(1,buff);
    }

}
int myopen(char* name){
    int fd;
    if((fd=open(name,'r'))==-1){
        printf("unable to open file");
        return(-1);
    }
    else return fd;
}