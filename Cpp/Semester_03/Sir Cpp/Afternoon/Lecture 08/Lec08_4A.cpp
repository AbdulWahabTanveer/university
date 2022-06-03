#include <iostream>
#include <ctime>

using namespace std;
class Matrix{
	int rows, cols, **e;
public:
	Matrix (int r=3, int c=4){//default values of parameter
		rows = r , cols = c;
		e = new int* [rows];
		for (int i=0;i<rows;i++)
			e [i] = new int [cols];
		initRandom();
	}
	Matrix (const Matrix &m){
		int i,j;
		cout << "Copy Constructor Called\n";
		rows = m.rows , cols = m.cols;
		e = new int* [rows];
		for (i=0;i<rows;i++){
			e [i] = new int [cols];
			for (j=0;j<cols;j++)
				e[i][j] = m.e[i][j];
		}
	}	
	void initRandom(){
		int i, j;
		for (i=0;i<rows;i++)
			for (j=0;j<cols;j++)
				e[i][j] = rand() % 10;
	}
	void show() const{
		int i, j;
		for (i=0;i<rows;i++){
			for (j=0;j<cols;j++)
				cout << e[i][j] << ' ';
			cout << '\n';
		}
	}
};
		

int main(){
	srand(time(0));
	Matrix m1, m2(4,5);
	m1.show();
	cout<<"---------------\n";
	m2.show();
	cout<<"---------------\n";
	m2 = m1; 
	m2.show();
	return 0;
}
