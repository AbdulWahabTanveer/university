#include<iostream>
#include<string.h>
#include"Store.cpp"

using namespace std;

class Medicalstore:public Store{
    bool doc_pres;
    public:
    Medicalstore(int count,char name[],bool doc_pres):Store(count,name){
        this->doc_pres=doc_pres;
    }
};
ostream& operator <<(ostream &out,const Medicalstore &m){
    out<<(Store)m;
    return out;
}
int main(){
    MedicalStore m(2,"Islamia Pharmacy","Albuterol Sulfate","China National Chemical Engineering Co",95,8,2,2025,20,"Genetics",true);
    cout<<m;
    return 0;
}
