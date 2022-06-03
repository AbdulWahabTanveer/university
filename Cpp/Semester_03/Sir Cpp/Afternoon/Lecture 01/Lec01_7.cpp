#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int x;
	for (x=1;x<=20;x++)
		cout << "X:" << setw(3) << x << '\n';
	return 0;
}
