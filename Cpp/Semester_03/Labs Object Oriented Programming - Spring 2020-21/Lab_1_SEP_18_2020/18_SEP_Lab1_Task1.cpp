#include<iostream>
#include <cmath>
using namespace std;
int main(){
    int x,sum=0,i;
    cout<<"Enter the Number";
    cin>>x;
    if (x<1)
        cout << "Wrong Use Case";
    else
        for(i=1;i<=x;i++){
            cout<<pow(i,i)<<' ';
            sum=sum+(pow(i,i));}
        cout<<sum;
	return 0;
}

