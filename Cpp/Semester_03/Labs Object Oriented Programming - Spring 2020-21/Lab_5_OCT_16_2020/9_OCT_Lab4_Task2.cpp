#include<iostream>
#include<iomanip>
using namespace std;

class Time{

    int hrs,mins,secs;//5-15, default is 10
    char zone;

    public:
    Time(){
        hrs=1;
        mins=0;
        secs=0;
    }
  
    void set(char Zone){
        zone=Zone;
    }
    void set(char Zone,int hours_in){
        zone=Zone;
        if(hours_in>12)
        hrs=1;
        else if(hours_in<1)
        hrs=1;
        else{
            hrs=hours_in;
        }
    }
    void set(char Zone,int hours_in,int mins_in){
        zone=Zone;
        if(hours_in>12)
        hrs=1;
        else if(hours_in<0)
        hrs=1;
        else{
            hrs=hours_in;
        }
        if(mins_in>59)
        mins=0;
        else if(mins_in<0)
        mins=0;
        else{
            mins=mins_in;
        }
    }
    void set(char Zone,int hours_in,int mins_in,int secs_in){
        zone=Zone;
        if(hours_in>12)
        hrs=1;
        else if(hours_in<1)
        hrs=1;
        else{
            hrs=hours_in;
        }
        if(mins_in>59)
        mins=0;
        else if(mins_in<0)
        mins=0;
        else{
            mins=mins_in;
        }
        if(secs_in>59)
        secs=0;
        else if(secs_in<0)
        secs=0;
        else{
            secs=secs_in;
        }
        
    }
    void add(int number,int value){
    switch(number){
            case 1:
                if(hrs+value>12){
                    hrs=hrs+value-12;
                    if(zone=='A')
                        zone='P';
                    else if(zone=='P')
                        zone='A';
                }
                else
                {
                    hrs=hrs+value;
                }
                break;

            case 2:
                if(mins+value>59){
                    mins=mins+value-60;
                    if(hrs+1>12){
                    hrs=hrs+1-12;
                    if(zone=='A')
                        zone='P';
                    else if(zone=='P')
                        zone='A';}
                    else hrs++;
                }
                else
                {
                    mins=mins+value;
                }
                break;
            case 3:
                if(secs+value>59){
                    secs=secs+value-60;
                    mins++;
                }
                else
                {
                    secs=secs+value;
                }
                break;
        }
    }
    void show() const{
    cout<<hrs<<':'
        << setw(2) << setfill('0') <<mins<<':'
        << setw(2) << setfill('0') <<secs<<' '
        <<zone<<'M'
        <<"\n";
    }
};

int main(){

    Time t1,t2,t3,t4;
    Time c[4];
    char z;
    int j,i,h,m,s,num,val,object,number,count=0;
    for(i=0;i<4;i++){
    cin>>j;
        switch(j){
            case 4:
                cin>>z>>h>>m>>s;
                t1.set(z,h,m,s);
                t1.show();
                c[count++]=t1;
                break;
            case 3:
                cin>>z>>h>>m;
                t2.set(z,h,m);
                t2.show();
                c[count++]=t2;
                break;
            case 2:
                cin>>z>>h;
                t3.set(z,h);
                t3.show();
                c[count++]=t3;
                break;
            case 1:
                cin>>z;
                t4.set(z);
                t4.show();
                c[count++]=t4;
                break;
        }
    }
    
 
    cin>>num;
    for(i=0;i<num;i++){
        cin>>object;
        switch (object)
        {
        case 1:
            cin>>number>>val;
            t1.add(number,val);
            t1.show();
            break;
        
        case 2:
            cin>>number>>val;
            t2.add(number,val);
            t2.show();
            break;
        case 3:
            cin>>number>>val;
            t3.add(number,val);
            t3.show();
            break;
        case 4:
            cin>>number>>val;
            t4.add(number,val);
            t4.show();
            break;
        }
    }
    
    return 0;


}