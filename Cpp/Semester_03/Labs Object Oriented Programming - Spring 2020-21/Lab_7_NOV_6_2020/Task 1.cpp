#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*int* Find_common(int c1,int c2,int *c,const int list1[],const int list2[]){
    int *data;
    int c12,i,j;
    
    
    return data;
}*/


int main() {
    int count1,count,i,j,c,*list1,*list2,*arr1,*data;

    cin.read((char*)&count1,sizeof(int));
    list1=new int[count1];
    cin.read((char*)list1,sizeof(int)*count1);
    int count2;
    cin.read((char*)&count2,sizeof(int));
    list2=new int[count2];
    cin.read((char*)list2,sizeof(int)*count2);
    
    bool flag = true;
    //dublication handler
    int arr[count1];
    
    for(i=0;i<count2;i++){
        for(j=0;j<count1;j++){
            if(list2[i]==list1[j]){
                flag = true;
                for(c=0;c<count;c++){
                    if(arr[i]==list2[i]){
                        flag=false;
                    }   
                }
                if(flag) arr[count++]=list2[i];
            }
        }
    }

    //I have an array up top with common values but its size is of size list 1
    //so created a copy
    arr1=new int[count];
    for(c=0;c<count;c++){
                    arr1[c]=arr[c];
                    }
    //copy so that no extra free space


    cout.write((char*)&count,sizeof(int));
    cout.write((char*)arr1,sizeof(int)*count);
    return 0;
}


