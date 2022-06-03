#include <iostream>
#include <iomanip>
#include <string.h>
#include "Task_01_Team.cpp"
#define Teamcount 6
class Match{
    Team *t;
    public:
    Match(){
        t=new Team[Teamcount];
    }
    int compare(){
        int max=t[0].total,no=0,i;
        for(i=1;i<Teamcount;i++){
            if(max<t[i].total){
                max=t[i].total;
                no=i;
            }
            else if(max==t[i].total && t[no].wickets>t[i].wickets){
                max=t[i].total;
                no=i;
            }
        }
        return no;
    }
    friend int main();
};


int main(){
    Match M;

    fstream io("Read",ios::binary);
    int arr[12];
    io.read(char*(arr),sizeof(int)*12);
    
    for(int i=0;i<Teamcount;i++){
        M.t[i].set(a[i],a[++i]);
    }
    //sets total and wickets from binary file in format
    //total wickets without spaces in binary


    

    
    for(int i=0;i<Teamcount;i++){

        M.t[i].readplayer();
    }
    int win=M.compare();
    cout<<M.t[win];
    return 0;
}