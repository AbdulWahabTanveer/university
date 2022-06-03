#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<ctime>

using namespace std;

template <class T>
class sets{
  T *arr;int size,csize;
  public:  
    sets(int size){this->size=size;arr=new T[size];csize=0;}
    
    sets(T arr[],int size){
        this->size=size;
        arr=new T[size];
        for(int i;i<size;i++)
            this->arr[i]=arr[i];
        }

    bool isExist(T var){
        for(int i=0;i<csize;i++){
            if(this->arr[i]==var)
                return true;
        }
        return false;
    }

    bool add(T var){
        if(csize==size){
           ResizeArray(arr,size,size+5,arr);
        }
        
        if(!isExist(var)){
            arr[csize++]=var;
            return true;}
        return false;
    }
    sets operator -(const sets &s){
        sets local;int count=0;
        for(int i;i<csize;i++)
            if(!s.isExist(arr[i]))
                local.arr[count++]=arr[i];
        return local;
    }
    void operator +=(const sets &s){
           ResizeArray(arr,size,size+s.size,arr);
           int j=0;
           for(int i=csize;i<csize+s.csize;i++)
            arr[i]=s.arr[j++];
    }

    void operator =(const sets &s){
        this->size=s.size;
        delete[] arr;
        arr=new T[size];
        csize=s.csize;
        for(int i=0;i<s.csize;i++)
                arr[i]=s.arr[i];
    }
    ~sets(){delete[] arr;}
    template<typename m> 
    friend ostream& operator <<(ostream& out, const sets<m>& s);
    void ResizeArray(T* paArray, int iOldSize, int iNewSize, T *tInitValue){
        
        T* paTmpArray = new T[iOldSize];
        for(int i = 0; i < iOldSize; i++){
        paTmpArray[i] = paArray[i];
        }
        delete [] paArray;
        paArray=new T[iNewSize];
        for(int i=0; i < iNewSize; i++){
            paArray[i] = tInitValue[i];
        }
        for(int i = 0; i < iOldSize; i++){
            paArray[i] = paTmpArray[i];
        }
        delete [] paTmpArray;
    }

};
    template<typename m> 
    ostream& operator <<(ostream& out, const sets<m>& s){
        
        out<<"Size: "<<s.size<<"\n";

        out<<"No. of Elements: "<<s.csize<<"\n";
        out<<"Set {";
        for(int j=0;j<s.csize;j++){
            out<<s.arr[j]<<' ';
        }
        out<<"}\n\n";
        return out;
    }

template<class myway>
class setbuilder{
    sets <myway> s1,s2,s3,s4;
    public:
    setbuilder():s1(10),s2(10),s3(10),s4(10){
    }
    void add(int whichone,myway val){
        switch(whichone){
            case 1:    
                s1.add(val);
                break;
            case 2:
                s2.add(val);
                break;
            case 3:
                s3.add(val);
                break;
            case 4:
                s4.add(val);
                break;
        }
    }
    sets<myway> get_set(int whichone){
        switch(whichone){
            case 1:    
                return s1;
                break;
            case 2:
                return s2;
                break;
            case 3:
                return s3;
                break;
            case 4:
                return s4;
                break;
        }
        return s1;
    }
    ~setbuilder(){
    }
};


int main(){
    setbuilder <int>s;
    s.add(1,5);
    s.add(1,7);
    s.add(1,5);
    s.add(1,4);
    s.add(1,9);
    s.add(1,3);
    s.add(1,90);
    s.add(1,1);

    s.add(2,11);
    s.add(2,3);
    s.add(2,5);
    s.add(2,9);
    s.add(2,10);
    s.add(2,13);
    s.add(2,11);

    s.add(3,18);
    s.add(3,18);
    s.add(3,4);
    s.add(3,45);
    s.add(3,18);
    s.add(3,12);
    s.add(3,32);

   // s.get_set(4) +=s.get_set(1);
    //s.get_set(4) +=s.get_set(2);
    //s.get_set(4) +=s.get_set(3);

cout<<s.get_set(1);
cout<<s.get_set(2);
cout<<s.get_set(3);
//cout<<s.get_set(4);

    return 0;
}