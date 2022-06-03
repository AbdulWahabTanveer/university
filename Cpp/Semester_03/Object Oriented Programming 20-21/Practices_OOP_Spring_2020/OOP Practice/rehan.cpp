#include <iostream>
using namespace std;

class A{
int x;
public:
    A(int x){
    cout << "A constructor called\n";    
    }

    int f1(){
        cout << "f1 of A is called\n";
        return 999;
    }
};

int main(){

A *ptrA;
int x=0;
x = ptrA->f1();
cout<<"X is: "<<x;
return 0;

}
