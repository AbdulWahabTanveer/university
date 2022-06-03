#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<ctime>

using namespace std;
//Incomplete code of Complex class
#define RND1 rand()%10-5
#define RND2 (rand()%10+1)

class Painting
{
    protected:
    string title, artist;
    int value;
    public:
    Painting(string title="",string artist=""){
    this-> title=title;
    this-> artist=artist;
    value=400;
    }
    void set(string title,string artist){
        this-> title=title;
        this-> artist=artist;
    }
    void show(){
        cout<<*this;
    }
    friend ostream& operator <<(ostream& out,const Painting &p);
};
ostream& operator <<(ostream& out,const Painting &p){
        out<<"Title: "<<p.title<<"\n";
        out<<"Artist: "<<p.artist<<"\n";
        out<<"Value: "<<p.value<<"\n";
        return out;
}
class FamousPainting:public Painting{
    public:
    FamousPainting():Painting(title,artist){
        value=25000;
    }
};
int main(){
    Painting *p[10];
    string d1,d2;
    for(int i=0;i<10;i++){
        cout<<"Enter Title: ";
        getline(cin,d2);
        cout<<"Enter Artist: ";
        getline(cin,d1);
        if(d1.compare("Degas")==0||d1.compare("Monet")==0||d1.compare("Picasso")==0||d1.compare("Rembrandt")==0)
           {p[i]= new FamousPainting[1];
            p[i]->set(d2,d1);}
        else
            {p[i]=new Painting[1];
             p[i]->set(d2,d1);}  
    }
    for(int i=0;i<10;i++)
        p[i]->show();
    return 0;
}

