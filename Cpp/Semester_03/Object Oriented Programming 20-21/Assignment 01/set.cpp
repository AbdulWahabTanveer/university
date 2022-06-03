#include <iostream>
#include <ctime>
using namespace std;

struct Set{
	int *data, currentSize, size,*universal,usize,ucurrentsize;

	void init(const int SIZE){
		size = SIZE;
		currentSize = 0;
		data = new int[size];
	}
	void inputset(const int Size){
        //custom function to easy initialize the data array
        int i,temp;
        for(i=0;i<Size;i++){
            cin>>temp;
            add(temp);
        }
    }
	bool add(const int ELEMENT){
		if (currentSize == size)	return false;
		if (isExist(ELEMENT))		return false;
		data [ currentSize++ ] = ELEMENT;
		return true;
	}
	bool isExist(const int ELEMENT){
		for (int i=0;i<currentSize;i++)
			if (data[i] ==  ELEMENT)
				return true;
		return false;
	}

	Set set_union(const Set &sB){
        Set local;
        int i;
        local.init(currentSize+sB.currentSize);

        for(i=0;i<currentSize;i++)
            local.data[local.currentSize++]=data[i];

        for(i=0;i<sB.currentSize;i++)
                local.add(sB.data[i]);

        return local;
    }
	Set set_intersection(const Set &sB){
		int i;
		Set local;
		local.init(currentSize+sB.currentSize);
		for(i=0;i<sB.currentSize;i++)
            if(isExist(sB.data[i]))
                local.data[local.currentSize++]=sB.data[i];
        return local;
	}
	Set set_difference(Set &sB){
		int i;
		Set local;
		local.init(currentSize);
		for(i=0;i<currentSize;i++)
            if(!sB.isExist(data[i]))
                local.data[local.currentSize++]=data[i];
        return local;
    }
    void universal_set(Set sB){
        //initializes the universal set
        int i;
        Set local=set_union(sB);
        usize=local.size;
        universal=new int[usize];
        for(i=0;i<local.currentSize;i++){
            universal[i]=local.data[i];
            cout<<universal[i]<<" ";
        }
        ucurrentsize=local.currentSize;
    }
    void set_resize(int newsize){
        Set local;
        int i;
        local.init(newsize);
        for(i=0;i<currentSize&&local.size!=local.currentSize;i++)
            local.data[local.currentSize++]=data[i];
        delete []data;
        data=local.data;
        size=local.size;
        currentSize=local.currentSize;

    }
	Set set_compliment(Set sB){
	    //Mapped the whole universal set to a Set variable
	    //to reuse difference function
	    Set local;
	    int i;
	    local.init(ucurrentsize);
	    for(i=0;i<ucurrentsize;i++){
            local.data[i]=universal[i];
        }
        local.size=usize;
        local.currentSize=ucurrentsize;
        local=local.set_difference(sB);
        return local;
        }

	bool isSubset(const Set sB){
        //simple applied Has logic from Bag code
        int i;
        for(i=0;i<sB.currentSize;i++){
            if(!isExist(sB.data[i]))
                return false;
        }
        return true;
	}
	bool isProperSubset(const Set sB){
        int i;
        for(i=0;i<sB.currentSize;i++){
            if(!isExist(sB.data[i]))
                return false;
        }
        if(currentSize>sB.currentSize)
        //if set 1 has more elements than B it cannot be equal to it
        //so there for its a proper subset
        return true;
        else
            return false;
    }
	void print(){
	    if(currentSize==0)
            cout<<"EmptySet";
		for (int i=0;i<currentSize;i++)
			cout << data[i] << ' ';
		cout << '\n';
	}
    void free(){
			delete []data;
	}
};

int main(){
	struct Set A,B,UnionSet,IntersectionSet;
	struct Set AminusB,BminusA;
	int sizeofA,sizeofB,newsize;
	srand(time(0));


	cout<<"This Program does not Expect the User to enter Garbage data\nSo Enter data wisely and if u try to repeat a number there will be No Error but the dublication will not occur\nfor further queries contact:bcsf19a513@pucit.edu.pk\n\n\n";




    cout<<"Enter Size of Set A: ";
    cin>>sizeofA;
    A.init(sizeofA);
    cout<<"Enter Size of Set B: ";
    cin>>sizeofB;
    B.init(sizeofB);
    //Made the 2 Sets and Declared Dynamic Arrays


    int esizeA,esizeB;
    cout<<"Enter Number of Elements to add to Set A: ";
    cin>>esizeA;
    cout<<"Enter "<<esizeA<<" Numbers to add to Set A: ";
    A.inputset(esizeA);
    cout<<"Enter Number of Elements to add to Set B: ";
    cin>>esizeB;
    cout<<"Enter "<<esizeB<<" Numbers to add to Set B: ";
    B.inputset(esizeB);
    cout<<"Set A: ";
    A.print();cout<<"\n";
    cout<<"Set B: ";
    B.print();cout<<"\n";
    //First took size to add then added and printed the Sets

    UnionSet=A.set_union(B);
    cout<<"A U B: ";
    UnionSet.print();
    //Calculated and printed Union

    IntersectionSet=A.set_intersection(B);
    cout<<"A ∩ B: ";
    IntersectionSet.print();
    //Calculated and printed Union

    AminusB=A.set_difference(B);
    cout<<"A - B: ";
    AminusB.print();
    //Calculated and A-B Set Difference

    BminusA=B.set_difference(A);
    cout<<"B - A: ";
    BminusA.print();
    //Calculated and B-A Set Difference

    cout<<"Enter New Size for Set A: ";
    cin>>newsize;
    A.set_resize(newsize);
    cout<<"Current Size of A:"<<A.currentSize<<" Size of A: "<<A.size<<"\n";
    //Resized Set A


    cout<<"\nUniversal Set A is: ";
    A.universal_set(B);
    cout<<"\nUniversal Set B is: ";
    B.universal_set(A);
    //created universal Set by combining the 2 Sets in both A and B

    Set CA,CB;
    CA=A.set_compliment(A);
    CB=B.set_compliment(B);
    cout<<"\n\nCompliment of A is: ";CA.print();
    cout<<"Compliment of B is: ";CB.print();cout<<"\n";
    //finding Compliments And printing them

    cout<<"Is B a Subset of A: ";
    if(A.isSubset(B))
        cout<<"True\n";
    else
        cout<<"False\n";
    //Checked for subset Bonus Q

    cout<<"Is B a Proper Subset of A: ";
    if(A.isProperSubset(B))
        cout<<"True\n";
    else
        cout<<"False\n";
    //Checked for Proper subset Bonus Q

    A.free();
    B.free();
    //to free memory
	return 0;
}
