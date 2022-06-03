#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int count1,count=0,i,j,c,*arr1,*list1,*list2;
    cin.read((char*)&count1,sizeof(int));
    list1=new int [count1];
    cin.read((char*)list1,sizeof(int)*count1);
    int count2;
    cin.read((char*)&count2,sizeof(int));
    list2=new int [count2];
    cin.read((char*)list2,sizeof(int)*count2);
    
    int arr[count1];
    
    for(i=0;i<count2;i++){
        for(j=0;j<count1;j++){
            if(list2[i]==list1[j]){
                arr[count++]=list2[i];
            }
            break;
        }
    }
    arr1=new int[count];
    for(c=0;c<count;c++){
            arr1[c]=arr[c];
                    }
    cout.write((char*)&count,sizeof(int));
    cout.write((char*)arr1,sizeof(int)*count);
    return 0;
}