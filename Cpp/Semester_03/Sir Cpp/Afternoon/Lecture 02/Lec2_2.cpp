#include <iostream>

using namespace std;

void initRandom(int *a, const int SIZE){
	for (int i=0;i<SIZE;i++)
		a[i] = rand() %100;
}
void printArray(int *a, const int SIZE){
	for (int i=0;i<SIZE;i++)
		cout << a[i] << ' ';
	cout << '\n';
}
void insertionSort(int *a, const int SIZE){
	int temp, i, j;
	for (i=1;i<SIZE;i++){
		temp = a[i];
		for (j=i-1 ; j>=0 && a[j]>temp; j--)
			a[j+1] = a[j];
		a[j+1] = temp;
	}
}
int main(){
	int *array, size;
	cout << "Enter Size:";
	cin >> size;
	array = new int[size];
	initRandom(array, size);
	printArray(array, size);
	insertionSort(array, size);
	printArray(array, size);
	delete []array;
	return 0;
}
