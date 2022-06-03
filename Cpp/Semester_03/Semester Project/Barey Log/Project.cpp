#include<iostream>
#include<string.h>

using namespace std;

class Flower_Pack{
protected:
    char fname[100];
    char gift[100];
    int price;
    char color[100];
public:
    Flower_Pack(){
    }
    Flower_Pack(char fname[], char gift[], char color[], int price){
        strcpy(this->fname,fname);
        strcpy(this->gift,gift);
        strcpy(this->color,color);
        this->price = price;
    }
    void SetFlowerPack(char fname[], char gift[], char color[], int price){
        strcpy(this->fname,fname);
        strcpy(this->gift,gift);
        strcpy(this->color,color);
        this->price = price;
    }
    friend ostream& operator << (ostream &out,const Flower_Pack &f){
        out<<"Flower Name:";
        out<<f.fname<<" Gift Type:"<<f.gift<<" Color of Sheet:"<<f.color<<" Price:"<<f.price<<"\n";
        return out;
    }
    friend istream& operator >> (istream &in, Flower_Pack &f){
        cout<<"Flower Name:";
        in>>f.fname;cout<<"Gift Type:";in>>f.gift;cout<<"Color of Sheet:";in>>f.color;cout<<"Price:";in>>f.price;
        return in;
    }
};
class Florist{
    Flower_Pack bouquet;
    char order_taker[100];
public:
    Florist(char order_taker[],char fname[], char gift[], char color[], int price){
    strcpy(this->order_taker,order_taker);
    bouquet.SetFlowerPack(fname,gift,color,price);
    }
friend istream& operator >> (istream &in, Florist &ft);
friend ostream& operator << (ostream &out, const Florist &ft);
};
istream& operator >> (istream &in, Florist &ft){
    cout<<"Order Taker's Name: ";
    in>>ft.order_taker;
    in>>ft.bouquet;
    return in;
}
ostream& operator << (ostream &out, const Florist &ft){
    cout<<"\n\t\tBlossom House\n";
    out<<"Order Taker's Name:"<<ft.order_taker<<"\n";
    out<<ft.bouquet;
    return out;
}


int main(){
    Florist ft("Alex", "TULIP", "Cookies", "Blush", 150);
    cout<<ft<<"\n\n";
    return 0;
}