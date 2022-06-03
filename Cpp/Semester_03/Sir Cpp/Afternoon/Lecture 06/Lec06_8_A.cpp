#include <iostream>

using namespace std;

class Point2D{	//Point2D lies in first quadrant means x & y are positive
	int x,y;
public:
	Point2D(){
		x=y=0;
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
	~Point2D(){
		cout << "Destructor Called\n";
	}
};
void fazoolFunction(){
	Point2D p4;
}

int main(){
	Point2D p1, p2, p3;
	p1.show();
	fazoolFunction();
	p2.show();
	p3.show();
	return 0;
}
