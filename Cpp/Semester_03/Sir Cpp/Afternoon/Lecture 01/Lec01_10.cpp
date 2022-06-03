#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int *x, i, count;
	cout << "Enter No of Values:";
	cin >> count;
	
	x = new int[count]; //alternate of malloc

	for (i=0;i<count;i++){
		x[i] = rand()%100;
		cout<< setw(4)  << x[i] << '\n';
	}

	delete []x ;	//alternate free
	return 0;
}
