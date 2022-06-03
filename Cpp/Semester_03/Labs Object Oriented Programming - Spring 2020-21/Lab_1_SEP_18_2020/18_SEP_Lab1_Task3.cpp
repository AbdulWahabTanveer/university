#include<iostream>
#include <cmath>
using namespace std;
int main(){
    int in,count1=1,i,j;
    cin>>in;
    for(i=in;i>0;i--){

        for(j=0;j<i;j++){
         cout<<count1;
         if(j!=i-1)
         cout<<' ';
         count1++;
        }
    cout<<'\n';
    }
    return 0;
}

