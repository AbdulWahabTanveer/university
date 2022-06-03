#include <iostream>

using namespace std;

struct Bag{
    int *data, currentSize, size;//100 size=100, 44  currentsize=44
    void set(const int SIZE){
        size = SIZE;//sets max , currentsize 0 , dynamic array declare
        currentSize = 0;
        data = new int[size];
    }
    bool isExist(const int ELEMENT){
        for (int i=0;i<currentSize;i++)
            if (data[i] ==  ELEMENT)
                return true;
        return false;
    }
    int index(const int ELEMENT){
        for (int i=0;i<currentSize;i++){
            if (data[i] ==  ELEMENT)
                return i;}
        return 0;
    }
    void add(const int ELEMENT){
        int i;
        for(i=0;i<ELEMENT;i++)
        cin>>data [ currentSize++ ];//data[0]=cin,data[1]=cin,
    }
    void insert(int number,int index){
        int i;
        for(i=currentSize;i>=index;i--)//11 new 22 33 55 {0 1 2 3 4} value 44
            data[i]=data[i-1];

        currentSize++;
        data[index]=number;
//1 2 22 3 5    5 4
    }
    void remove(int number){
        int i;
            i=index(number);//100 50 use 50 garbage
            for(;i<currentSize-1;i++){// 50 {0-49}
                data[i]=data[i+1];//11 22 33 55 55 currentsize--
            }
            currentSize--;
            data[i]=0;
    }
    void show(int f){
        for (int i=0;i<currentSize;i++)
            cout << data[i] << ' ';
        if(f==0)
        cout << '\n';
    }
};

int main(){
    struct Bag A;
    int size,esize,rnumber,numberinsert,indexinsert;
    cin>>size;
    A.set(size);
    cin>>esize;
    A.add(esize);
    A.show(0);
    cin>>rnumber;
    if(A.isExist(rnumber))
    A.remove(rnumber);
    A.show(0);

    cin>>numberinsert;
    cin>>indexinsert;

    A.insert(numberinsert,indexinsert);
    A.show(1);

    return 0;
}
/*  1 23 12 312 31
    12 234 324
    12 3 1
    ================ */

