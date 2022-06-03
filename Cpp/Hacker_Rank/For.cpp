#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n1,n2,n;
    cin >> n1>>n2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for(n=n1;n<=n2;n++){
    if(n==1)
        cout<<"one\n";
    else if(n==2)
        cout<<"two\n";
    else if(n==3)
        cout<<"three\n";
    else if(n==4)
        cout<<"four\n";
    else if(n==5)
        cout<<"five\n";
    else if(n==6)
        cout<<"six\n";
    else if(n==7)
        cout<<"seven\n";
    else if(n==8)
        cout<<"eight\n";
    else if(n==9)
        cout<<"nine\n";
    else if (n%2==0) 
        cout<<"even\n";
    else cout<<"odd\n";}
    return 0;
}

