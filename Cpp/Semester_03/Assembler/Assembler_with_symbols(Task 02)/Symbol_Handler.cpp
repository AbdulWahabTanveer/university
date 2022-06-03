#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#define Input_file "data.asm"
#define Output_file "MachineCode.hack"

using namespace std;
static int symbol_count=23;
static int symbol_val=16;
static int instruction_number=1;

string** create_symbol_tab(){
    string **temp=new string*[2];
    for(int i=0;i<2;i++)
        temp[i]=new string[23];
    
    string temporary[2][23]={"R0","R1","R2","R3","R4","R5","R6","R7","R8","R9","R10","R11","R12","R13","R14","R15","SP","LCL","ARG","THIS","THAT","SCREEN","KBD"
                            ,"0" ,"1" ,"2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10" ,"11" ,"12" ,"13" ,"14" ,"15" ,"0" ,"1"  ,"2"  ,"3"   ,"4"   ,"16384" ,"24576"};
    for(int i=0;i<2;i++)
        for(int j=0;j<23;j++)
            temp[i][j]=temporary[i][j];
    
    return temp;
}
string append_symbol_tab(string** &tab,string symbol,bool label){
    string **temp=new string*[2];
    for(int i=0;i<2;i++)
        temp[i]=new string[symbol_count+1];
    temp[0][symbol_count]=symbol;
    
    if(!label)
    temp[1][symbol_count]=to_string(symbol_val++);
    else
    temp[1][symbol_count]=to_string(instruction_number);// End:

symbol_count+=1;
    delete[] tab;
    tab =temp;

    return temp[1][symbol_count-1];
    
}
string  search_append(string symbol_check,string** &symbol_table,bool label){
    bool check;
    int i;

    for(i=0;i<symbol_count;i++) 
        if(symbol_check.compare(symbol_table[0][i])==0)
            return symbol_table[1][i];
    return append_symbol_tab(symbol_table,symbol_check,label);
}


void Symbol_pass(string &s,string** &symbol_table){
    int i;
    
    if(s[0]=='@'){
        if(int(s[1]-'0')>9||int(s[1]-'0')<0){
            s="@"+search_append(s.substr(1,s.size()-1),symbol_table,false);// 12345:
        }
    }
}
void label_pass(string &s,string** &symbol_table,bool &label){
    int i;
        for(i=0;i<s.size()||s[i]!='\0';i++){
            if(s[i]==':'){
                append_symbol_tab(symbol_table,s.substr(0,i),true);// 012345:
                s="";
                label=true;
            }
        }
}
/*
int main(){
    string **temp;
    temp=create_symbol_tab();
    for(int i=0;i<2;i++)
        for(int j=0;j<23;j++)
            cout<<"\nthis is: "<<temp[i][j];
}*/



void remove_comments(string &s,bool &Error,bool &Empty_line){
    Error=false;Empty_line=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='/')
            if(s[i+1]=='/'){
                if(i==0){Empty_line=true;goto End;}
                s=s.substr(0,i);
                break;
            }
        //This loops checks if there is a '/'
        //If yes it makes sure that it is follwed my another '\'
        //And then cuts everything out after the "//"
        
        else{
            cout<<s<<'\n';
            for(int j=0;j<i;j++)
                cout<<' ';
            cout<<"^----Stray '/' Error\n";
            Error=true;
            break;
        }
        //If '/' is not followed my another '/'
        //Gives stray '/' error
    }
    End:
    if(Error||Empty_line)
        s="";
    //In case of errors return Empty string
}
void remove_spaces(string &s){
    string str;
    int count = 0; 
  
    for (int i = 0;s.size(); i++){
        if(s[i]=='\0') break;//If we have reached the end breaks stops
        if (s[i] == ' ')//For spaces does nothing 
            continue;    
        str.insert(count++,1,s[i]);//Adds non-space character to a new string
    } 

    str[count] = '\0';

    s=str;//stores new string in s
}

void a_function(string &s,bool &Error){
    int i,val,count,check;string bin="";

    stringstream str(s.substr(1,s.size()-1));    //4 9
    str>>val;
    
    count=0;s="";
    /*for(int i=1;i<s.size()||s[i]!='\0';i++){
        check=s[i]-'0';
        if(check>=0&&check<=9)
            continue;
        else    Error=true;
    }*/
    if(Error)  goto End;
    while(val>0){
        count++;
        bin += to_string(val%2);
        val=val/2;
    }

    for(i=count-1;i>=0;i--){
        s+=bin[i];
    }
    End:
    s.insert(0,16-s.size(),'0');
}

