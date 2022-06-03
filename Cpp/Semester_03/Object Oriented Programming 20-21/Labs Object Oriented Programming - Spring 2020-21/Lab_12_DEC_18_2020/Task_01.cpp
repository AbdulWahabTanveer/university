#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<ctime>

using namespace std;
//Incomplete code of Complex class
#define RND1 rand()%10-5
#define RND2 (rand()%10+1)

class Complex
{
double real, comp;
public:
Complex(){
real=RND1+1.0/RND2;
comp=RND1+1.0/RND2;
}
Complex operator +(const Complex &c){
    real+=c.real;
    comp+=c.comp;

    return *this;
}
friend ostream& operator <<(ostream& out,const Complex &c);
};
ostream& operator <<(ostream& out,const Complex &c){
        out<<"Real: "<<c.real<<"\n";
        out<<"Complex: "<<c.comp<<"\n";
        return out;
}

template<typename T>
T sum(T arr[],int size){
    T sum=arr[0];
    for(int i=1;i<size;i++)
        sum=sum+arr[i];
    return sum;
}

int main(){
    srand(time(0)); 
    int x[]={3,2,4,6}; 
    double d[]={2.3,4.1,5.2};
    cout<<sum(x,4)<<"\n";
    cout<<sum(d,3)<<"\n";
    
    Complex cArr[3]; int i;
    for (i=0;i<3;i++ ) 
       cout<<cArr[i];
    cout<<"\n"; 
    cout<<sum(cArr,3);
    return 0;
}