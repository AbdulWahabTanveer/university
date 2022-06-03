#include<iostream>
using namespace std;

class Employee{

    string SN,FN;
    int H,HR;

    public:

        Employee(string fn, string sn){
            SN=sn;
            FN=fn;
            H=30;
            HR=100;
        }//assign 30 to hours and 100 hour rate

        Employee(string fn, string sn, int h, int hR){
            SN=sn;
            FN=fn;
            if(h<20)
                H=20;
            else
                H=h;
            if(hR<50)
                HR=hR;
            else
                HR=hR;
        }//called setters inside

        void setHours(int h){
            if(h<20)
                H=h;
            else
                H=h;}

        void setHourRate(int hR){
            if(hR<50)
                HR=hR;
            else
                HR=hR;}

        void increaseHourRate(int inc){
            H=H+inc;
        };

        void show(){
            cout<<SN<<' '<<FN<<' ';
            cout<<H<<' '<<HR<<' '<<calcSalary()<<'\n';
        }

        int calcSalary(){
            float salary;
            if(H>40){
                salary=40*HR;
                salary=salary+((H-40)*(1.5*HR));
            }
            else
                salary=HR*H;
            return int(salary);
        }
};

int main(){

    string sN, fN;

    int h, hR;

    cin>>fN>>sN;

    Employee emp1 (sN, fN);

    cin>>fN>>sN;

    cin.clear();

    cin>>h>>hR;

    Employee emp2 (sN, fN, h, hR);

    emp1.show();

    emp2.show();

    cout << emp1.calcSalary() << ' ' << emp2.calcSalary() << '\n';

    return 0;
}
