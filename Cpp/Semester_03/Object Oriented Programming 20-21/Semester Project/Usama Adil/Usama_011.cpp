#include <iostream>
#include<iomanip>
#include <string.h>
#include <fstream>
using namespace std;

class Plant {
	char pname[50];
	int price;
	public:
	void setplant(char *pname, int price){
		strcpy(this -> pname,pname);
		this->price=price;
	}
		friend ostream& operator << (ostream &out, const Plant &p);
};
ostream& operator << (ostream &out, const Plant &p){
    out<<"\nname of plant: "<< p.pname<< "\nprice: "<<p.price<<"\n";
	return out;
}

// file write (50,0,21038710741)

// file read  (50,0,21038710741)

class Nursery{
	string nname = "Weed land";
	int cap=50;
	int csize=0;
	Plant **plant;
	public:
		Nursery(){
		//	strcpy(this->nname,nname);
			//this->cap =cap;
			plant = new Plant*[cap];
			for(int i=0;i<cap;i++)
			plant[i]= NULL;
		}

	bool addplant(char *name, int price ){
		for(int i=0;i<cap;i++)
		if(plant[i]==NULL){
			plant[i]=new Plant;
			plant[i]->setplant(name,price);
			csize++;
			return true;
		}
		return false;
}

bool deleteplant(int x){
	  	if(x>=cap || plant[x]== NULL) return false;
	  	delete plant[x];
	  	plant[x]= NULL;
	  	csize--;
	  	return true;
	  }

	   ~Nursery(){
		   //cout<<"destructor";
	  	for(int i;i<cap;i++)
		  if (plant[i]!= NULL)
		  delete plant[i];
		delete []plant;
	  }
	  void modify(int n, char *name, int price){
	  	plant[n]->setplant(name,price);
	  }

	friend ostream& operator << (ostream &out, const Nursery &n);
};
ostream& operator << (ostream &out, const Nursery &n){
    out<<"\nname of nursery: "<< n.nname;
	for(int i=0;i<n.cap;i++)
	if(n.plant[i] != NULL)
	 out<< *n.plant[i]<<"\n";
	out<<'\n';
	return out;
}


int main(){
	int count;
	int mod;
	//char nursery_name[30];
	char plant_name[30];
	//int capacity;
	int price;
	int choice;
	int nplants;
	//cout<< "enter no. of nurseries:\n";
	//cin >> count;
	Nursery nursery, newN;
	//for (int i=0;i<count;i++){
	//cout<<"enter nursery name:\n";
	//cin>>nursery_name;
	//cin.getline(nursery_name, 50);
	//cout<<"enter capacity:\n";
	//cin>>capacity;
//	nursery.setnursery();
fstream file("nursery.bin", ios::binary | ios::in | ios::out);
	if (file.fail()){//check if file successfully opened
		ofstream out("nursery.bin");//Otherwise create a new file
		out.close();				//close file
		file.open("nursery.bin", ios::binary | ios::in | ios::out);//Reopen in reading+writing mode
	}
	file.write((char*) &nursery, sizeof(Nursery));
	do{
	cout<<"press 1 for adding plant\n";
	cout<<"press 2 for removing plant\n";
	cout<<"press 3 for modifing plant\n";
	cout<<"press 4 to show all records\n";
	cout<<"press 0 to terminate\n";

	cout<<"enter choice of operation:\n";
	cin>> choice;
	switch(choice){
		case 1:{


			cout<<"enter plant name:\n";
			cin>>plant_name;
			cout<<"enter plant price:\n";
			cin>>price;
			nursery.addplant(plant_name, price);
			file.seekp(0, ios::end);
			file.write ( (char*) &nursery, sizeof(Nursery) );
			break;
		}
		case 2:{

			int rec;
			cout<<"enter number of the record to be deleted:\n";
			cin>> rec;
			rec=rec-1;
			nursery.deleteplant(rec);
			file.seekg(0);
			file.close();
			remove("nursery.bin");
			fstream out ("nursery.bin",ios::binary|ios::in | ios::out);
			out.write((char*) &nursery, sizeof(Nursery));

			break;
		}
		case 3:{

		    cout<< "enter rec no to be modified:\n";
			cin>> mod;
			mod=mod-1;
			cout<<"enter plant name:\n";
			cin>>plant_name;
			cout<<"enter plant price:\n";
			cin>>price;
			nursery.modify(mod,plant_name,price);
			file.seekg(0);
			file.close();
			remove("nursery.bin");
			fstream out2 ("nursery.bin",ios::binary|ios::in | ios::out);
			out2.write((char*) &nursery, sizeof(Nursery));
			break;
		}
		case 4:{
		    	//file.seekg(0, ios::end);
				//count = file.tellg() / sizeof(Nursery);//Counting number of objects
				file.seekg(0);
				file.read ( (char*) &newN, sizeof(Nursery) );
				cout << newN<<'\n';

				break;
			}

	}
}while (choice!=0);

	file.close();
//	cout<<"nursery:\n";
//	cout <<nursery << "\n";

//    newN.~Nursery();
//	nursery.~Nursery();

	return 0;
}

