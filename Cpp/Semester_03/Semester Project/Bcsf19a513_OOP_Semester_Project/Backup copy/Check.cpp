#include<iostream>
#include<string.h>
#include<iomanip>
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

class Item{
protected:
    char name[30],company[45];
    int price,stock;
    date d;
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

class Medicine:public Item{
    bool doc_pres;
    char sec[25];
    public:
    Medicine(char name[]="",char company[]="",int price=0,int date=0,int month=0,int year=0,int stock=0,char sec[]="",bool doc=false):
    Item(name,company,price,date,month,year,stock){
        this->doc_pres=doc_pres;
        strcpy(this->sec,sec);
    }
    void set(char name[],char company[],int price,int date,int month,int year,int stock,char sec[],bool doc){
        Item::set(name,company,price,date,month,year,stock);
        this->doc_pres=doc_pres;
        strcpy(this->sec,sec);
    }
    friend ostream& operator <<(ostream &out,const Medicine m);

    void operator =(const Medicine &M){
        this->doc_pres=M.doc_pres;
        strcpy(this->sec,M.sec);
        strcpy(this->name,M.name);
        strcpy(this->company,M.company);
        this->price=M.price;
        d.set_day(M.d.get_day());
        d.set_month(M.d.get_month());
        d.set_year(M.d.get_year());
        this->stock=M.stock;
    }
};
ostream& operator <<(ostream &out,const Medicine m){
    cout<<Item(m);
    out<<'\n'<<"Section: ";
    out<<m.sec<<'\n';
    out<<"Requires Doctor Prescription:";
    if(m.doc_pres){out<<"Yes\n\n";}
    else {out<<"No\n\n";}
    return out;
}

void Filehandle(const Medicine m[]){
    ofstream out("input.bin",ios::out|ios::binary);
    out.seekp(0);
    char a[50];strcpy(a,"Islamia Pharmacy");
    out.write(a,sizeof(char)*50);
int count=50;
    out.write((char*)&count,sizeof(int));

   // out.write((char*)&S.store_name,sizeof(char)*50);
    for(int i=0;i<count;i++){
        out.write((char*)&m[i],sizeof(Medicine));
        cout<<m[i];
        }
    //out.write((char*)&S.store_name,sizeof(char)*50);
    //for(i=0;i<5;i++){ }
    out.close();
}

int main(){

    ifstream in("input.bin",ios::in|ios::binary);
int count;char n[50];Medicine M[50];

in.read(n,50);
cout<<n;
in.read((char*)&count,sizeof(int));
cout<<"\n\n"<<count;
in.read((char*)M,sizeof(Medicine)*50);
cout<<"\n\n";

for(int i=0;i<50;i++)
cout<<M[i];
    return 0;
}