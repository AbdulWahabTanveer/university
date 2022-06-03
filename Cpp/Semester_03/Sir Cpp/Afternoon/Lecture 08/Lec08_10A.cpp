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
	Matrix (int rows=3, int cols=4){//default values of parameter
		this->rows = rows , this->cols = cols;
		e = new int* [rows];
		for (int i=0;i<rows;i++)
			e [i] = new int [cols];
		initRandom();
	}
	Matrix (const Matrix &m){
		copy(m);
	}	
	Matrix operator = (const Matrix &m){
		//Assignment operator is called for existing object		
		freeMemory();	
		copy(m);
		return *this;//to return current object
	}
	void initRandom(){
		int i, j;
		for (i=0;i<rows;i++)
			for (j=0;j<cols;j++)
				this->e[i][j] = rand() % 10;
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
//This pointer
//exit by default in every class and points to current object
//this pointer is used in member functions to access data members of current object, if
//data members and local variables have same name

//this pointer is used to access current object for passing to some function or returning from
//member function

int main(){
	srand(time(0));
	Matrix m1, m2(4,5), m3;
	m1.show();
	cout<<"---------------\n";
	m3 = m2 = m1;
	cout<<"---------------\n";
	m2.show();
	cout<<"---------------\n";
	m3.show();
	return 0;
}
