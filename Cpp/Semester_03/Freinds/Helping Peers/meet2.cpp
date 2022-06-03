#include <iostream>
#include <fstream>
#include <string.h>//String copy function strcpy
#include <iomanip>

using namespace std;

class Student{
	char fName[10], sName[10], rNo[11];//Roll no has 10 characters + 1 null character
	float cgpa;  //10+10+11+4 = 35 bytes size of object, padding of 1 byte will make the size 36 bytes
public:
	Student(){}
	Student(const char fn[], const char sn[], const char r[], float cgpa){
		set(fName, sName, rNo, cgpa);
	}
	void set(const char fn[], const char sn[], const char r[], float cgpa){
		strcpy(fName, fn);
		strcpy(sName, sn);
		strcpy(rNo, r);
		this->cgpa = cgpa;
	} 
	friend ostream& operator << (ostream &, const Student &);
};
ostream& operator << (ostream &out, const Student &st){
	out << st.rNo << ' ' << left << setw(10) << st.fName << ' ' << setw(10) << st.sName << ' ' << setw(4) 
		<< fixed << setprecision(2) << st.cgpa << '\n';
	return out;
}
int main(){
	#define COUNT 5
    Student s[COUNT];//Declared array of size 5, means 5 objects of type student
	char fName[COUNT][10]={"Qasim", "Aslam","Muhammad", "Shahzad","Adnan"};
	char sName[COUNT][10]={"Munir", "Raza", "Khawar", "Amin","Rasool"};
	char rNo[COUNT][11]={"BCSF01M001","BCSF01M002","BCSF01M004","BCSF01M007","BCSF01M009"};
	float cgpa[COUNT]={3.15,3.2,2.86,3.34,3.78};
	int i;
	for (i=0;i<COUNT;i++)
		s[i].set(fName[i], sName[i], rNo[i], cgpa[i]);
	
    fstream out("students.bin", ios::binary | ios::in | ios::out);
    //appened 5
	out.write( (char*) s , sizeof(Student) * COUNT );//10 digit--- P 4
	out.close();

	Student newS[5];
	
    ifstream in("students.bin", ios::binary);
	in.read ( (char*) newS, sizeof(Student) * COUNT );//file
	for (i=0;i<COUNT;i++)
		cout << newS[i];
	in.close();
    return 0;//file char ++ string
}
// row*Colum 5 students jaga
// newS pointer adress
//new pointer file sara bytes 