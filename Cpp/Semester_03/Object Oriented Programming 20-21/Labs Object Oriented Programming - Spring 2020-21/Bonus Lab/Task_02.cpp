#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<ctime>

using namespace std;

string subtract(string s1,string s2){
    bool match=false;string s;
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[0]){
            match=true;
            for(int i=1;i<s2.size()||s1[i]!='\0';i++)
                if(s1[i]!=s2[i])
                    match=false;
        }
    }
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[0]){
            s1.erase(i,i+s2.size());
        }
    }
    if(match){
        return s1;
    }
    else {
        return s;
    }
}

template<typename T>
T add(T num1,T num2){
    return num1+num2;
}

template<typename T1,typename T2>
T1 sub(T1 num1,T2 num2){
    return num1-num2;
}
template <> 
string add<string>(string s1,string s2) 
{ 
    return s1+s2; 
} 
template <> 
string sub<string,string>(string s1,string s2) 
{ 
    return subtract(s1,s2); 
} 

 

int main(){
    cout<<"\nAdded 2 int "<<add<int>(14,15);
    cout<<"\nAdded 2 float "<<add<float>(14.23,15.66);
    cout<<"\nSubtracted  int float "<<sub<float,int>((float)15.125,5);
    cout<<"\nSubtracted  int int "<<sub<int,int>(15,10);

    cout<<"\n\nAdded 2 strings "<<"\n"<<add<string>("1.This is ","2.A statement");
    cout<<"\nSubtracted 2 strings "<<"\n\n"<<sub<string>("1.This is ","2.A statement This");
    cout<<"\n\n";
    return 0;
}