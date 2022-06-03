#include<iostream>
using namespace std;
int main(){
    cout<<"Enter the Size of Array: ";
    int x;
    cin>> x;
    int i,j,temp,arr[x];
    cout<<"Enter "<<x<< " Numbers:\n";
    for(i=0;i<x;i++){
        cin>>arr[i];
    }
    cout<<"Entered Numbers Are: ";
    for(i=0;i<x;i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    for(i=1;i<x;i++){
        temp=arr[i];
        for(j=i-1;j>=0 && arr[j]>temp;j--)
            arr[j+1]=arr[j];
        arr[j+1]=temp;
    }
    cout<<"\nSorted Array is: ";
    for(i=0;i<x;i++){
        cout<<arr[i]<<' ';
    }
    cout<<"\n";
    return 0;
}
