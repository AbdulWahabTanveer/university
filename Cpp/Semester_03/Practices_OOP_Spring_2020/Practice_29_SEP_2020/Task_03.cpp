#include<iostream>
using namespace std;

class BinaryCalc{
    int m_n1,m_n2;
    
    public:
    void set(int n1,int n2){
        m_n1=n1;
        m_n2=n2;
    }
    void Add() const{
        int r;
        r=m_n1+m_n2;
        cout<<"Addition Result: "<<r<<"\n";
    }
    void Sub() const{
        int r;
        r=m_n1-m_n2;
        cout<<"Subtraction Result: "<<r<<"\n";
    }
    void multi() const{
        int r;
        r=m_n1*m_n2;
        cout<<"Multiplication Result: "<<r<<"\n";
    }
    void show() const{
        cout<<"\n";
        cout<<"Number 1 : "<<m_n1<<"\n";
        cout<<"Number 2 : "<<m_n2<<"\n";
        cout<<"\n";
    }
};

int main(){
    int n1,n2,perimeter,area;
    BinaryCalc C1;
    
    cout<<"Enter Number 1 : ";
    cin>> n1;
    cout<<"Enter Number 2 : ";
    cin>> n2;

    C1.set(n1,n2);
    C1.show();
    C1.Add();
    C1.multi();
    C1.Sub();

    return 0;
    

}