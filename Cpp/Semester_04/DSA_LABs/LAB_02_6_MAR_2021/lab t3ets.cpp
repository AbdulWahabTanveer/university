#include <iostream>

using namespace std;

int main(){
    
    int n;int center,oper,n1=0,n2=0;
    cin>>n;
    if(n%2==0)
        return 0;
    else center=(n/2)+1;
    
    cout<<center<<"center";

int ptr[n][n];

    int rangep=n-center;
    
    int rangen=-n+center;
  
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>ptr[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<ptr[i][j]<<' ';
    
    cout<<endl;}
    cin>>oper;
    
    for(int i=0;i<oper;i++){
       try{ cin>>n1;
           cout<<"n1 is"<<n1<<endl;
            if(n1>rangep||n1<rangen){
            throw 2;}
            cin>>n2;
           cout<<"n2 is"<<n2<<endl;
           if(n1>rangep||n1<rangen){
            throw 2;}
        n1=n1+center-1;
        n2=(-1*n2)+center-1;
        cout<<"n1 is now "<<n1<<endl;
           cout<<"n2 is now "<<n2<<endl;
        
         cout<<ptr[n1][n2]<<endl;}
        catch(const int i){
        cout<<"INVALID INPUT"<<endl;
        }
    
    }

    
    return 0;
}
