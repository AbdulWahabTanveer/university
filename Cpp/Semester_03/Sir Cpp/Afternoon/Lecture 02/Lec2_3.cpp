#include <iostream>

using namespace std;

void initRandom(int *a[5], const int COLSIZE){
	for (int j=0;j<5;j++)
		for (int i=0;i<COLSIZE;i++)
			a[i][j] = rand() %100;
}
void printArray(int *a[5], const int COLSIZE){
	for (int j=0;j<5;j++){
		for (int i=0;i<COLSIZE;i++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}
int main(){  
	int *array[5],col_size, i;
	cout << "Enter Column Size:";
	cin >> col_size;
	for (i=0;i<5;i++)
		array[i] = new int[col_size];

	initRandom(array, col_size);
	printArray(array, col_size);

	for (i=0;i<5;i++)
		delete []array[i];
	return 0;
}
