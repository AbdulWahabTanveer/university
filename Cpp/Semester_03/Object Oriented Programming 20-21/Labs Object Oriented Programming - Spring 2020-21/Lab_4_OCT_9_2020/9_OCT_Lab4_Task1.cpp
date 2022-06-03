#include<iostream>
using namespace std;

class QuizResult{

int noOfStrudents;//5-15, default is 10

int *marks;

public:
QuizResult(const int n){
    noOfStrudents=n;
    marks=new int [n];
}
QuizResult(const QuizResult &q1){
    int i;
    noOfStrudents=q1.noOfStrudents;
    marks=new int [noOfStrudents];
    for(i=0;i<noOfStrudents;i++)
        marks[i]=q1.marks[i];
}

void read(){
    int i;
    for(i=0;i<noOfStrudents;i++)
        cin>>marks[i];
}

void show() const{
    int i;
    for(i=0;i<noOfStrudents;i++){
        cout<<marks[i]<<" ";
    }
    cout<<"\n";
}
void scale(int value){
    int i;
    for(i=0;i<noOfStrudents;i++)
        marks[i]=marks[i]+value;
}
};

int main(){

int n, value;

cin >> n;

QuizResult q1(n);

q1.read();  //input n values

q1.show();

QuizResult q2 = q1;

cin >> n >> value;

if (n==1)   q1.scale (value); //increase marks of all students for quiz 1

else        q2.scale (value); //increase marks of all students for quiz 2

q1.show();

q2.show();

return 0;

}