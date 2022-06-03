#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<ctime>

using namespace std;

class Room{
    float length,width,height;
    friend ostream& operator <<(ostream& out,const Room &r);

    public:
    Room(float length=0.0,float width=0.0,float height=0.0){
        this->length=length;
        this->width=width;
        this->height=height;
    }
     float calcarea()const{
        return length*width;
    }
     float calcvol()const{
        return length*width*height;
    }
    void set_room(float length,float width,float height){
        this->length=length;
        this->width=width;
        this->height=height;
    }
};
ostream& operator <<(ostream& out,const Room &r){
    out<<"\n\nRoom length "<<r.length;
    out<<"\nRoom Width "<<r.width;
    out<<"\nRoom Height "<<r.height;
    return out;
}
class house{
    Room *r;
    int count;
    void copy(int count){

        r=new Room[count];
        this->count=count;
    }
    public:
        house(int count){
            copy(count);
        }
        float total_area(){
            float sum=0;
            for(int i=0;i<count;i++)
                sum+=r[i].calcarea();
            return sum;
        }
        float total_vol(){
            float sum=0;
            for(int i=0;i<count;i++)
                sum+=r[i].calcvol();
            return sum;
        }
        void total_rooms(){
            cout<<"\nTotals Rooms are: "<<count;
        }
        void room_setter(float length,float width,float height,int index){
            r[index].set_room(length,width,height);
        }
        void room_show(int i){
            cout<<r[i];
        }
};
int main(){ 
    house h(5);

    h.total_rooms();

    h.room_setter(5,555.43,8912.33,0);
    h.room_setter(53.42,555.43,832.343,3);
    h.room_setter(7.2144,123.43,123.3213,2);

    h.room_show(0);
    h.room_show(3);

    cout<<"\n\nTotal Area is: "<<h.total_area();
    cout<<"\nTotal Volume is: "<<h.total_vol()<<"\n\n";

    return 0;
}