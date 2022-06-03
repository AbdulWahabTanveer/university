#include <bits/stdc++.h>
using namespace std;

int H[100];
int size = -1;

int parent(int i){
	return (i - 1) / 2;
}

int leftChild(int i){
	return ((2 * i) + 1);
}

int rightChild(int i){
	return ((2 * i) + 2);
}


void shiftUp(int i){
	while (i > 0 && H[parent(i)] < H[i]) {

		swap(H[parent(i)], H[i]);

		i = parent(i);
	}
}


void insert(int Priority){
	size=size+1;
	H[size] = Priority;
	shiftUp(size);
	cout<<"Task with priority "<<Priority<<" is added\n";
}

int MaxPrior(){
	int result = H[0];


	H[0] = H[size];
	size = size - 1;

	return result;
}



int getMax(){

	return H[0];
}


void remove(int i){
	H[i] = H[0] + 1;

	shiftUp(i);

	MaxPrior();
}


int main(){

	insert(45);
	insert(20);
	insert(14);
	insert(12);
	insert(19);
	insert(7);
	insert(11);
	insert(13);
	insert(7);

	int i = 0;

	cout << "Priority Queue : ";
	while (i <= size) {
		cout << H[i] << " ";
		i++;
	}

	cout << "\n";


	cout << "Task with maximum priority : " << MaxPrior() << "\n";


	cout << "Priority queue after extracting maximum : ";
	i = 0;
	while (i <= size) {
		cout << H[i] << " ";
		i++;
	}

	cout << "\n";

	return 0;
}
