#include <iostream>

using namespace std;

class Rope{
	int feet;
	int inches;
	void normalize(){
		if (inches>=12){    
			feet += inches / 12;			
			inches%=12;		
		}
	}		
public:
	Rope(int feet=1, int inches=0){
		if (feet==0 && inches==0)
			feet = 1;
		this->feet = feet;
		this->inches = inches;
	}
	int getFeet() const{
		return feet;
	}
	int getInches() const{
		return inches;
	}
	void setFeet(int feet){
		if (feet==0)	feet = 1;
		this -> feet = feet;
	}
	void setInches(int inches){
		this -> inches = inches;
	}
	//Pre Increment
	Rope& operator++(){
		inches++;
		normalize();
		return *this;
	}
	//Post Increment
	Rope operator++(int){
		Rope newRope = *this;	//Create copy of current object using default copy constructor
		inches++;
		normalize();
		return newRope;
	}
	Rope operator+(const Rope &r){
		Rope newRope;
		newRope.feet = feet + r.feet;
		newRope.inches = inches + r.inches;
		newRope.normalize();	
		return newRope;
	}
	void show() const{
		cout << "Rope is " << feet << " feet ";
		if (inches > 0)
			cout << inches << " inches ";
		cout << "long\n";
	}
	friend Rope& operator * (Rope&, const int);//Friendship is granted to global function
};
//Global function to multiply rope with a scalar number
//This multiplication will increase the rope by scalar number times like 2 times or 3 times
Rope& operator * (Rope &r, const int K){
	r.feet = r.feet * K ;
	r.inches = r.inches * K ;
	r.normalize();
	return r;
}

int main(){
	Rope r1(3,5);
	r1.show();
	r1 * 3;
	r1.show();
	return 0;
}




