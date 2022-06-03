#include <iostream>
#include <ctime>
using namespace std;

class Set{
    int  currentSize, size;
    char *data;

    bool equality(const Set sB){
        int i;
        for(i=0;i<sB.currentSize;i++){
            if(!isExist(sB.data[i]) && sB.currentSize==currentSize)
                return false;
        }
        return true;
    }
    friend ostream& operator  << (ostream &out,const Set &s);
    public:
    Set(const int SIZE=5){
        size = SIZE;
        currentSize = 0;
        data = new char[size];
    }
    void operator = (const Set s){
        int i;
        size = s.size;
        currentSize = s.currentSize;
        data = new char[size];
        
        for(i=0;i<s.currentSize;i++){
            data[i]=s.data[i];
        }
    }
    bool add(const char ELEMENT){

        if (isExist(ELEMENT))        return false;
        data [ currentSize++ ] = ELEMENT;
        return true;
    }
    void inputset(const int Size){
        int i;
        char temp;
        for(i=0;i<Size;i++){
            cin>>temp;
            add(temp);
        }
    }
    bool operator + (const char ELEMENT){
        if (currentSize == size)    return false;
        if (isExist(ELEMENT))        return false;
        data [ currentSize++ ] = ELEMENT;
        return true;
    }
    bool isExist(const char ELEMENT){
        for (int i=0;i<currentSize;i++)
            if (data[i] ==  ELEMENT)
                return true;
        return false;
    }

    Set operator + (const Set &sB){
        int i;
        Set local(currentSize+sB.currentSize);

        for(i=0;i<currentSize;i++)
            local.data[local.currentSize++]=data[i];

        for(i=0;i<sB.currentSize;i++)
                local.add(sB.data[i]);

        return local;
    }
    Set operator - (Set &sB){
        int i;
        Set local(currentSize);
        for(i=0;i<currentSize;i++)
            if(!sB.isExist(data[i]))
                local.data[local.currentSize++]=data[i];
        return local;
    }
    void operator - (const char Element){
        int i,j;
        for(i=0;i<currentSize;i++){
            if(Element==data[i]){
                currentSize--;
                for(j=i;j<currentSize;j++){
                    data[j]=data[j+1]; 
                }
            }
        }
    }

    bool operator == (const Set sB){
        bool local=equality(sB);
        return local;
    }
    bool operator != (const Set sB){
        bool local=true;
        if(equality(sB)) local=false;
        return local;
    }
    void operator *(const Set S){
        int i,j;
        cout<<"{";
        for(j=0;j<S.currentSize;j++){
        for(i=0;i<currentSize;i++){
            cout<<"("<<data[i]<<','<<S.data[j]<<')';
            if(!(i==currentSize-1 && j==S.currentSize-1)) cout<<',';
        }
        }
        cout<<"}";
    }
    void free(){
            delete []data;
    }
};
ostream& operator  << (ostream &out,const Set &s){
        if(s.currentSize==0)
            out<<"EMPTY SET\n";
        else{
        for (int i=0;i<s.currentSize;i++)
            out << s.data[i] << ' ';
        out << '\n';}
    return out;
}
int main(){
    int i,times,selector1,selector2,selector3;
    int operation;
    char character;
    Set pointer[5];
    cin>>times;

    for(i=0;i<times;i++){  
        cin>>operation; 
        switch(operation){
            case 1:
                cin>>selector1>>selector2>>selector3; 
                pointer[--selector3]=pointer[--selector1]+pointer[--selector2];
                break;
            case 2:
                cin>>selector1>>selector2; 
                pointer[--selector1] * pointer[--selector2];
                break;    
            case 3: 
                cin>>selector1>>character; 
                pointer[--selector1]+character;
                break;
            case 4: 
                cin>>selector1>>character; 
                pointer[--selector1]+character;
                break;

            case 5: 
                cin>>selector1>>character; 
                pointer[--selector1]-character;
                break;
            case 6: 
                cin>>selector1>>selector2;
                if(pointer[--selector1]==pointer[--selector2]) cout<<"TRUE\n";
                else cout<<"FALSE\n";
                break;
            case 7: 
                cin>>selector1>>selector2;
                if(pointer[--selector1]!=pointer[--selector2]) cout<<"TRUE\n";
                else cout<<"FALSE\n";
                break;
            case 8: 
                cin>>selector1;
                cout<<pointer[--selector1];
                break;
            case 9: 
                cin>>selector1;
                cin>>selector2;
                pointer[--selector1].inputset(selector2);
                break;
            case 10: 
                cin>>selector1>>selector2;
                pointer[--selector1]=pointer[--selector2];
                break;
        }
    }
    return 0;
}
/*15
8 2
9 2 3 A B C 
8 2 
9 3 3 C B A 
8 3 
6 2 3 
7 3 2 
4 3 D 
4 3 E 
1 2 3 1
8 1 
7 1 3 
7 1 2 
10 4 2
2 2 4 */