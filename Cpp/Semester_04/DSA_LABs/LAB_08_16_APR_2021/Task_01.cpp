#include <iostream>
#include <iomanip>


using namespace std;

class CarNode{
    public:
	string company,brand,transmittion;
	bool Registered;
	int enginecapacity,seatingcapacity,mileage,price;
	CarNode* next;
	CarNode* prev;
	CarNode(){
		company="Toyota";
		brand="Yaris";
		transmittion="Manual";
		Registered=false;
		enginecapacity=1300;
		seatingcapacity=4;
		mileage=62000;
		price=220000;
		next=NULL;
		prev=NULL;
	}
	CarNode(string c,string b,bool reg,int mil,int price,string trans="Automatic",int eng=660,int cap=4,CarNode* p=NULL,CarNode* n=NULL){
		company=c;
		brand=b;
		transmittion=trans;
		Registered=reg;
		enginecapacity=eng;
		seatingcapacity=cap;
		mileage=mil;
		this->price=price;
		next=n;
		prev=p;
	}
	void Show(){
		cout<<left<<setw(12)<<company<<"  "<<setw(10)<<brand<<"  "<<setw(14)<<transmittion
		<<"  "<<setw(12);
		if(Registered) 
		cout<<setw(18)<<"Registered";
		else
		cout<<setw(18)<<"Unregistered";
		
		cout<<"  "<<setw(17)<<enginecapacity
		<<"  "<<setw(12)<<seatingcapacity<<"  "<<setw(7)<<mileage<<"  "<<setw(9)<<price<<endl;
	}
	friend ostream & operator << (ostream &out, const CarNode &c);

};
ostream & operator << (ostream &out, const CarNode &c){
    out << c.company<<' '<<c.brand<<' '<<c.enginecapacity<<"CC "<<"[Rs. "<<c.price<<" only]"<<endl;
    out << c.transmittion <<' ';
	
	if(c.Registered) 
		out<<"Registered"<< endl;
	else
		out<<"Unregistered"<< endl;

	out<<"Seating Capacity: "<<c.seatingcapacity<<endl;
	out<<"Mileage:  "<<c.mileage<<endl;
    return out;
} 



class Showroom{
	CarNode *head;
public:
	Showroom(){	head = new CarNode();	head -> next = head ;head -> prev = head;	}
	
	/*void addNodeAtHead(string c,string b,bool reg,int mil,int price,string trans="Automatic",int eng=660,int cap=4){
		CarNode *newNode =new CarNode(c,b,reg,mil,price,trans,eng,cap,head, head->next);
		head -> next -> prev = newNode;
		head -> next = newNode;
	}*/
	void addNewCar(string c,string b,bool reg,int mil,int price,string trans="Automatic",int eng=660,int cap=4){
		CarNode *newNode =new CarNode(c,b,reg,mil,price,trans,eng,cap, head->prev, head);
		head -> prev -> next = newNode;
		head -> prev = newNode;
	}
	
	void print(CarNode *t){
		if (t == head)	return;
		cout << *t  << ' ';	
		print(t->next);
	}
	void print(){
		print(head->next);
		cout << '\n';	
	}
	
	void searchCompany(string val){
		CarNode *t;
		t=head;
		if(t->company.compare(val)==0)
				cout<< *t <<endl;
		t=head->next;
		for(;t!=head;t=t->next){
			if(t->company.compare(val)==0)
				cout<< *t<<endl;
		}
	}
	void searchBrand(string val){
		CarNode *t;
		t=head;
		if(t->brand.compare(val)==0)
				cout<< *t <<endl;
		t=head->next;
		for(;t!=head;t=t->next){
			if(t->brand.compare(val)==0)
				cout<< *t <<endl;
		}
	}
	void searchAuto(){
		CarNode *t;
		t=head;
		if(t->transmittion.compare("Automatic")==0)
				cout<< *t <<endl;
		t=head->next;
		for(;t!=head;t=t->next){
			if(t->transmittion.compare("Automatic")==0)
				cout<< *t<<endl;
		}
	}
	void searchManual(){
		CarNode *t;
		t=head;
		if(t->transmittion.compare("Manual")==0)
				cout<< *t <<endl;
		t=head->next;
		for(;t!=head;t=t->next){
			if(t->transmittion.compare("Manual")==0)
				cout<< *t<<endl;
		}
	}
	void searchRange(int low,int high){
		CarNode *t;
		t=head;
		if(t->price > low && t->price < high )
				cout<< *t <<endl;
		t=head->next;
		for(;t!=head;t=t->next){
			if(t->price > low && t->price < high )
				cout<< *t<<endl;
		}
	}
	friend ostream & operator << (ostream &out, const Showroom &s);

};

ostream & operator << (ostream &out, const Showroom &s){
	out<<"Company"<<"       "<<"Brand"<<"     "<<"Transmittion"
		<<"     "<<"Registeration"<<"       "<<"EngineCapacity"
		<<"  "<<"SeatingCapacity"<<"  "<<"Mileage"<<"    "<<"Price"<<endl;
	CarNode *t;
	t=s.head;
	t->Show();
	t=s.head->next;
		for(;t!=s.head;t=t->next){
				t->Show();
		}
	return out;
}

int main(){
	CarNode list;
	cout<<list<<endl;
	list.Show();

	cout<<endl<<endl<<"Printed First Default Constructed Car in CarNode Using Ostream And Show Functions";
cout<<endl<<"-------------------------------------------------------------------------"<<endl;


	Showroom L;
	L.addNewCar("Suzuki","Wagon R",true,65000,180000,"Manual",1000,5);
	L.addNewCar("Hyundai","Tuson",true,30000,650000,"Automatic",1800,5);
	L.addNewCar("Changhan","Alsvin",true,45000,240000,"Manual",1300,5);
	
	cout<<endl<<endl<<"Auto Search result"<<endl;
	L.searchAuto();
cout<<"-------------------------------------------------------------------------"<<endl;

	cout<<endl<<endl<<"Manual Search result"<<endl;
	L.searchManual();
cout<<"-------------------------------------------------------------------------"<<endl;

	cout<<endl<<endl<<"In Range 100000-250000"<<endl;
	L.searchRange(100000,250000);
cout<<"-------------------------------------------------------------------------"<<endl;

	cout<<endl<<endl<<"In Company Suzuki"<<endl;
	L.searchCompany("Suzuki");
cout<<"-------------------------------------------------------------------------"<<endl;

	cout<<endl<<endl<<"In Company Yaris"<<endl;
	L.searchBrand("Yaris");
cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<endl<<"Printing All Cars As a Table";
	cout<<endl<<endl<<endl;
	cout<<L;
	cout<<endl<<endl<<"toyota Yaris Is dummy Not included in results";
	return 0;
}
