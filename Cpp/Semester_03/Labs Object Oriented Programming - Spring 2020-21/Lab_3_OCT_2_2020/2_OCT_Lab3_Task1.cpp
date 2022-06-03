#include<iostream>
using namespace std;


class Address{
	int houseNo;//1-8

	char floor;//a-d

	char block;//A-J

	public:
	Address(int hn,char fl,char bl){
        floor=fl;
        block=bl;
        houseNo=hn;
	}
	void setFloor(char f){
        floor=f;
	}
	char getFloor(){ return floor;}
	char getBlock(){ return block;}
	int getHouseNo(){ return houseNo;}
	bool hasUpperFloor(Address a2){

        if(int(floor)<int(a2.floor))
            return false;
        else
            return true;
	}
	bool isSameBlock(const Address a2) const{
        if(block==a2.block)
            return true;
        else
            return false;
	}
	void show() const{
		cout<<"House No:"<<houseNo<<"\n";
        cout<<"Floor:"<<floor<<"\n";
        cout<<"Block:"<<block<<"\n";
        cout<<"------------\n";
	}
};

int main(){

int h; char f, b;

cin>>h>>f>>b;

Address a1(h, f, b);

cin>>h>>f>>b;

Address a2(h, f, b);

a1.show();

a2.show();

if (a1.isSameBlock(a2))

    cout<<"has same block\n";

else

    cout<<"has different block\n";

cin>>f;

a1.setFloor(f);

if (a1.hasUpperFloor(a2))

    cout<<"has upper floor\n";

else

    cout<<"has same or lower floor\n";

a2.setFloor('c');

cout<<"A2 has floor:"<<a2.getFloor()<<'\n';

cout<<"Block:"<<a2.getBlock()<<'\n';

cout<<"House no:"<<a1.getHouseNo()<<'\n';

return 0;
}
