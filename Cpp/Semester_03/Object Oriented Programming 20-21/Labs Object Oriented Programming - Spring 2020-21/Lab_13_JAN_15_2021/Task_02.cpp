#include <iostream>
#include <iomanip>
#include <string.h>
#include<ctime>

/*Edited Lab 10 Task 2 Which was a Group Lab*/


using namespace std;

class ship{
    private:
    string name;
    string builtyear;
    public:
    ship(string name=" ", string builtyear=" ")
	{
    this->name=name;
    this->builtyear=builtyear;
    }
    void set_ship(string name, string builtyear=""){
        this->name=name;
        this->builtyear=builtyear;      
    }
    string get_name(){return name;}
    string get_builtyear(){return builtyear;}
    virtual void printfunc()
    {
        cout<<left<<setw(25)<<"SHIP NAME"<<setw(25)<<"BULTYEAR";
        cout<<endl;
        cout<<setw(25)<< name;
        cout<<setw(25)<< builtyear<<'\n';
    }
};
class cruiseship:public ship{
    int numofpass;
    
    public:
    cruiseship(string name="",string year="",int numofpass=0):ship(name,year)
	{
    this->numofpass=numofpass;
    }
    void set_numofpass(int numofpass){
            this->numofpass=numofpass;
    }
     void  printfunc()
    {
        cout<<left<<setw(25)<<"SHIP NAME"<<setw(25)<<"NUMBER OF PASSENGERS";
        cout<<endl;
        cout<<setw(25)<< get_name();
        cout<<setw(25)<< numofpass<<'\n';
    }
    
};
class cargoship:public ship
	{
    int capacity;
    public:
    cargoship(string name="",string year="",int capacity=0):ship(name,year){
    this->capacity=capacity;
    }
    void set_capacity(int capacity){
        this->capacity=capacity;
    }
    
    void printfunc()
    {
        cout<<left<<setw(25)<<"SHIP NAME"<<setw(25)<<"CARGO CAPACITY";
        cout<<endl;
        cout<<setw(25)<<get_name();
        cout<<setw(25)<<capacity<<'\n';
    }

};
string shipname(){
    int choice=rand()%5+1;
    switch(choice){
    case 1:
    return "Ghazi";
    case 2:
    return "Conqueror";
    case 3:
    return "Khalid";
    case 4:
    return "Hadaf";
    
    }
    return "Titanic";
}

int main()
{

//Testing purposes
    
    //Making static objects and using print functions
    ship s11("Ghazi","2021");
    s11.printfunc();
    cout<<"\n";
    ship s12("Ghazi ||","2023");
    s12.printfunc();
    cout<<"\n";
    ship s13("Ghazi |||","2025");
    s13.printfunc();
    cout<<"\n";

    ship *pointer;

    pointer=new ship[1];
    pointer->set_ship("Khalid","2001");
    pointer->printfunc();


    pointer=new cruiseship[1];
    pointer->set_ship("Khalid ||","2012");
    cout<<"\n";
    cruiseship *c11=(cruiseship*)pointer;
    c11->set_numofpass(3000);
    c11->printfunc();
    cout<<"\n";

    pointer=new cargoship[1];
    pointer->set_ship("Khalid |||","2015");
    cargoship *c12=(cargoship*)pointer;
    c12->set_capacity(150000);
    c12->printfunc();


cout<<"\n------------------------------------------\n\nRandomized Data and Type of Ships\n";


    srand(time(0));
    ship *s[10];int choice;
    string year="2002";char c;
for(int i=0;i<10;i++){
    choice=rand()%3+1;
    switch(choice){
        case 1:
        cout<<"\nShip\n";
        s[i]=new ship(shipname(),year);
        s[i]->printfunc();
         year[2]='1';
        year[3]='9';
            break;
        
        case 2:
        cout<<'\n'<<"Cruise Ship\n";
        s[i]=new cruiseship(shipname(),year,rand()%300+50);
        s[i]->printfunc();
       
            break;
        
        
        case 3:
        cout<<'\n'<<"Cargo Ship\n";
        s[i]=new cargoship(shipname(),year,rand()%1500+100);
        s[i]->printfunc();
            break;
    }
}
cout<<"\nProgram Ended :)\n<---------------------------------------------->\n";

    return 0;
}