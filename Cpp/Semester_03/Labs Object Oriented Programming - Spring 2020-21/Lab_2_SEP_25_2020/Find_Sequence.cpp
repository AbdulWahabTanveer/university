struct Matrix{
    int **d, rows, columns;
    void init(int r, int c){
        rows=r, columns=c;
        int i;
        d = new int* [rows];
        for (i=0;i<rows;i++)
            d[i] = new int [columns];
    }
    void read(){
        int i,j;
        for (i=0;i<rows;i++)
            for (j=0;j<columns;j++)
                cin>>d[i][j];
    }
    //Copy elements of Matrix or 2D array into 1D array
    void copyElementIntoArray(int *a){
        int i,j, k=0;
        for (i=0;i<rows;i++)
            for (j=0;j<columns;j++)
                a[k++]=d[i][j];
    }
    void sort(int *a, const int SIZE){
        int i, j, value;
        for (i=1;i<SIZE;i++){
            value = a[i];
            for (j=i-1;j>=0 && a[j]>value;j--)
                a[j+1]=a[j];
            a[j+1]=value;
        }
    }
    void findPosition(const int ELEMENT, int &i, int &j){
        for (i=0;i<rows;i++)
            for (j=0;j<columns;j++)
                if (d[i][j]==ELEMENT)
                    return;
    }
    void findAndPrintSequence(){
        int size = rows * columns;
        int *a = new int[size];
        copyElementIntoArray(a);//copy Matrix that is 2D array into 1D array
        sort(a, size);
        int r=0, c=0, i, j, count;
        for (int k=0 ; k<size ; k++){
            findPosition(a[k], r, c);//Find element of 1D array in 2D array, where 1D array is sorted array now
            i = r, j = c;
            //As 1D array is made from 2D array, therefore every element of 1D array exist in 2D array so take count as 1
            count=1;
            //Check how many elements lie in sequence in 2D array that is either in next column of same row or
            //first element of next row, if current element exist in last column of current row
            while (true){  //Continue till elements in 2D array are in sequence
                if (i==rows-1 && j==columns-1)  break;  //If reach end of 2D array, terminates the loop
                //If reach end of column, move to first column and next row
                if (j==columns-1 )
                    i++, j=0;
                else        //If there are more elements in same row, move to next element in same row
                    j++;
                if (d[i][j]==a[++k]) count++;   //If elements of 1D and 2D array match, increment in count
                else { k--; break;}             //If elements of 1D and 2D array mismatch, terminate the loop
            }
            //Print, starting from first element poistion return by findPosition function, how many elements
            //are in sequence
            cout << r+1 << ' ' << c+1 << ' ' << count << '\n';
        }
    }
    
};

int main() {
    Matrix m;
    int r, c;
    cin >> r >> c;
    m.init(r, c);
    m.read();
    m.findAndPrintSequence();
    return 0;
}
