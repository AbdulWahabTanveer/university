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
                data[i][j]=rand()%20;
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
    Matrix operator +(const Matrix &M){
        Matrix local;
        local.set(rows, columns);

        if(this->rows==M.rows&&this->columns==M.columns){
            for (int i=0;i<rows;i++)
                for (int j=0;j<columns;j++)
                    local.data[i][j] = data[i][j] + M.data[i][j];
        }
        else{
            cout<<"\nDimentions Don't Match.";
        }
        return local;
    }
    Matrix operator -(const Matrix &M){
        Matrix local;
        local.set(rows, columns);

        if(this->rows==M.rows&&this->columns==M.columns){
            for (int i=0;i<rows;i++)
                for (int j=0;j<columns;j++)
                    local.data[i][j] = data[i][j] - M.data[i][j];
        }
        else{
            cout<<"\nDimentions Don't Match.";
        }
        return local;
    }
    void operator -=(const Matrix &M){
    
        if(this->rows==M.rows&&this->columns==M.columns){
            for (int i=0;i<rows;i++)
                for (int j=0;j<columns;j++)
                    data[i][j] = data[i][j] - M.data[i][j];
        }
        else{
            cout<<"\nDimentions Don't Match.";
        }
    }
    void operator +=(const Matrix &M){
    
        if(this->rows==M.rows&&this->columns==M.columns){
            for (int i=0;i<rows;i++)
                for (int j=0;j<columns;j++)
                    data[i][j] = data[i][j] + M.data[i][j];
        }
        else{
            cout<<"\nDimentions Don't Match.";
        }
    }
    Matrix operator *(const Matrix &M){
        Matrix local;
        local.set(rows, columns);
        int i,j,k;

        if(this->columns==M.rows){
            for(i = 0; i < rows; ++i){
                for(j = 0; j < M.columns; ++j){
                    for(k = 0; k < columns; ++k){
                        local.data[i][j] += data[i][k] * M.data[k][j];
                    }
                }
            }
        }
        else{
            cout<<"\nMatrices not suitable for Multiplication.";
        }
        return local;
    }
    void operator *=(const Matrix &M){
        Matrix local;
        local.set(rows, columns);
        int i,j,k;

        if(columns==rows&&M.columns==columns&&M.rows==rows){
            for(i = 0; i < rows; ++i){
                for(j = 0; j < M.columns; ++j){
                    for(k = 0; k < columns; ++k){
                        local.data[i][j] += data[i][k] * M.data[k][j];
                    }
                }
            }
        }
        else{
            cout<<"\nMatrices not suitable for Multiplication.";
        }
         for (int i=0;i<rows;i++)
                for (int j=0;j<columns;j++)
                    data[i][j] = local.data[i][j];
    }
    
};

int main(){
    int row,col,i,selector;
    srand(time(0));
    Matrix m1,m2;

cout<<"Enter Rows: ";
    cin>>row;
cout<<"Enter Colums: ";
    cin>>col;

    m1.set(row,col);
cout<<"Enter Rows for M2: ";
    cin>>row;
cout<<"Enter Colums for M2: ";
    cin>>col;
    m2.set(row,col);
    m1.init();
    m2.init();
    
    
cout<<"\nM1 is\n";
    m1.show();
cout<<"\nM2 is\n";
    m2.show();
cout<<"\nM1+M2 is\n";
    (m1+m2).show();
cout<<"\nM1-M2 is\n";
    (m1-m2).show();
cout<<"\nM1*M2 is\n";
    (m1*m2).show();

    m1*=m2;
cout<<"\nM1 is after m1*=m2\n";
    (m1).show();    
    
    m1-=m2;
cout<<"\nM1 is after m1-=m2\n";
    m1.show(); 

    m2+=m1;
cout<<"\nM2 is after m2+=m2\n";
    m1.show();   
    
    m1.free();
    m2.free();
    return 0;
}
