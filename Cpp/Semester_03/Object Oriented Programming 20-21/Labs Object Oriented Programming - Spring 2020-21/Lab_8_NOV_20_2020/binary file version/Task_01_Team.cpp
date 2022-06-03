#include <iostream>
#include <iomanip>
#include <string.h>
#include "Task_01.cpp"

class Team{
    Player *p;
    int total;
    int wickets;
public:
    Team(){
        p=new Player[11];
        cin>>total;
        cin>>wickets;
    }
    void readplayer(){
        int i=0;
      // for(int i=0;i<11;i++){
            cin>>p[i].Playername;
            cin>>p[i].numberofmathches ;
            cin>>p[i].scoremax ;
            cin>>p[i].centuries ;
            cin>>p[i].fifties ;
            cin>>p[i].playernumber ;
            }
      //h }
    
    int higestscore(){
        int max=p[0].scoremax,no=0,i;
        for(i=1;i<11;i++){
            if(max<p[i].scoremax){
                max=p[i].scoremax;
                no=i;
            }
        }
        return no;
    }
    int mostcenturies(){
        int max=p[0].centuries,no=0,i;
        for(i=1;i<11;i++){
            if(max<p[i].centuries){
                max=p[i].centuries;
                no=i;
            }
            else if(max==p[i].centuries && p[no].fifties<p[i].fifties){
                max=p[i].centuries;
                no=i;
            }
        }
        return no;
    }
    friend ostream& operator << (ostream &out, const Team &t);
    friend class Match;
};
ostream& operator << (ostream &out, const Team &t){
    for(int i=0;i<11;i++){
                out<<t.p[i];
                }
    out<<"\n\n";
    out<<"Wickets: "<<t.wickets<<'\n';
    out<<"Total: "<<t.total<<"\n\n";
    return out;
}
