#include <iostream>

using namespace std;

class Point2D{	//Point2D lies in first quadrant means x & y are positive
	int x,y;
public:
	Point2D(){		//Non-parameterized constructor
		x=y=0;
	}
	Point2D(int vx, int vy){		//Parameterized constructor
		if (vx<0)	x = 0;
		else		x = vx;
		if (vy<0)	y = 0;
		else		y = vy;
	}
	void set(int vx, int vy){
		setX(vx);	setY(vy);
	}
	void setX(int vx){
		if (vx<0)	x = 0;
		else		x = vx;
	}
	void setY(int vy){
		if (vy<0)	y = 0;
		else		y = vy;
	}
	int getX() const{
		return x;
	}
	int getY() const{
		return y;
	}
	void show() const{
		cout << "X:" << x << ",Y:" << y << '\n';//only reading value
	}
};

int main(){
	Point2D p1, p2, p3(3,5);
	p1.show();
	p2.show();
	p3.show();
	return 0;
}
