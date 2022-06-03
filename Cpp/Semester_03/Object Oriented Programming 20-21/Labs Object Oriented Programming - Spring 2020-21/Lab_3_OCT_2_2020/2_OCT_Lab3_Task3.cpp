#include <iostream>
#include <iomanip>

using namespace std;

struct Matrix{
    int **data, rows, columns;
    void set(const int ROWS, const int COLUMNS){
        rows = ROWS;
        columns = COLUMNS;
        data = new int*[ROWS];//memory of 1d pointers
        for (int i=0;i<ROWS;i++)
            data[i] = new int [COLUMNS];
    }
    void init(){
        int i,j;
        for (i=0;i<rows;i++)
            for (j=0;j<columns;j++)
                cin>>data[i][j];
    }
    void show(){
        int i,j;
        for (i=0;i<rows;i++){
            for (j=0;j<columns;j++)
                cout <<data[i][j] << ' ';
            cout << '\n';
        }

    }
    void multiply_row(int krow,int scalar){
        int i;
        for (i=0;i<columns;i++)
                data[krow][i] = data[krow][i] * scalar;
    }
    void multiply_col(int kcol,int scalar){
        int i;
        for (i=0;i<rows;i++)
                data[i][kcol] = data[i][kcol] * scalar;
    }
    void add_row(int jrow,int krow){
        int i;
        for (i=0;i<columns;i++)
                data[krow][i] = data[jrow][i] + data[krow][i];
    }
    void add_col(int jcol,int kcol){
        int i;
        for (i=0;i<rows;i++)
                data[i][kcol] = data[i][kcol] + data[i][jcol];
    }
    void subtract_row(int jrow,int krow){
        int i;
        for (i=0;i<columns;i++)
                data[krow][i] = data[krow][i] - data[jrow][i];
    }
    void subtract_col(int jcol,int kcol){
        int i;
        for (i=0;i<rows;i++)
                data[i][kcol] = data[i][kcol] - data[i][jcol];
    }
    void free(){
        for (int i=0;i<rows;i++)
            delete []data[i];
        delete data;
    }
};

int main(){
    int row,col,i,selector;
    int k,j,scalar,number;
    Matrix m1;

    cin>>row>>col;

    m1.set(row,col);
    m1.init();
    cin>>number;
    for(i=0;i<number;i++){
        cin>>selector;
        switch (selector){
            case 1:
                cin>>k>>scalar;
                m1.multiply_row(--k,scalar);
                break;
            case 2:
                cin>>k>>scalar;
                m1.multiply_col(--k,scalar);
                break;
            case 3:
                cin>>j>>k;
                m1.add_row(--j,--k);
                break;
            case 4:
                cin>>j>>k;
                m1.add_col(--j,--k);
                break;
            case 5:
                cin>>j>>k;
                m1.subtract_row(--j,--k);
                break;
            case 6:
                cin>>j>>k;
                m1.subtract_col(--j,--k);
                break;
            case 7:
                m1.show();
                break;
        }
    }
    m1.free();
    return 0;
}
