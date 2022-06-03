#include <iostream>
#include "Stack.cpp"

using namespace std;

static Stack <int> S(25);
int static arr[25];
int static count=0;

bool checkexist(int num){
    for(int i=0;i<count;i++){
        if(arr[i]==num)
            return true;
    }
    return false;
}

void print(int num,int p1,int p2){
    cout<<num<<": "<<p1<<" + "<<p2<<endl;
} 

void into_parts(int num,int &p1,int &p2){
    if(num%2==0){
            p1=p2=num/2;
        }
        else{
            p1=p2=num/2;
            p1++;
        }
}

void additive_divide(int num){ 
   int p1,p2;


    while(num!=2&&num!=1){
        arr[count++]=num;
        into_parts(num,p1,p2);
        print(num,p1,p2);
        num=p1;
        S.push(p2);
    }
    while(!S.isEmpty()){
        if(checkexist(S.seeTop())){
            S.pop();
            continue;
        }
        num=S.seeTop();
        S.pop();
        while(num!=2&&num!=1){
            if(checkexist(num)){
                break;
            }
            arr[count++]=num;
            into_parts(num,p1,p2);
            print(num,p1,p2);
            num=p1;
            S.push(p2);
        }
    }
}

int main(){
    
   additive_divide(37);
   cout<<endl<<"next check"<<endl;
   additive_divide(32);
   cout<<endl<<"next check"<<endl;
   additive_divide(56);


    return 0;
}