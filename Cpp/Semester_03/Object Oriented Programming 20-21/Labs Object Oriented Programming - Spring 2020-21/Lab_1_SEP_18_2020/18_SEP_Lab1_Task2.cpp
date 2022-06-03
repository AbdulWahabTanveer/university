#include<iostream>
#include <cmath>
using namespace std;
int main(){
    int i,j,k,common=0,row,colum1,colum2;
    cin>>row>>colum1>>colum2;
    int array1[row][colum1];
    int array2[row][colum2];
    for(i=0;i<row;i++)
        for(j=0;j<colum1;j++){
            cin>>array1[i][j];}
    for(i=0;i<row;i++)
        for(j=0;j<colum2;j++){
            cin>>array2[i][j];}

    for(i=0;i<row;i++){
        common=0;
        for(j=0;j<colum1;j++){
            for(k=0;k<colum2;k++){
                if(array1[i][j]==array2[i][k])
                {common++;
                break;}
                }
                }
        cout<<common<<"\n";}

    return 0;
}

