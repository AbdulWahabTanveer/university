#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

void login(){
	char saved_name[25],saved_pass[10];
string name="",pass="";
again:

    ifstream data;
	data.open("Id.bin", ios::in|ios::binary);

	cout << "Enter Login Id : ";
	getline(cin,name);
    data.read(saved_name,25);
	string a(saved_name);

	
    cout << "Enter Password : ";
	getline(cin,pass);
    data.read(saved_pass,10);
	string b(saved_pass);

	if (a.compare(name)==0 && b.compare(pass)==0)
		{

		cout << "\t  _____________________________________________" << endl;
		cout << "\t |                                             |" << endl;
		cout << "\t |         ***************************         |" << endl;
		cout << "\t |         ***************************         |" << endl;
		cout << "\t |         ***************************         |" << endl;
		cout << "\t |         ***********WELCOME*********         |" << endl;
		cout << "\t |         ***************************         |" << endl;
		cout << "\t |         ***************************         |" << endl;
		cout << "\t |         ***************************         |" << endl;
		cout << "\t |         *******|1.Search a Medicine         |"<< endl;
		cout << "\t |         *******|2.Add New Medicine          |"<< endl;
		cout << "\t |         *******|3.Modify a Medicine         |" << endl;
		cout << "\t |         *******|4.Show a Medicine           |" << endl;
		cout << "\t |         *******|5.Bill some Medicines       |" << endl;
		cout << "\t |         *******|6.Show All Medicines        |" << endl;
		cout << "\t |_____________________________________________|" << endl;
		//cout << "\n\n" << "*******|Enter Operation Number: ";
		
}
else{
cout<<"Wrong User Name or Password Please try again.\n
	   Check Documentation for Further Details. ;)";
goto again;}

}