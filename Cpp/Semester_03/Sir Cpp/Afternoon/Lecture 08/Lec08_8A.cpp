#include <iostream>
#include <ctime>

using namespace std;
class Matrix{
	int rows, cols, **e;
	void copy(const Matrix &m){
		//Copy constructor is called for new object
		int i,j;
		rows = m.rows , cols = m.cols;
		e = new int* [rows];
		for (i=0;i<rows;i++){
			e [i] = new int [cols];
			for (j=0;j<cols;j++)
				e[i][j] = m.e[i][j];
		}
	}
	void freeMemory(){
		for (int i=0;i<rows;i++)
			delete []e[i];	
		delete []e;
	}
public:
	Matrix (int r=3, int c=4){//default values of parameter
		rows = r , cols = c;
		e = new int* [rows];
		for (int i=0;i<rows;i++)
			e [i] = new int [cols];
		initRandom();
	}
	Matrix (const Matrix &m){
		copy(m);
	}	
	void operator = (const Matrix &m){
		//Assignment operator is called for existing object		
		freeMemory();	
		copy(m);
	}
	void initRandom(){
		int i, j;
		for (i=0;i<rows;i++)
			for (j=0;j<cols;j++)
				e[i][j] = rand() % 10;
	}
	void setValue(int i, int j, int newValue){
		if (i>=0 && i<rows && j>=0 && j<cols)
			e[i][j] = newValue;
	}
	void show() const{
		int i, j;
		for (i=0;i<rows;i++){
			for (j=0;j<cols;j++)
				cout << e[i][j] << ' ';
			cout << '\n';
		}
	}
	~Matrix(){
		freeMemory();
	}
};
	

int main(){
	srand(time(0));
	Matrix m1, m2(4,5);
	m1.show();
	cout<<"---------------\n";
	m2 = m1; //shallow copy
	m2.show();
	cout<<"---------------\n";
	m1.setValue(0,0,20);
	m2.setValue(1,1,30);
	m1.show();
	cout<<"---------------\n";
	m2.show();
	return 0;
}
