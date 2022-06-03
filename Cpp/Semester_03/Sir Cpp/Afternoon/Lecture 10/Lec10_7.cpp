#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix3x3{
	int e[3][3];
	void initRand(){
		int i,j;
		for (i=0;i<3;i++)
			for (j=0;j<3;j++)
				e[i][j]=rand()%5;
	}
public:
	Matrix3x3(){
		initRand();
	}
	Matrix3x3(int e[][3]){
		set(e);
	}
	void set(int  e[][3]){
		int i,j;
		for (i=0;i<3;i++)
			for (j=0;j<3;j++)
				this->e[i][j]=e[i][j];
	}
	void show() const{
		int i,j;
		for (i=0;i<3;i++){
			for (j=0;j<3;j++)
				cout << e[i][j] << ' ';
			cout << '\n';
		}
	}
	void operator *= (int k){//Scalar Multiplication
		int i,j;
		for (i=0;i<3;i++)
			for (j=0;j<3;j++)
				this->e[i][j] *= k;	
	}
};
	

int main(){
	srand(time(0));
	Matrix3x3 m1;
	m1.show();
	m1 *= 2
	cout << "----------------\n";
	m1.show();
	return 0;
}
