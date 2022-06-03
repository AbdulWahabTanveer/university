#include <iostream>
#include <cmath>
#include<vector>
#include<iterator>
using namespace std;

static int CounT=0;

int* vecprime=new int[100];

void primeFactors(int n)
{
     int i;
     double total = n*(n);

     for (i = 2; i <= total; i++)
         while (n % i == 0) {   
		    vecprime[CounT++]=i;    
            primeFactors(n /= i); 
            return;              
	    }
}



int main() 
{
    int n = 0,sum=1,n1;
    int count1 = 0;
    cin >> n1;
    primeFactors(n1);
    n=vecprime[0];
    cout<<vecprime[0]<<' ';
    for(int i=0 ;i <= CounT ; i++){
            if(vecprime[i]==n){
                count1++;
                continue;}
            else {cout<<count1<<' ';count1=1;}
            n=vecprime[i];
            if(i!=CounT)
            cout<<vecprime[i]<<' ';
        }
    for(int i=0 ;i < CounT ; i++){
            sum*=vecprime[i];
        }
    if(sum!=n1)  cout<<n1-sum;

     
  
    return 0;
}