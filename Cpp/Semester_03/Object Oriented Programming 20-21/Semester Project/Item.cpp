#include<iostream>
#include<iomanip>
#include<string.h>
#include"Expiry_date.cpp"

using namespace std;
class Item{
protected:
    char name[30],company[45];
    int price,stock;
    expiry_date d;
    void copy(char name[]="",char company[]="",
        int price=0,int day=0,int month=0,
        int year=0,int stock=0){
            
            strcpy(this->name,name);
            strcpy(this->company,company);
            this->price=price;
            d.set_day(day);
            d.set_month(month);
            d.set_year(year);
            this->stock=stock;
        }
    public:
    Item(char name[]="",char company[]="",
        int price=0,int date=0,int month=0,
        int year=0,int stock=0){
            
            copy(name,company,price,date,month,year,stock);
    }
    void set(char name[]="",char company[]="",
            int price=0,int date=0,int month=0,
            int year=0,int stock=0){
               
                copy(name,company,price,date,month,year,stock);
    }
    friend ostream& operator <<(ostream &out,const Item i);
};

void fun(){}

ostream& operator <<(ostream &out,const Item i){
    out<<left
    
    <<setw(25)<<"Item"
    <<setw(45)<<"Company"
    <<setw(7)<<"Price"
    <<"Stock "<<"Expiry Date  "<<"\n";
    
    out<<setw(25)<<i.name
    <<setw(45)<<i.company
    <<setw(7)<<i.price
    <<setw(6)<<i.stock
    <<i.d;
    out<<setfill(' ')<<right;
    return out;
}
/*
int main(){
    Item i;
    cout<<i<<"\n\n";
    i.set("Albuterol Sulfate","China National Chemical Engineering Co",95,8,2,2025,20);
    cout<<i;
    cout<<"this is it\n";//char name[]="",char company[]="",int price=0,int date=0,int month=0,int yechar name[]="",char company[]="",int price=0,int date=0,int month=0,int year=0,int stock=0,char sec[]=""){ar=0,int stock=0,char sec[]=""){
        return 0;
}*/
