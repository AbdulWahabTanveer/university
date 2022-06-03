#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

string* Read_line(int &count){
    ifstream file;
    file.open("data.txt",ios::in);
    
    count=0;

    string line[100];
    while (getline(file, line[count++]))
    {
        // note that the newline character is not included
        // in the getline() function
        cout << line[count-1] << endl;//'\n'
    }
    file.close();
    
    return line;
}
char* Asm(){
    int i;//1 11 1 ccccccc ddd jjj
    for(asdasdas)
    if(c[i]==' ')
        break;
    if(c[i]=='@'){
        c[i+1];       //    M   =   M+1   ;   JMP
    }
    else {//c instruction    control unit char[16]}
    return "as";
}

int main(){
    string *c;   //1 4-byte
    int count;
    c=Read_line(count);


}