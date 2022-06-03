#include <iostream>

using namespace std;

int main(){
    
    int n;int center,oper=0,sum=0;
    
    cin>>n;
    int value[n];

    for(int i=0;i<n;i++){
            cin>>value[i];
            sum+=value[i];
        }

    return 0;
}