#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

static int arraysize=0;

#define NONODE -1

class BSTreeArray{
	int *x, size;
public:
	BSTreeArray(const int SIZE){
		size = SIZE;
		this->x = new int[size];
		for (int i=0;i<size;i++)
			x[i] = NONODE;
	}
	//Worker Function
	void insert(int index, int data){
		if (index>=size)	return;
		if (x[index] == NONODE)	{
			x[index] = data;
			return;
		}
		if (x[index]>data)	
			insert(index*2, data);
		else
			insert(index*2+1, data);
	}
	//Wrapper Function
	void insert(int data){
		insert(1, data);
	}
	int findHighest(int index){
		while (index*2+1 < size && x[index*2+1]!=NONODE)
			index = index * 2 + 1;
		return index;
	}
	int findLowest(int index){
		while (index*2 < size && x[index*2]!=NONODE)
			index = index * 2 ;
		return index;
	}
	bool isNode(int index){
		if (index<size && x[index] != NONODE)	return true;
		return false;
	}
	void deleteNode(int index, int data){
		if (index>=size)		return;
		if (x[index]== NONODE)	return;
		if (x[index]>data)	
			deleteNode(index*2, data);
		else if (x[index]<data)
			deleteNode(index*2+1, data);
		else{//data found
			if (!isNode(index*2) && !isNode(index*2+1)){
				x[index] = NONODE;
				return;
			}
			else if (!isNode(index*2)){
				int lowestIndex = findLowest(index*2+1);
				x[index] = x[lowestIndex];
				deleteNode (lowestIndex, x[lowestIndex]);
			}
			else{
				int highestIndex = findHighest(index*2);
				x[index] = x[highestIndex];
				deleteNode (highestIndex, x[highestIndex]);
			}
		}	
	}	
	void deleteNode(int data){
		deleteNode(1, data);
	}
	int findNode(int index, int data){
		if (index>=size)		return -1;
		if (x[index]== NONODE)	return -1;
		if (x[index]>data)	
			return findNode(index*2, data);
		else if (x[index]<data)
			return findNode(index*2+1, data);
		else
			return index;
	}	
	int findNode(int data){
		return findNode(1, data);
	}
	void inOrder(int i){
		if (i >= size || x[i] == NONODE)
			return;
		inOrder(2*i);
		cout << x[i] << ' ';
		inOrder(2*i+1);
	}
	void inOrder(){
		inOrder(1);
		cout << '\n';
	}
	int findHeight(int i){
		if (i>=size || x[i]==NONODE)	return -1;
		int h1 = findHeight(2*i);
		int h2 = findHeight(2*i+1);
		if (h1 > h2)	return h1+1;
		else 			return h2+1;
	}
	int findHeight(){
		return findHeight(1);
	}
	
	/*This is the Task Part*/

	int sumBST(int i){
		if(i >= size || x[i]==NONODE)
			return 0;
		return (x[i] + sumBST(2*i+1) + sumBST(2*i));
	}

	int CountSubNodes(int i){
		if(i >= size || x[i]==NONODE)
			return 0;
		return (1 + CountSubNodes(2*i+1) + CountSubNodes(2*i));
	}

	void CompareBST(BSTreeArray &T){
		if(CompareBSTrecursive(1,T))
		 	cout<<"Both Trees are identical";
		else cout<<"Both Trees are different";
	}

	bool CompareBSTrecursive(int i,BSTreeArray &T){
		if (T.x[i] == NONODE || x[i] == NONODE)
			return	true;
		else if (T.x[i] != NONODE && x[i] == NONODE)
        	return false;
    	else if (T.x[i] == NONODE && x[i] != NONODE)
        	return false;
		
		else{
			if(T.x[i]==x[i] && CompareBSTrecursive(2*i,T) && CompareBSTrecursive(2*i+1,T))
				return true;
			else return false;
		}
	}

	static void IsTree(int arr[]){
		
		if(IsTreeRecursive(1,arr))
		 	cout<<"This Array is a Tree";
		else cout<<"This Array is a Not Tree";
	
	}

	static bool IsTreeRecursive(int i,int *arr){
		if (i>arraysize)
			return true;
		else{
			if((i*2+1)<=arraysize){
				if(arr[i] < arr[2*i] && arr[i] < arr[2*i+1] && IsTreeRecursive(2*i,arr) &&  IsTreeRecursive(2*i+1,arr))
					return true;
				else return false;
			}
			else if((i*2)<=arraysize){
				if(arr[i] < arr[2*i] && IsTreeRecursive(2*i,arr))
					return true;
				else return false;
			}
			else return true;
		}
	}

	~BSTreeArray(){	delete []x;	}
};
int main(){
	srand(time(0));
	int d ;
	BSTreeArray tree(204),t1(250),t2(260),t3(25),t4(25);
	for (int i=0;i<20;i++){
		d = rand()%500;
		tree.insert(d);
	}
	cout << '\n';
	tree.inOrder();


	cout<<"Sum is "<<tree.sumBST(1);
	cout<<endl<<"Count from 1st Node(Total Count): "<<tree.CountSubNodes(1);
	cout<<endl<<"Count from 7th Node: "<<tree.CountSubNodes(7);


	for (int i=0;i<20;i++){
		d = rand()%500;
		t1.insert(d);
		t2.insert(d);
	}
	cout<<endl<<"\nGenerated T1: ";
	t1.inOrder();
	cout<<"Generated T2: ";
	t2.inOrder();
	cout<<endl<<"Comparing T1 & T2\n";
	t1.CompareBST(t2);
	cout<<endl;

	for (int i=0;i<20;i++){
		d = rand()%50;
		t3.insert(d);
	}
	for (int i=0;i<20;i++){
		d = rand()%50;
		t4.insert(d);
	}
	cout<<endl<<"\nGenerated T3: ";
	t3.inOrder();
	cout<<"Generated T4: ";
	t4.inOrder();
	cout<<endl<<"Comparing T3 & T4\n";
	t3.CompareBST(t4);
	cout<<endl<<endl;
	
	arraysize=6;
	//to save memory and not make array size a local for 
	//each recursive call i have a static int for array size
	//also i used a static function to check array if it is a tree
	//so that i can call it without making an object

	int arr[] = { 0,19, 23, 25, 30, 45 ,100};
	
	cout<<"Checking Is array  { 0,19, 23, 25, 30, 45 ,100} a Tree or Not\n";
	
	BSTreeArray::IsTree(arr);

	int arr1[] = { 0,19, 23, 30, 25, 45 , 19};

	cout<<endl<<"\nChecking Is array  { 0,19, 23, 30, 25, 45 , 19} a Tree or Not"<<endl;

	BSTreeArray::IsTree(arr1);

	return 0;
}
