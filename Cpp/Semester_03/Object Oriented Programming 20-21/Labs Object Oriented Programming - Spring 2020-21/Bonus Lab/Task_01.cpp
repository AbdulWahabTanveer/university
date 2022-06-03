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
    virtual int calcsal()const{
        return salary;
    };
    void set_salary(int salary){
        this->salary=salary;
    }
    int get_salary(){
        return this->salary;
    }
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

class Department{
    string title;
    int max_employee,current_employees;
    Employee **e;
    public:
    Department(string title="",int max_employee=0){
        this->current_employees=0;
        this->max_employee=max_employee;
        e=new Employee*[max_employee];
        for(int i=0;i<max_employee;i++)
            e[i]=NULL;
    }
    void add_employee(int hour_rate,int hours,string sname,string fname){
        e[current_employees++]=new DWageEmp(hour_rate,hours,sname,fname);
    }
    void add_employee(int hour_rate,int hours,int salary,string sname,string fname){
        e[current_employees++]=new ConEmp(hour_rate,hours,salary,sname,fname);
    }
    void add_employee(int add_hours,int salary,string sname,string fname,bool flag){
        e[current_employees++]=new Regemp(add_hours,salary,sname,fname);
    }
    void add_employee(int salary,string sname,string fname){
        e[current_employees++]=new Employee(salary,sname,fname);
    }
    void modify_salary(int no,int salary){
        e[--no]->set_salary(salary);
    }
    void calcsal(int no){
        cout<<e[--no]->get_salary();
    }
    void calcsal_all(){
        for(int i=0;i<current_employees;i++)
            cout<<"\n"<<*e[i];
    }
    void delete_employe(int no){
        for(int i=--no;i<current_employees-1;i++)
            e[i]=e[i+1];
        e[current_employees]=NULL;
        current_employees--;
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
    Department D("OMEGA University",10);
    srand(time(0));
    Employee *e[10];int choice,salary,hours,hours_rate;

for(int i=0;i<10;i++){
    choice=rand()%3+1;
    salary=rand()%50000+10000;
    hours=rand()%12+1;
    hours_rate=rand()%500+100;
    switch(choice){
        case 1:
        cout<<'\n'<<"Regular Employee\n";
        D.add_employee(hours,salary,randsname(),randfname(),false);
            break;
        
        case 2:
        cout<<'\n'<<"Contractual Employee\n";
        D.add_employee(hours_rate,hours,salary,randsname(),randfname());
            break;
        
        
        case 3:
        cout<<'\n'<<"Daily Wagers Employee\n";
        D.add_employee(hours_rate,hours,randsname(),randfname());
            break;
    }
}
    D.calcsal_all();
    cout<<"---------------------------------------------------";
    D.modify_salary(1,40000);
    cout<<"\nChanged Basic Salary of Employee#1 is : ";
    D.calcsal(1);
    cout<<"\n";
    cout<<"Deleted 2\n"<<"\nShowing all over again\n";
    D.delete_employe(2);
    D.calcsal_all();
    cout<<"\n------------------------------------------------------";
    cout<<"\nImportant notice Depending upon the type \n"
           << "of employee the salary calculation might result in unexpected results\n"
           << "So do keep that in mind";
    cout<<"\nEmployee Types in order printed at the Top before anything";

    cout<<"\n------------------------------------------------------\n\n";

    return 0;
}