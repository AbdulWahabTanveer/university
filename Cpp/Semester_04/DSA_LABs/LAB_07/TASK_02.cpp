#include<iostream>
#include "Stack.cpp"

using namespace std;


int find_smallest_divisor(int start,int num){
    for(int i=start;i<5000;i++){
        if(num%i==0)
            return i;
    }
    return -99999;
}

void find_divisor(int num){
        if(find_smallest_divisor(2,num)==num || num==2 ||find_smallest_divisor(2,num)==-99999 ){
            return;
        }
        else{
        int div=find_smallest_divisor(2,num);
        cout<<"Divisor of "<<num<<": "<<div;
        if(num/div!=div)
            cout<<','<<num/div<<endl;
        else 
            cout<<endl;
        find_divisor(num/div);
        return;
        }
}


int main(){
    cout<<"First Check"<<endl;
    find_divisor(16);
    cout<<endl<<"Next Check"<<endl;
    find_divisor(64);
    cout<<endl<<"Next Check"<<endl;
    find_divisor(49);
    cout<<endl<<"Next Check"<<endl;
    find_divisor(56);
    cout<<endl<<"Next Check Nothing will be primted for a prime number"<<endl<<endl;
    find_divisor(7);
    return 0;
}