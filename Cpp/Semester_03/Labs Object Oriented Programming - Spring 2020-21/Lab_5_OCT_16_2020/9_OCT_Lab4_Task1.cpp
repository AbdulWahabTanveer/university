#include<iostream>
using namespace std;

class Player{
    
    int playerno,numberofMatches,*scores,*numberofplayers;
    char *status;
    
    int iningscounter() const{
        int i,count;
        for(i=0;i<numberofMatches;i++){
            if(status[i]=='O')
                count++;
        }
        return count;
    }
    public:

        void set(int numberofMatches,int *p){
            this->numberofMatches=numberofMatches;
            scores=new int[numberofMatches];
            status=new char[numberofMatches];
            numberofplayers=p;

        }
        void read(int number){
            for(int i=0;i<numberofMatches;i++){
                cin>>scores[i];
                cin>>status[i];}
        }
        int average() const{
            int score=0,i;
            for(i=0;i<numberofMatches;i++){
                score+=scores[i];
            }
            int average=score/iningscounter();
            return average;
        }
        void show(){
            cout<<"Player "<<numberofplayers<<" has played "<<numberofMatches
                <<" matches and "<<iningscounter()<<" innings";

        }
        void free(){
            delete []scores;
            delete []status;
        }

};

int main(){
    int first,second,third,numberofoperations,in,*pointer,i,nplay;
    int playerno;
    cin>>first>>second>>third;
    pointer=&nplay;
    nplay=3;

    Player p[10];//so that i can use it for repetition
    
    p[9].set(first,pointer);p[8].set(second,pointer);p[7].set(third,pointer);//first 3 default ones

    cin>>numberofoperations;
    int operation;
    for(i=0;i<numberofoperations;i++){
        cin>>operation;
        switch(operation){
            case 1:
                cin>>in;
                    p[in].average();
                    break;
            case 2:
                cin>>in;
                    p[in].show();
                    break;
            case 3:
                cout<<"Number of Players: "<<*pointer;
                break;
            case 4:
                cin>>in;
                    p[in].average();
                    break;
            case 5:
                cin>>in;
                        p[in].free();
                        nplay--;
                break;
            case 6:
                cin>>playerno>>in;
                    p[playerno].set(in,pointer);
                    nplay++;
                    break;
            case 7:
                cin>>playerno;
                p[playerno].set(playerno,pointer);
                break;
        }
    }
    return 0;
}