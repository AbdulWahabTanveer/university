#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
class Flower_Pack{
	string fname;
	string gift;
	int price;
	string color;
public:
	Flower_Pack(){
	}
	Flower_Pack(string fname, string gift, string color, int price){
        	this->fname=fname;
        	this->gift=gift;
        	this->color=color;
        	this->price = price;
    	}
	void SetFlowerPack(string fname, string gift, string color, int price){
	        this->fname=fname;
	        this->gift=gift;
	        this->color=color;
	        this->price = price;
	}
friend ostream& operator << (ostream &out,const Flower_Pack &f);
friend istream& operator >> (istream &in, Flower_Pack &f);
};
ostream& operator << (ostream &out,const Flower_Pack &f){
        out<<setw(15)<<left<<f.fname<<setw(15)<<left<<f.gift<<setw(15)<<left<<f.color<<setw(15)<<left<<f.price<<"\n";
        return out;
}
istream& operator >> (istream &in, Flower_Pack &f){
        cout<<"Flower Name:";
        in>>f.fname;
        cout<<"  gift:";
        in>>f.gift;
        cout<<"  Color:";
        in>>f.color;
        cout<<"  price:";
        in>>f.price;
        return in;
}

class Florist{
	Flower_Pack pack;
	string order_taker;
public:
	Florist(){
	}
	Florist(string order_taker,string fname, string gift, string color, int price){
	this->order_taker=order_taker;
	pack.SetFlowerPack(fname,gift,color,price);
	}
	void set(string order_taker,string fname, string gift, string color, int price){
        	pack.SetFlowerPack(fname,gift,color,price);
        	this->order_taker = order_taker;
    	}
friend void choices();
friend istream& operator >> (istream &in, Florist &ft);
friend ostream& operator << (ostream &out, const Florist &ft);
};

istream& operator >> (istream &in, Florist &ft){
	cout<<"Order Taker's Name: ";
	in>>ft.order_taker;
	in>>ft.pack;
	return in;
}
ostream& operator << (ostream &out, const Florist &ft){
	out<<setw(15)<<left<<ft.order_taker;
	out<<ft.pack;
	return out;
}

int main(){
	Florist f[5];
	string order_taker[5]={"Ali","Ben","Charlie","Daniel","Elen"};
	string fname[5]={"Lily","Abmber","Blush","Sunflower","Jasmine"};
	string color[5]={"Red","Blue","Purple","Blush","Indigo"};
	string gift[5] = {"Chocolate","Headband","Bangles","Flower Pot","Rings"};
	int price[5]={200,150,97,120,300};
	for(int i=0;i<5;i++){
        	f[i].set(order_taker[i],fname[i],gift[i],color[i],price[i]);
        }
	ofstream file1;
	file1.open("florist.bin",ios::in | ios::app | ios::binary);
	file1.write((char*)f,sizeof(Florist)*5);
	file1.close();

    	Florist ft[5];
        ifstream file;
        file.open("florist.bin",ios::binary | ios::out);
        file.read((char*)ft,sizeof(Florist)*5);
    int choice;
    do{
        cout<<"Press 0 to end the program\n";
        cout<<"Press 1 to show all the records\n";
        cout<<"Press 2 to modify an existing record\n";
        cout<<"Press 3 to add a new record\n";
        cout<<"Press 4 to search an existing record\n\n";
        cin >> choice;
        switch(choice){
        case 0:
            cout<<"\tThanks for using this program\n";
            break;
        case 1:
            cout<<"\n\t\tBlossom House\n";
            for(int i=0;i<5;i++)
                cout<<ft[i];
            file.close();
            cout<<"\n\n";
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:

            break;

        }

    }while(choice!=0);

	return 0;
}