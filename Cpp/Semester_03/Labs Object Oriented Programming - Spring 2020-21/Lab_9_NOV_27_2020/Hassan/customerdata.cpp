#include <iostream>
#include <iomanip>
#include <string.h>
#include "persondata.cpp"

using namespace std;

class customerdata:public persondata{
	
	unsigned int cus_no;
	bool allow;
	char cusemail[50];

public:
        customerdata(unsigned int cus_no=0,char cusemail[]="",bool allow=true){
	        this-> cus_no = cus_no;
	        strcpy(this->cusemail,cusemail);
	        this-> allow = allow;

	}
void set_cusno(){
        this->cus_no=cus_no;
        }
void set_email(char cusemail[]){
        if(allow==true)
        strcpy(this->cusemail,cusemail);
        }
unsigned int getcus_no()const{return cus_no;}
string getcusemail()const{return cusemail;}

friend ostream& operator << (ostream &out, const customerdata &b);



};
ostream& operator << (ostream &out, const customerdata &b)
{
        cout<<(persondata)b;
        out<<"CUSTOMER NO.";
        out<<"\t";
        out<<"EMAIL";
        out<<"\n";
        out<<b.getcus_no();
        out<<"\t";
        out<<b.cusemail;
        out<<"\n\n";
        return out;
}
int main(){
customerdata c;
cout<<c;

}