#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int x;
	cout << "Enter Value:";
	cin >> x;
	if (x%2==0)
		cout << setw(5) << x << " is even\n";
	else
		cout << setw(5) << x << " is odd\n";
	return 0;
}
