#include<iostream>

using namespace std;

class A{
public:
void fa(){cout<<"Called A";}
};
class B:public A{
public:
void fb(){cout<<"Called B";}
};
class C:public B{
public:
void fc(){cout<<"Called C";}
};

int main(){
A *aptr;
B *bptr;

aptr=new A;// A object ptr A

C *cptr= static_cast<C*> (aptr);
cptr->fc();

}


