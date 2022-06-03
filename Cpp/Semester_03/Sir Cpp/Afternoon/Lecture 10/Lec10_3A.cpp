#include <iostream>

using namespace std;

class Point2D{
	int x,y;
public:
	Point2D(int x=0, int y=0){
		set(x, y);
	}
	void set(int x=0, int y=0){
		this->x = x;
		this->y = y;
	}
	void show() const{
		cout << "X:" << x << " ,Y:" << y << '\n';
	}
};
	

int main(){
	//Point2D *points = new Point2D[10];
	Point2D *points = (Point2D*) malloc(10*sizeof(Point2D));
	int i;
	for (i=0;i<10;i++)
		points[i].set(rand()%10,rand()%10);
	points[0] = Point2D(3, 5);
	for (i=0;i<10;i++)
		points[i].show();
	delete []points;
	return 0;
}
