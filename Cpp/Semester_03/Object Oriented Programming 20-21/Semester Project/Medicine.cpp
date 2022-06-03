#include<iostream>
#include<iomanip>
#include<string.h>
#include"Item.cpp"

using namespace std;

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
    char* get_name(){return name;}
    char* get_company(){return company;}
    int get_price(){return price;}
    int get_stock(){return stock;}
    void set_stock(int stock){ this->stock=stock;}

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
    void create_Medicine(){
        cout<<"Enter Details\n ";
          //  if(flag==true) cin.ignore(1, EOF);
      
        cout<<"Name: ";
            //if(second_flag==true) 
            cin.ignore(1, EOF);
            cin.getline(name,30);
        cout<<"Company: ";
            cin.getline(company,45);
        cout<<"Price: ";
            cin>>price;
        d.create_date();
        cout<<"Stock: ";
            cin>>stock;
        cout<<"Section: ";
            cin.ignore();
            cin.getline(sec,25);
        cout<<"Prescription Needed: ";
            cin>>doc_pres;
    }
};
ostream& operator <<(ostream &out,const Medicine m){
    cout<<m;
    out<<'\n'<<"Section: ";
    out<<m.sec<<'\n';
    out<<"Requires Doctor Prescription:";
    if(m.doc_pres){out<<"Yes\n\n";}
    else {out<<"No\n\n";}
    return out;
}
