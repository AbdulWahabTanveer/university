#include <iostream>

using namespace std;int n1=0;


bool bank_hack(int n){
    if(n==1){
        return true;
    }
    if(n==10||n==20){
        return true;
    }
    else if(n%10!=0 && n%20!=0){
        return false;
    }
    else{
        if(n%10!=0 && n%20==0){
            n=n/20;
            return bank_hack(n);
        }
        else if(n%10==0 && n%20!=0){
            n=n/10;
            return bank_hack(n);
        }
        else if(n%10==0 && n%20==0){
          
            n1=n;
            while(n1>=10){
                n1=n1/10;
            }
            if(n1==1){n=n/10;return bank_hack(n);}
            else{n=n/20;return bank_hack(n);}
            }
            if(n<200){
            n=n/10;
            return bank_hack(n);
            }
            if(n<200&&n!=100){
                return false;
            }

        }
    return false;}
    

int main(){
    
    int n;int times;
    cin>>times;

    for(int i=0;i<times;i++){
        cin>>n;
        if(bank_hack(n)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    

    return 0;
}