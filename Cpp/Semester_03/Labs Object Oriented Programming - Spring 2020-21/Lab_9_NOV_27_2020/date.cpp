#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>

using namespace std;

class date{
    int day,month,year;
    public:
    void set_day(int day1){
        if(day1<=0)
        this->day=1;
        else if(day1>30)
        this->day=30;
        else this->day=day1;
    
    }
    void set_month(int month1){
        if(month1<=0)
        this->month=1;
        else if(month1>12)
        this->month=12;
        else this->month=month1;
    
    }
    void set_year(int year){
        if(year<0)
        this->year=1;
        else this->year=year;
    }
    int get_day()const{return day;}
    int get_month()const{return month;}
    int get_year()const{return year;}
};
ostream& operator <<(ostream& out,const date &d){
    out<<setfill('0')<<right
    <<setw(2)<<d.get_day()<<'-'
    <<setw(2)<<d.get_month()<<'-'
    <<setw(4)<<d.get_year();
    return out;
}
/*
int main(){
    date d;
    d.set_day(0);
    d.set_month(0);
    d.set_year(2020);
    cout<<d<<'\n';
    return 0;
}*/