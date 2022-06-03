#include <iostream>
#include <iomanip>
#include <string.h>


using namespace std;

class persondata{
	char firstname[50], lastname[50], email[50];
	unsigned int houseno;
	char block;
	char  city[50];
	
public:
	persondata(char firstname[]="", char lastname[]="", char email[]="", unsigned int houseno=0, char block='A', char city[]=""){
	        strcpy(this-> firstname,firstname );
	        strcpy(this-> lastname,lastname);
	        strcpy(this-> email,email);
	        this-> houseno = houseno;
	        this-> block = block;
	        strcpy(this-> city,city);
	}
void set_firstname(){
        strcpy(this->firstname,firstname);
        }
void set_lastname(){
        strcpy(this->lastname,lastname);
        }
void set_email(){
        strcpy(this->email,email);
        }
void set_houseno(){
        houseno=houseno;
        }
void set_block(){
        block=block;
        }
void set_city(){
        strcpy(this->city,city);
        }
string getfn()const{return firstname;}
string getln()const{return lastname;}
string getem()const{return email;}
int gethn()const{return houseno;}
char getb()const{return block;}
string getc()const{return city;}
};
ostream& operator << (ostream &out, const persondata &a){
	out<<"FIRST NAME\tLAST NAME\tEMAIL\t\t\tHOUSE NUMBER\tBLOCK\tCITY";
	out<<"\n";
	out<<a.getfn();
	out<<"\t";
	out<<a.getln();
	out<<"\t";
	out<<a.getem();
	out<<"\t\t\t\t\t\t";
	out<<a.gethn();
	out<<"\t";
	out<<a.getb();
	out<<"\t";
	out<<a.getc();
	out<<"\n";
	return out;
}


