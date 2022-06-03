#include<iostream>

using namespace std;

class A{
public:

 virtual void fa(){ cout<<"Called A";}//virtual table
};
class B:public A{
public:
void fa(){cout<<"Called B";}
};
class C:public B{
public:
void fa(){ cout<<"Called A from C\n";}
void fc(){cout<<"Called C native function";}
};

int main(){
A *aptr;
B *bptr;

aptr=new C;
aptr->fa();
//aptr->fc();
C *cptr= dynamic_cast<C*> (aptr);
//if(cptr==0) {cout<<cptr;return 0;}
cptr->fc();
return 0;
}


