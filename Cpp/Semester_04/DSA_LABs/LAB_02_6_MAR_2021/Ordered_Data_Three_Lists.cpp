#include <iostream>

using namespace std;
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int partition(int array[],int array1[],int array2[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
      swap(&array1[i], &array1[j]);
      swap(&array2[i], &array2[j]);
    }
}
  swap(&array[i + 1], &array[high]);
  swap(&array1[i + 1], &array1[high]);
  swap(&array2[i + 1], &array2[high]);
  return (i + 1);
}

void quickSort(int array[],int array1[],int array2[], int low, int high) {
  if (low < high) {
    
    int pi = partition(array,array1,array2, low, high);

    quickSort(array,array1,array2, low, pi - 1);

    quickSort(array,array1,array2, pi + 1, high);
  }
}
int main(){
    int n,n1,n2,n3;
    cin>>n;
    
    int l0[n],l1[n],l2[n];
    
    for(int i=0;i<n;i++){
        cin>>l0[i];
        cin>>l1[i];
        cin>>l2[i];
    }
    int op;
    cin>>op;
    for(int i=0;i<op;i++){
        cin>>n1;
        cin>>n2;
        switch(n1){
            case 0:
                n3 = sizeof(l0) / sizeof(l0[0]);
                quickSort(l0,l1,l2,0,n3-1);
                break;
            case 1:
                n3 = sizeof(l1) / sizeof(l1[0]);
                quickSort(l1,l0,l2,0,n3-1);
                break;
            case 2:
                n3 = sizeof(l2) / sizeof(l2[0]);
                quickSort(l2,l0,l1,0,n3-1);
                break;
        }
                cout<<l0[n2]<<' ';
                cout<<l1[n2]<<' ';
                cout<<l2[n2];
                cout<<endl;
                
        }
    return 0;
    }