string c_Compute(string c_instruction,string &a){
    a.insert(0,1,'0');
    string temp="";
    string s[2][18]={"0"     ,"1"      ,"-1"   ,"D"     ,"A"     ,"!D"    ,"!A"    ,"-D"    ,"-A"    ,"D+1"   ,"A+1"   ,"D-1"   ,"A-1"   ,"D+A"   ,"D-A"   ,"A-D"   ,"D&A"   ,"D|A"
                    ,"101010","111111","111010","001100","110000","001101","110001","001111","110011","011111","110111","001110","110010","000010","010011","000111","000000","010101"};
    
    
    for(int j=0;j<c_instruction.size();j++){
        if(c_instruction[j]=='M'){
            c_instruction[j]='A';
            a[0]='1';    
        }
    }
    for(int i=0;i<18;i++){ 
        if(c_instruction.compare(s[0][i])==0){
            temp = s[1][i];
            return temp;}
            }
    return "$";
    //Return $ to show an error
}
string c_Destination(string c_instruction){
    string s[2][8]={"null","M"  ,"D"  ,"MD" ,"A"  ,"AM" ,"AD" ,"AMD"
                    ,"000","001","010","011","100","101","110","111"};
    
    for(int i=0;i<8;i++) 
        if(c_instruction.compare(s[0][i])==0)
            return s[1][i];
    return "000";
}
string c_Jump(string c_instruction){
    string s[2][8]={"null","JGT","JEQ","JGE","JLT","JNE","JLE","JMP"
                    ,"000","001","010","011","100","101","110","111"};

    for(int i=0;i<8;i++) 
        if(c_instruction.compare(s[0][i])==0)
            return s[1][i];
    return "000";
}
void c_function(string &s,bool &Error){
    int i,j,count=0;
    string s1="",s2="",s3="",a;

    for(i=0;i<s.size();i++){
        if(s[i]=='='||s[i]=='\0')
            break;
        }
    
    for(j=0;j<s.size();j++)
        if(s[j]==';'||s[j]=='\0')
            break;

    if(s[i]=='\0')  s1="000";
    else s1=c_Destination(s.substr(0,i));
    
    if(s[i]=='\0' && s[j]=='\0')    s2=c_Compute(s,a);
        else if(s[i]!='\0')  s2=c_Compute(s.substr(i+1,j-(i+1)),a);// 10  7 
            else  s2=c_Compute(s.substr(0,j),a);// 3 
    
    if(s[j]!='\0')
        s3=c_Jump(s.substr(j+1,3));
    else s3="000";
    s1[3]='\0';s2[8]='\0';s3[3]='\0';a[1]='\0';
    if(s2[0]=='$')    Error=true;
    s="";
    s="111"+a+s2+s1+s3;

}


string Line_Assembler(string s,bool &Error,bool &Empty_line){
    string str=s;
    bool ok=false;
    Error=false;Empty_line=false;

    //Symbol_pass(s,symbol,label);

        if(s.empty()){
            Empty_line=true;
            goto End;
        }
        //Check if the line was a comment or empty line to skip it

        if(s[0]=='@'){
            ok=true;
            a_function(s,Error);
            goto End;
        }
        //if the first character is @ pass it to a_function
        c_function(s,Error);
              ok=true;
        /*else{ 
            for(int i=0;i<s.size();i++){
                if(s[i]=='\0') break;
                if(s[i]=='='||s[i]==';'||!s.empty()){ 
                    c_function(s);
                    ok=true;
                    break;    
                }
            }
        }*/
        //if its a non empty line pass it to c

    
    
    End:
    
    if(Error) {cout<<str<<"\n^-------This is not a Valid Assembly instruction\n";Error=true;}

    C_End:

    return s;

}    

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
    int count;bool Error,empty_line,label;
    count=number_of_lines();
    c=Read(count+5);
    
    ofstream file(Output_file,ios::out);
   // for(int i=0;i<count;i++)
   //     cout<<"\n line is :"<<c[i]<<'\n';

    for(int i=0;i<count;i++){ 
        remove_comments(c[i],Error,empty_line);
        if(Error)   {cout<<"\nError at Line Number "<<i+1<<"\nProgram Execution Terminated\nReturned -1\n\n";return -1;}
            //if removing comments encountered errors end the function

        remove_spaces(c[i]);
            //Removing all spaces
        label_pass(c[i],symbol_tab,label);

        if(!(empty_line || c[i].empty() || label)) instruction_number++;
    }  
   // for(int i=0;i<count;i++)
   ////     cout<<"\n line is :"<<c[i]<<'\n';
    for(int i=0;i<count;i++){ 
        
        Symbol_pass(c[i],symbol_tab);

        if(!(empty_line || c[i].empty())) instruction_number++;
    }
    ////for(int i=0;i<count;i++)
    //    cout<<"\n line is :"<<c[i]<<'\n';
    for(int i=0;i<count;i++){
    //    for(int j=0;j<c[i].size();j++)
                
        //cout<<c[0];   
        output=Line_Assembler(c[i],Error,empty_line);
        if(Error)   {cout<<"\nError at Line Number "<<i+1<<"\nProgram Execution Terminated\nReturned -1\n\n";return -1;}
            //else if(empty_line)     continue;
                else file<<output<<"\n";
        cout<<"\n line is :"<<output<<'\n';
        
    }

    cout<<"Machine Code Generated Successfully\n\n";
    return 0;
    //cout<<"\ncount: "<<count;
    
}