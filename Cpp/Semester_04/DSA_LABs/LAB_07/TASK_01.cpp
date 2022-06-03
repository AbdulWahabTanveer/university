#include<iostream>
#include "Stack.cpp"

using namespace std;
int static countofdivide=0;

void check_arrays(int arr[],int size){
        Stack <int> s,s2;
        for (int i=0;i<size-1;i++){
            s.push(arr[i]);
            if(arr[i]==-1)
                countofdivide++;
        }
        for (int i=0;i<countofdivide;i++){
            while(s.seeTop()!=-1){
                s2.push(s.seeTop());
                s.pop();
            }
            if(s.seeTop()==-1){
                s.pop();
                while(!s2.isEmpty()){
                    cout<<s2.seeTop()<<' ';
                    s2.pop();
                }
                cout<<endl;
            }
        }
    cout<<endl;
}


int main(){
    int arr[]={-1 ,23 ,59 ,37 ,-1 ,46 ,64 ,-1,};
    check_arrays(arr,8);
    return 0;
}