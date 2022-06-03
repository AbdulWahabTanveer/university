#include<iostream>
#include<string.h>
#include<iomanip>
#include<fstream>
#include"Store.cpp"

using namespace std;


void FileWrite(const Store &S){
    ofstream out("input.bin",ios::out|ios::binary);
    out.seekp(0);
    char a[50];strcpy(a,"Islamia Pharmacy");
    out.write(S.store_name,sizeof(char)*50);

    out.write((char*)&S.count,sizeof(int));


    for(int i=0;i<S.count;i++){
        out.write((char*)&S.m[i],sizeof(Medicine));
        }
    out.close();
}

Store FileRead(){
    
    ifstream in("input.bin",ios::in|ios::binary);
    in.seekg(0);
    
    char a[50];int count;Medicine *m;

    in.read(a,sizeof(char)*50);
    in.read((char*)&count,sizeof(int));
    m=new Medicine[50];
    in.read((char*)m,sizeof(Medicine)*50);

Store S(count,a);
    S.m=m;
    in.close();
    return S;
}
