#include <iostream>

using namespace std;

struct Bag{
    int *data, currentSize, size;
    void init(const int SIZE){
        size = SIZE;
        currentSize = 0;
        data = new int[size];
    }
    bool isExist(const int ELEMENT){
        for (int i=0;i<currentSize;i++)
            if (data[i] ==  ELEMENT)
                return true;
        return false;
    }
    void add(const int ELEMENT){
        int i;
        for(i=0;i<ELEMENT;i++)
        cin>>data [ currentSize++ ];
    }
    int indexof(const int ELEMENT){
        for (int i=0;i<currentSize;i++){
            if (data[i] ==  ELEMENT)
                return i;}
        return -1;
    }
    void bag_resize(const int newsize){
        Bag local;
        int i;
        local.init(newsize);
        for(i=0;i<currentSize&&local.size!=local.currentSize;i++)
            local.data[local.currentSize++]=data[i];
        delete []data;
        data=local.data;
        size=local.size;

    }
    Bag bag_merge(const Bag &B2){
        Bag local;
        int i;
        local.init(currentSize+B2.currentSize);

        for(i=0;i<currentSize;i++)
            local.data[local.currentSize++]=data[i];

        for(i=0;i<B2.currentSize;i++)
                local.data[local.currentSize++]=B2.data[i];

        return local;
    }
    bool bag_has(const Bag &B2){
        int i;
        for(i=0;i<B2.currentSize;i++){
            if(!isExist(B2.data[i]))
                return false;
        }
        return true;
    }
    void print(){
        for (int i=0;i<currentSize;i++)
            cout << data[i] << ' ';
        cout << '\n';
    }
    void free(){
			delete []data;
	}
};

int main(){
    struct Bag A,B;
    int sizeA,sizeB,esizeA,esizeB;
    int numindex,newsize;

    cout<<"Enter Size of Bag A: ";
    cin>>sizeA;
    A.init(sizeA);

    cout<<"Enter Size of Bag B: ";
    cin>>sizeB;
    B.init(sizeB);
    //These 2 chunks Declare The 2 Bags A and B


    cout<<"Enter Size to add Numbers in Bag A: ";
    cin>>esizeA;
    A.add(esizeA);

    cout<<"Enter Size to add Numbers in Bag B: ";
    cin>>esizeB;
    B.add(esizeB);
    //These 2 chunks Initialize The 2 Bags A and B


    cout<<"Bag A is: ";
    A.print();
    cout<<"\n";
    cout<<"Bag A is: ";
    B.print();
    cout<<"\n";
    //First print to Check Basic Functionality


    cout<<"\nEnter Element to find index of in Bag A: ";
    cin>>numindex;
    cout<<"Index of "<<numindex<<" Is " <<A.indexof(numindex);
    //This chunk Makes use of the indexof Function


    cout<<"\n\nEnter New size for Bag A: ";
    cin>>newsize;
    A.bag_resize(newsize);
    cout<<"New size for A is "<<A.size<<" And current size of A is "<<A.currentSize;
    //This chunk Resizes bag A with the help of bag_resize


    struct Bag C;
    C=A.bag_merge(B);
    cout<<"\n\nThe Merged A and B bags in C are: ";
    C.print();
    //This chunk merges the Bag A and B in Bag C


    cout<<"\nCheck if A has all the elements of B: ";
    if(A.bag_has(B))
        cout<<"True\n";
    else
        cout<<"False\n";
    //This chunk makes use of that Bag_has function

    A.free();
    B.free();
    C.free();
    //releases the memory

    return 0;
}
