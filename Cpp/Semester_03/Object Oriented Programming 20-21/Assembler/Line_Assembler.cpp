#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

void remove_comments(string &s,bool &Error,bool &Empty_line){
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='/')
            if(s[i+1]=='/'){
                if(i==0){Empty_line=true;goto End;}
                s=s.substr(0,i);//index char size   12345   //asdasdasdasd
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
        if (s[i] == ' '||s[i] == '\t')//For spaces does nothing 
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
    for(int i=1;i<s.size()||s[i]!='\0';i++){
        check=s[i]-'0';
        if(check>=0&&check<=9)
            continue;
        else    Error=true;
    }
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
    
    remove_comments(s,Error,Empty_line);
    if(Error)   goto C_End;
    //if removing comments encountered errors end the function

    remove_spaces(s);
    //Removing all spaces

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