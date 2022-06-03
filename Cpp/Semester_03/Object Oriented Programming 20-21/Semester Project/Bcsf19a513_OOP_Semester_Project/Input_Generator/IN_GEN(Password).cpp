#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>

using namespace std;
int main(){

    char a[25]="Abdul Mateen",b[10]="arslan";int i;
    ofstream out("Id.bin",ios::out|ios::binary);
    out.write((char*)a,sizeof(char)*25);
    out.write((char*)b,sizeof(char)*10);
    out.close();
 cout<<"\n\n";

    ifstream in("Id.bin",ios::in|ios::binary);
    //seekg(0,ios::beg);
    in.read(a,sizeof(char)*25);
    in.read(b,sizeof(char)*10);
    cout<<a<<' ';
    cout<<b;
    
}
