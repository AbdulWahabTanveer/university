#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
class Flower_Pack{
public:
	string fname;
	string gift;
	int price;
	string color;
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
        cout<<"gift:";
        in>>f.gift;
        cout<<"Color:";
        in>>f.color;
        cout<<"price:";
        in>>f.price;
        return in;
}


class Florist{
	Flower_Pack pack;
	static int count;
	string order_taker;
public:
	Florist(){
	    count++;
	}
	Florist(string order_taker,string fname, string gift, string color, int price){
	this->order_taker=order_taker;
	pack.SetFlowerPack(fname,gift,color,price);
	}
	void set(string order_taker,string fname, string gift, string color, int price){
        	pack.SetFlowerPack(fname,gift,color,price);
        	this->order_taker = order_taker;
    }
    void setFlower(string fname){
        this->pack.fname = fname;
    }
    void setGift(string gift){
        this->pack.gift = gift;
    }
    void setColor(string color){
        this->pack.color = color;
    }
    void setPrice(int price){
        this->pack.price = price;
    }
    string get_order_taker(){
        return order_taker;
    }
    string getFlowerName(){
        return pack.fname;
    }
    string getGift(){
        return pack.gift;
    }
    string getColor(){
        return pack.color;
    }
    int getPrice(){
        return pack.price;
    }
    int get_count(){
        return count;
    }
    ~Florist(){
        count--;
    }
friend void choices();
friend istream& operator >> (istream &in, Florist &ft);
friend ostream& operator << (ostream &out, const Florist &ft);
};
int Florist::count = 0;
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

