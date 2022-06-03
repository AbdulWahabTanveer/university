#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include"date.cpp"

using namespace std;

class Employee{

    int employee_no;
    date d;
    friend ostream& operator <<(ostream& out,const Employee &d);
    void copy(int employee_no,int day,int month,int year){
        this->employee_no=employee_no;
        d.set_day(day);
        d.set_month(month);
        d.set_year(year);
    }
    public:
    Employee(int employee_no=0,int day=1,int month=1,int year=1){
        copy(employee_no, day, month, year);
    }
    void Employee_set(int employee_no,int day,int month,int year){
        copy(employee_no, day, month, year);
    }
    int get_day()const{return d.get_day();}
    int get_month()const{return d.get_month();}
    int get_year()const{return d.get_year();}
    int get_employee_no()const{return employee_no;}

};
ostream& operator <<(ostream& out,const Employee &e){
    out<<"Employee No: "<<e.employee_no<<'\n';
    out<<"Date: ";cout<<e.d;
    return out;
}
/*
int main(){
    Employee e;
    //d.set_day(0);
    //d.set_month(0);
    //d.set_year(2020);
    cout<<e<<'\n';
    return 0;
}*/