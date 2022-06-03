#include <iostream>
#include <ctime>

using namespace std;

//const data members. Such data members can be initialized once for any individual object.
//Constant data members are initialized before the constructor body


class ABC{
	const int WIDTH, HEIGHT;
	int x, y;	
public:
	ABC ():	WIDTH(100), HEIGHT(200){
		x = y = 0;
	}
	ABC (int width, int height):	WIDTH(width), HEIGHT(height){
		x = y = 0;
	}
	ABC (int width, int height, int x, int y):	WIDTH(width), HEIGHT(height){
		this->x = x;
		this->y = y;
	}
	int getWIDTH() const{
		return WIDTH;
	}	
	int getHEIGHT() const{
		return HEIGHT;
	}	
	int getX() const{
		return x;
	}	
	int getY() const{
		return y;
	}	
};


int main(){
	ABC abc1, abc2(50, 100, 10, 20);
	cout << abc1.getWIDTH() << ' ' << abc1.getHEIGHT() << '\n';
	cout << abc2.getWIDTH() << ' ' << abc2.getHEIGHT() << ' ' << abc2.getX() <<
		' ' << abc2.getY()<<'\n';
	return 0;
}













/*#include<iostream>

using namespace std;

class Rope{
    int feet,inches;
    public:
    
}

int main(){

}*/
/*Class Rope has two data members, feet and inches. Create follwoing 
member functions:

Parameterized copy constructor

ostream operator

operator to add two rope objects into new object.
++ post increment operator

++ pre increment operator

-- post decrement operator

-- pre decrement operator

+= to add two rope objects into first operand

to compare two rope objects and return true, if first object is greater, 
otherwise false

= to compare two rope objects and return true, if first object is greater
 or equal to second object, otherwise false

== to compare two rope objects and return ture, if both objects are same,
 otherwise return false

Create two objects, by input 4 parameters. Display both rope objects using
 ostream. Perform operation 3 to 10 in sequence and display objects after 
 each operation. Perform binary operations for first two objects and perform 
 unary operations for first object only. For relational operatorions print TRUE 
 or FALE.*/