void choices(){
    cout<<"Press 0 to end the records\n";
    cout<<"Press 1 to show all the orders made yet in our new shop\n";
    cout<<"Press 2 to modify any entity in an existing record\n";
    cout<<"Press 3 to add a new order\n";
    cout<<"Press 4 to search an existing record\n";
    cout<<"Press 5 to show the number of records\n";
}
void case1(Florist *ft,int csize){
    cout<<"\n\t\tWELCOME TO BLOSSOM HOUSE\n\n";
    for(int i=0;i<csize;i++)
        cout<<ft[i];
    cout<<"\n\n";
}
void case2(Florist *ft){
    int n,i,Price;
    string flower,Gift,Color;
    cout<<"Enter the no of record you want to modify:";
    cin>>n;
    n--;
    cout<<ft[n];
    cout<<"\nWhich entity do you want to modify?\n";
    cout<<"Press 1 to change the flower type\n";
    cout<<"Press 2 to change the gift in the pack\n";
    cout<<"Press 3 to change the color of gift wrapper\n";
    cout<<"Press 4 to edit the price of the pack\n";
    cin>>i;
    switch(i){
    case 1:
        cin>>flower;
        ft[n].setFlower(flower);
        break;
    case 2:
        cin>>Gift;
        ft[n].setGift(Gift);
        break;
    case 3:
        cin>>Color;
        ft[n].setColor(Color);
        break;
    case 4:
        cin>>Price;
        ft[n].setPrice(Price);
        break;
    }
}
void case4(Florist *ft, int csize){
    int i,Price;
    string name,flower,Gift,Color;
    cout<<"Press 1 to search a record by order taker's name\n";
    cout<<"Press 2 to search a record by flower type\n";
    cout<<"Press 3 to search a record by gift type\n";
    cout<<"Press 4 to search records by wrapping sheet color\n";
    cout<<"Press 5 to search records by price\n";
    cin>>i;
    switch(i){
    case 1:
        cin>>name;
        for(i=0;i<csize;i++){
            if(ft[i].get_order_taker()==name)
                cout<<ft[i];
        }
        break;
    case 2:
        cin>>flower;
        for(i=0;i<csize;i++){
            if(ft[i].getFlowerName()==flower)
                cout<<ft[i];
        }
        break;
    case 3:
        cin>>Gift;
        for(i=0;i<csize;i++){
            if(ft[i].getGift()==Gift)
                cout<<ft[i];
        }
        break;
    case 4:
        cin>>Color;
        for(i=0;i<csize;i++){
            if(ft[i].getColor()==Color)
                cout<<ft[i];
        }
        break;
    case 5:
        cin>>Price;
        for(i=0;i<csize;i++){
            if(ft[i].getPrice()==Price)
                cout<<ft[i];
        }
        break;
    }
}
int main(){
    int size = 51,csize = 0;
	Florist *f = new Florist [size];
	string order_taker[size]={"ANNIE","ALI","BRUCE","BEN","KATASHI","JERRY","MARY","REM","ASH","DANIEL","PICO","ELEN","ROBERT","MICHAEL","REM","WILLIAM","RICHARD","Thomas","CHARLES","MIKASA","ASH","JOSHUA","KEVIN","JOSEPH","BRIAN","KEVIN","ALI","MIKASA","AMAN","MARY","EMMA","JESICA","KATHERINE","SYRA","HELEN","ERI","KATSUKI","HANAKO","SELENA","TAYLOR","REI","YUKI","LEVI","TODOROKI","JASON","HELEN","JOSHUA","MICHAEL","AIMAN","MAHAM","LAILA"};
	string fname[size]={"ACONITE","AMARYLLIS","ANGELICA","BELLFLOWER","BUTTERCUP","BALSAM","BEGONIA","CALENDULA","CARNATION","COLUMBINE","COSMOS","DAFFODIL","DAISY","DAHLIA","FENNEL","GAILLARDIA","GARDENIAS","GARDENIAS","GAZANIA","GEUM","HIBUSCUS","HYDRANGEA","HEPATICA","HYACINTH","IMPATIENS","IRIS","LANTANA","LAVENDER","LILY","LEADWORT","LISIANTHUS","MARIGOLD","MOONFLOWER","MIRABILIS","NASTURTIUM","ORCHID","OSTEOSPERMUM","PANSY","PENTAS","PERIWINKLE","RANUNCULUS","RHODODENDRON","ROSE","SNAPDRAGON","SUNFLOWER","TANSY","TULIP","VERBENA","VIOLET","WISTERIA","ZINNIA"};
	string color[size]={"RED","BLUE","PURPLE","BLUSH","INDIGO","MAGENTA","VIOLET","BROWN","LIME","PINK","VIOLET","PLUM","AMBER","BLUE","EMERALD","ORANGE","ORCHID","CYAN","MAGENTA","PEACH","GREEN","GOLD","SILVER","COPPER","JADE","BLUSH","TURQUOISE","PINK","RED","GREEN","YELLOW","PURPLE","INDIGO","BROWN","PEACH","VIOLET","GRAY","WHITE","SCARLET","LIME","GREEN","EMERALD","CORAL","GOLD","BLUSH","AMBER","LILAC","LIME","PINK","RED","BLACK","PURPLE"};
	string gift[size] = {"CHOCOLATES","HEADBAND","BANGLES","FLOWER POT","RINGS","LIPSTICK","PERFUME","FLORAL CROWN","CHOCOLATES","WALLET","TEDDY BEAR","COOKIES","TEDDY BEAR","NECKLACE","COLORING BOOK","COOKIES","EARRINGS","RUG","WREATH","HAT","RING","SUNGLASSES","PERFUME","LIGHTING","SNEAKER","KNIVES","WOODEN PLANTER","EARPHONE","BANGLES","NECKLACE","RINGS","HEADBAND","PHONE CASE","SNEAKER","PAINTS","PENDANTS","CHOKER NECKLACE","HAND BAG","NAIL PAINT","BANGLES","SUNGLASSES","PERFUME","SHOES","LAMP","BROOCHES","BAGS","HEAD SCARF","BANGLES","LPSTICKS","ANKLETS","T-SHIRTS"};
	int price[size]={200,150,97,120,300,130,210,180,100,97,230,350,190,310,280,100,250,215,175,150,110,100,220,230,140,150,69,175,280,95,300,310,230,130,240,150,260,300,180,90,140,310,220,310,240,150,90,150,180,99,100};
	for(int i=0;i<size;i++){
        	f[csize++].set(order_taker[i],fname[i],gift[i],color[i],price[i]);
        }
    cout<<"*No of records : "<<csize<<"**\n\n";
	ofstream file;
	file.open("florist.bin",ios::in | ios::binary);
	file.write((char*)f,sizeof(Florist)*csize);
	file.close();

    Florist *ft = new Florist [100];
    ifstream file1;
    file1.open("florist.bin",ios::binary | ios::out );
    file1.read((char*)ft,sizeof(Florist)*csize);
    file1.close();
    ofstream file2;
    file2.open("florist.bin",ios::binary | ios::in );
    file2.write((char*)ft,sizeof(Florist)*100);
    string name,flower,Gift,Color;
    int choice,n,i,Price;
    do{
        choices();
        cin >> choice;
        switch(choice){
        case 0:
            cout<<"\tThanks for visiting my shop\n";
            break;
        case 1:
            case1(ft,csize);
            break;
        case 2:
            case2(ft);
            file2.write((char*)ft,sizeof(Florist)*size);
            break;
        case 3:
            cin>>ft[csize++];
            file2.write((char*)ft,sizeof(Florist)*size);
            break;
        case 4:
            case4(ft,csize);
            break;
        case 5:
            cout<<"*No of records : "<<csize<<"**\n\n";
            break;
        }
        }while(choice!=0);
    file2.close();
	return 0;
}