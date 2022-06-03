#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<ctime>

using namespace std;

class Employee{
    protected:
    string fname,sname;
    int salary;
    friend ostream& operator <<(ostream& out,const Employee &d);
    public:
    Employee(int salary=0,string sname="",string fname=""){
        this->salary=salary;
        this->sname=sname;
        this->fname=fname;
    }
    virtual int calcsal()const=0;
   
};
ostream& operator <<(ostream& out,const Employee &e){
    out<<"Employee Name: "<<e.fname<<' '<<e.sname<<'\n';
    out<<"Employee Salary: "<<e.calcsal()<<'\n';
    return out;
}
class Regemp:public Employee{
    int add_hours;
    public:
    Regemp(int add_hours,int salary,string sname,string fname):Employee(salary,sname,fname){
        this->add_hours=add_hours;
    }
     int calcsal()const{
         return salary+(add_hours*100);
    }
};
class ConEmp:public Employee{
    int hour_rate,hours;
    public:
    ConEmp(int hour_rate,int hours,int salary,string sname,string fname):Employee(salary,sname,fname){
        this->hour_rate=hour_rate;
        this->hours=hours;

    }
    int calcsal()const{
         return salary+(hours*hour_rate);
    } 
};
class DWageEmp:public Employee{
    int hour_rate,hours;
    public:
    DWageEmp(int hour_rate,int hours,string sname,string fname):Employee(0,sname,fname){
        this->hour_rate=hour_rate;
        this->hours=hours;

    }
    int calcsal()const{
         return (hours*hour_rate);
    }
   
};
string randfname(){
int choice=rand()%7+1;
    switch(choice){
    case 1:
    return "Fatima";
    case 2:
    return "Hassan";
    case 3:
    return "Nofil";
    case 4:
    return "Unaiza";
    case 5:
    return "Haseeb";
    case 6:
    return "Waleed";
    }
    return "Hamza";
}
string randsname(){
    int choice=rand()%5+1;
    switch(choice){
    case 1:
    return "Wahab";
    case 2:
    return "Abdul Mateen";
    case 3:
    return "Abid";
    case 4:
    return "Farooq";
    
    }
    return "Hamza";
}
int main(){
    srand(time(0));
    Employee *e[10];int choice,salary,hours,hours_rate;
for(int i=0;i<10;i++){
    choice=rand()%3+1;
    salary=rand()%50000+10000;
    hours=rand()%12+1;
    hours_rate=rand()%500+100;
    switch(choice){
        case 1:
        cout<<'\n'<<"Regular Employee";
        e[i]=new Regemp(hours,salary,randsname(),randfname());
        cout<<'\n'<<*e[i];
            break;
        
        case 2:
        cout<<'\n'<<"Contractual Employee";
        e[i]=new ConEmp(hours_rate,hours,salary,randsname(),randfname());
        cout<<'\n'<<*e[i];
        cout<<"Basic salary: "<<salary<<'\n';
        cout<<"Hours Rate Random: "<<hours_rate<<"\n";
        cout<<"Hours Random: "<<hours<<"\n";
            break;
        
        
        case 3:
        cout<<'\n'<<"Daily Wagers Employee";
        e[i]=new DWageEmp(hours_rate,hours,randsname(),randfname());
        cout<<'\n'<<*e[i];
        cout<<"Hours Rate Random: "<<hours_rate<<"\n";
        cout<<"Hours Random: "<<hours<<"\n\n";
            break;
    }
}


    return 0;
}