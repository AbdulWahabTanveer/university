#include <iostream>

using namespace std;

int main(){
    
    int n;int center,oper,n1=0,n2=0;
    cin>>n;//5
    if(n%2==0)
        return 0;
    else center=(n/2)+1;

int ptr[n][n];

    int rangep=n-center;//allowed values 2
    int rangen=-n+center;//negative
  
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>ptr[i][j];
    cin>>oper;
    
    for(int i=0;i<oper;i++){
       try{ cin>>n1;
            cin>>n2;
           if(n1>rangep||n1<rangen||n2>rangep||n2<rangen){
            throw 2;}
            
        n1=n1+center-1;
        n2=(-n2)+center-1;
        
        cout<<ptr[n2][n1]<<endl;}
        catch(const int i){
        cout<<"INVALID INPUT"<<endl;
        }
    
    }

    
    return 0;
}