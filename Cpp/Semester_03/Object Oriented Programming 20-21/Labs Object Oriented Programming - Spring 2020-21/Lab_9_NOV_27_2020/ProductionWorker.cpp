#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include "Employee.cpp"

using namespace std;

class ProductionWorker:public Employee{
    
    float pay_rate;
    unsigned int shift;
    void copy(float pay_rate,int shift,int employee_no,int day,int month,int year){
        if(pay_rate<0)
        this->pay_rate=0;
        else
        this->pay_rate=pay_rate;

        if(shift==1||shift==2)
        this->shift=shift;
        else shift=1;

        Employee_set(employee_no, day, month, year);
    }
    public:
    ProductionWorker(float pay_rate=0,int shift=1,
                    int employee_no=0,int day=1,
                    int month=1,int year=1){
        
        copy(pay_rate,shift,employee_no,day,month,year);
    }
    void setter(float pay_rate,int shift,int employee_no,int day,int month,int year){
        copy(pay_rate,shift,employee_no,day,month,year);
    }
    float get_pay_rate()const{return pay_rate;}
    int get_Shift()const{return shift;}

    friend ostream& operator <<(ostream& out,const ProductionWorker &p);
};
ostream& operator <<(ostream& out,const ProductionWorker &p){
    cout<<(Employee)p;
    out<<"\n";
    out<<"Shift: ";
    if(p.shift==1)
    out<<"Day";
    else if(p.shift==2)
    out<<"Night";

    out<<"\nPay Rate: "
    <<p.pay_rate<<"\n\n";
    return out;
}