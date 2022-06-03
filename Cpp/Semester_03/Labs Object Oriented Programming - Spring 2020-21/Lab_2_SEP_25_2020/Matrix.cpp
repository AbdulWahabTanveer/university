#include <iostream>
#include <iomanip>

using namespace std;

struct Matrix{
    int **data, rows, columns;
    void set(const int ROWS, const int COLUMNS){
        rows = ROWS;
        columns = COLUMNS;
        data = new int*[ROWS];
        for (int i=0;i<ROWS;i++)
            data[i] = new int [COLUMNS];
    }
    void read(){
        int i,j;
        for (i=0;i<rows;i++)
            for (j=0;j<columns;j++)
                cin>>data[i][j];
    }
    void changecolum(int col1,int col2){
        int i,temp;
        for (i=0;i<rows;i++){
                temp=data[i][col1];
                data[i][col1]=data[i][col2];
                data[i][col2]=temp;
        }

    }
    void multiplyrow(int row1,int number){
        int j,x;
            for (j=0;j<columns;j++){
                x=data[row1][j]*number;
                data[row1][j]=x;}
    }
    void show(int f){
        int i,j;
        for (i=0;i<rows;i++){
            for (j=0;j<columns;j++)
                cout<< data[i][j] << ' ';
            cout << '\n';
        }
        if(f==0)
        cout << '\n';
    }
    void free(){
        for (int i=0;i<rows;i++)
            delete []data[i];
        delete data;
    }
};

int main(){
    int row,col,number,row1,col1,col2;
    int formater=1;
    Matrix m1;
    cin>>row;
    cin>>col;
    m1.set(row,col);
    m1.read();
    m1.show(formater);
    cin>>row1;
    row1--;
    cin>>number;
    m1.multiplyrow(row1,number);
    cin>>col1;
    cin>>col2;
    col1--;col2--;
    m1.changecolum(col1,col2);
    formater++;
    m1.show(formater);
    m1.free();
    return 0;
}
