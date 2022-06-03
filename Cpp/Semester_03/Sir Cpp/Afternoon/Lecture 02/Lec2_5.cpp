#include <iostream>

using namespace std;
				
void initRandom(int **a, const int ROWSIZE, const int COLSIZE){
	for (int j=0;j<ROWSIZE;j++)
		for (int i=0;i<COLSIZE;i++)
			a[j][i] = rand() %100;
}
void printArray(int **a, const int ROWSIZE, const int COLSIZE){
	for (int j=0;j<ROWSIZE;j++){
		for (int i=0;i<COLSIZE;i++)
			cout << a[j][i] << ' ';
		cout << '\n';
	}
}
//2D array with variable size rows & columns
//We need a 2D or double pointer
//We declare a 2D or double pointer using **
int main(){  
	int **array, row_size, col_size, i;
	cout << "Enter Row Size:";
	cin >> row_size;
	cout << "Enter Column Size:";
	cin >> col_size;
	array = new int* [row_size]; // int *array[5]
	for (i=0;i<row_size;i++)
		array[i] = new int[col_size];

	initRandom(array, row_size, col_size);
	printArray(array, row_size, col_size);

	for (i=0;i<row_size;i++)
		delete []array[i];
	delete []array;
	return 0;
}
