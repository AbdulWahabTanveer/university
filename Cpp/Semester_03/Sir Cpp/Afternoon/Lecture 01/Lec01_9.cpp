#include <iostream>

using namespace std;

int main(){
	int x, y;
	cout << "Enter Two Values Separated With Space:";
	cin >> x >> y;
	if (x > y)
		cout << x << " is greater than " << y << '\n';
	else if (y > x)
		cout << y << " is greater than " << x << '\n';
	else
		cout << x << " and " << y << " are equal\n";
	return 0;
}
