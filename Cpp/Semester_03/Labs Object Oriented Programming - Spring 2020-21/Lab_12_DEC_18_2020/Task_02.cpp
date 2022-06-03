#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<ctime>

using namespace std;

template <class T>
class sets{
  public:
  T *arr;int size,csize;
  
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
        sets local(csize+s.csize);int count=0;
        for(int i=0;i<csize;i++)
            if(!local.isExist(arr[i]))
                local.arr[count++]=arr[i];
        for(int i=0;i<s.csize;i++)
            if(!local.isExist(s.arr[i]))
                local.arr[count++]=s.arr[i];
        
        local.csize=csize+s.csize;
        *this=local;
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




int main(){
    sets <int> s(1);
    sets <int> s1(10);

    s.add(5);
    s.add(10);
    s.add(45);
    s.add(75);
    s.add(95);
    s.add(85);
    s1.add(15);
    s1+=s;
    cout<< s;
    return 0;
}