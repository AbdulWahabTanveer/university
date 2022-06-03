#include<iostream>
#include<iomanip>

using namespace std;

class Student{
    int salary,NO_of_anime;
    bool has_a_car;
    float height;
    public:
    Student(int salary=0,int NO_of_anime=0,bool has_a_car=false,float height=0.0){
        this->salary=salary;
        this->NO_of_anime=NO_of_anime;
        this->has_a_car=has_a_car;
        this->height=height;
    }  
    void IDK(){
    }

};
int main(){
    Student s1(50000,40,true,5.004);
    Student *s2[10];
    cout<<"Salary :"<<s1.salary;
}