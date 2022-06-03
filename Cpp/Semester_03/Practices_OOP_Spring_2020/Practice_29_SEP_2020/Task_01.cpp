#include<iostream>
using namespace std;

class Student{
    string m_name,m_phoneno;int m_rollno;
    public:
    void set(string name,string phoneno,int rollno){
        m_name=name;
        m_phoneno=phoneno;
        if(rollno>0){
           m_rollno=rollno;
        }
        else{
            rollno=0;
        }
        
    }
    void show(){
        cout<<"\n";
        cout<<"Name: "<<m_name<<"\n";
        cout<<"Phone-No: "<<m_phoneno<<"\n";
        cout<<"Rollno: "<<m_rollno<<"\n";
        cout<<"\n";
    }
};

int main(){
    int rollno;
    string phoneno,name;
    Student S1,S2;
    
    cout<<"Enter Name Omitting Space: ";
    cin>>name;
    cout<<"Enter Phone No: ";
    cin>>phoneno;
    cout<<"Enter Rollno: ";
    cin>>rollno;

    S1.set(name,phoneno,rollno);

    cout<<"Enter Name Omitting Space For Student 2 : ";
    cin>>name;
    cout<<"Enter Phone No For Student 2 : ";
    cin>>phoneno;
    cout<<"Enter Rollno For Student 2 : ";
    cin>>rollno;

    S2.set(name,phoneno,rollno);

    S1.show();S2.show();

}