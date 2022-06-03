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
        ifstream in("input",ios::binary);
        static 
        p=new Player[11];
    }
    void set(int total,int wickets){
        this->total=total;
        this->wickets=wickets;
    }
    void readplayer(){
        fstream io("read",ios::binary);
        int i=0;
        char a[20];
        io.seekg(48,ios::beg);
 
       for(int i=0;i<11;i++){
            io.read(a,sizeof(char)*20);
            strcopy(p[i].Playername,a);
            io.read(char*(&p[i].numberofmathches),sizeof(int));
            io.read(char*(&p[i].scoremax),sizeof(int)) ;
            io.read(char*(&p[i].centuries),sizeof(int)) ;
            io.read(char*(&p[i].fifties),sizeof(int)) ;
            io.read(char*(&p[i].playernumber),sizeof(int)) ;
            }
       }
    
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
