#include<stdio.h>
#include<stdlib.h>
#define LineLength 100
#define PageLength 24

/*Not the exact copy as my paper code but almost it*/

void do_more(char* fname);
FILE* myopen(char* name);

int main(int argc,char* argv[]){
if(argc==1){
    printf("please enter a parameter");
    return 0;
}
for(int i = 1 ; i < argc; i++){
printf("%s",argv[i]);
    do_more(argv[i]);
    if(i+1<argc)
    printf("Now Showing %s \n\n",argv[i+1]);
}
return 0 ;
}

void do_more(char* fname){
    int linecount=0;
    char choice;
    FILE* fd= myopen(fname);
    char buff[LineLength];
    while(1){
        if(linecount==PageLength-1){
   printf("\n\033[7m --more--(%%) \033[m");
            scanf("%c",&choice);
            if(choice==' '){
                linecount=0;
            }
            else if (choice == '\n'){
                linecount=linecount-1;
            }
            else
                break;
        }
        linecount++;
        
        if(fgets(buff,LineLength,fd))
       	fputs(buff,stdout);
       	else
       	   break;
    }

}

/*Had to change a few things here for it to work*/
/*Because in paper i thought fgets uses file descritper not file pointer*/

FILE* myopen(char* name){
    FILE* fd;
    if((fd=fopen(name,"r"))== NULL){
        printf("unable to open file");
        exit(-1);
    }
    else return fd;
}


