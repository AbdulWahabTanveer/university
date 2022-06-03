#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include"ProductionWorker.cpp"
using namespace std;

int main(){

cout<<"File Handled Priting 5 records\n\n";

    //File Handled Priting 5 records
    ProductionWorker *p;
    p=new ProductionWorker[5];
    ifstream file("input_lab.bin",ios::binary|ios::in);
    file.read((char*)p,sizeof(ProductionWorker)*5);

    for(int i=0;i<5;i++)
    cout<<p[i];

cout<<"Parameterize Contructor\n\n";

    //Parameterize Contructor
    ProductionWorker p1(6262.123,2,456,12,3,2045);
    cout<<p1;

cout<<"Setter One\n\n";

    //Setter
    ProductionWorker p2;
    p2.setter(423.55,1,2,1,34,2021);
    cout<<p2;

file.close();
}






class a{
    void funtion(int a,int b){}
}
class b:public a{
    void funtion(int a){}
}
class c:public b{
    void funtion(int a){}
    void funtion(int a,int b){}

}

c ajsndo;

ajsndo.function(5,5);