#include<iostream>
using namespace std;

class Rectangle{
    int m_Length,m_Width;
    
    public:
    void set(int length,int width){
        if(length>0){
           m_Length=length;
        }
        else{
            m_Length=0;
        }
        if(width>0){
           m_Width=width;
        }
        else{
            m_Width=0;
        }
        
    }
    int calcArea(int L,int W){
        int r;
        r=L*W;
        return r;
    }
    int calcPerimeter(int L,int W){
        int r;
        r=2*(L+W);
        return r;
    }
    void show(int area,int perimeter) const{
        cout<<"\n";
        cout<<"Length: "<<m_Length<<"\n";
        cout<<"Width: "<<m_Width<<"\n";
        cout<<"Area: "<<area<<"\n";
        cout<<"Perimeter: "<<perimeter<<"\n";
        cout<<"\n";
    }
};

int main(){
    int L,W,perimeter,area;
    Rectangle R1;
    
    cout<<"Enter Length : ";
    cin>> L;
    cout<<"Enter Width : ";
    cin>> W;

    R1.set(L,W);
    perimeter = R1.calcPerimeter(L,W);
    area = R1.calcArea(L,W);
    R1.show(area,perimeter);

}