#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include "Line_Assembler.cpp"
#define Input_file "data.asm"
#define Output_file "MachineCode.hack"

using namespace std;

int number_of_lines(){
    ifstream file;
    file.open(Input_file,ios::in);
    
    int count=0;
    string l;
    
    while (getline(file,l)){count++;}
    
    file.close();
    return count;
}
string* Read(int total_count){
    ifstream file;
    file.open(Input_file,ios::in);
    
    int count=0;

    string *line;
    line=new string[total_count];
    while (getline(file, line[count++])){}
    file.close();
    count--;
    return line;
}


int main(){
    string *c,output,**symbol_tab=create_symbol_tab();   //1 4-byte
    int count;bool Error,empty_line,symbol_check;
    count=number_of_lines();
    c=Read(count+1);
    
    ofstream file(Output_file,ios::out);

    for(int i=0;i<count;i++){ 
        remove_comments(c[i],Error,empty_line);
        if(Error)   {cout<<"\nError at Line Number "<<i+1<<"\nProgram Execution Terminated\nReturned -1\n\n";return -1;}
            //if removing comments encountered errors end the function

        remove_spaces(c[i]);
            //Removing all spaces
        Symbol_pass(c[i],symbol_tab);

        if(!(empty_line || c[i].empty())) instruction_number++;
    }/*  
    for(int i=0;i<count;i++){
    //    for(int j=0;j<c[i].size();j++)
                
        //cout<<c[0];   
        output=Line_Assembler(c[i],Error,empty_line,symbol_check,symbol);
        if(Error)   {cout<<"\nError at Line Number "<<i+1<<"\nProgram Execution Terminated\nReturned -1\n\n";return -1;}
            else if(empty_line)     continue;
                else file<<output<<"\n";
    }*/

    cout<<"Machine Code Generated Successfully\n\n";
    return 0;
    //cout<<"\ncount: "<<count;
    
}