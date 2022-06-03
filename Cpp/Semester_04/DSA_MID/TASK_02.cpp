#include <iostream>

#include "DNode.cpp"

using namespace std;

#define DUMMY 0
static int count=1;//This val is 1 Cause of my logic that head is always there and how i counted nodes
class DHCLList{
	DNode *head;
public:
	DHCLList(){	head = new DNode(DUMMY);	head -> next = head -> prev = head;	}
	void addNodeAtHead(int d){
		DNode *newNode =new DNode(d, head, head->next);
		head -> next -> prev = newNode;
		head -> next = newNode;
	}
	void addNodeAtTail(int d){
		DNode *newNode =new DNode(d, head->prev, head);
		head -> prev -> next = newNode;
		head -> prev = newNode;
	}
	void print(DNode *t){
		if (t == head)	return;
		cout << t -> data << ' ';	
		print(t->next);
	}
	void print(){
		print(head->next);
		cout << '\n';	
	}
	
	DNode* search(int val,DNode *t){
		for(;t!=head;t=t->next){
			if(t->data==val)
			return t;
		}
		return NULL;
	}
	
	
	void swapNodes( int d1, int d2){
		DNode *N1 = NULL;
		DNode *N2 = NULL;
		DNode *temp = head;

		for (int i = 0; i < count; i++){
			
			if (temp->data==d1)
				N1 = temp;
			else if (temp->data==d2)
				N2 = temp;
			temp = temp->next;
			if (N1 && N2)
				break;
		}
		//Checking Boundary Cause of Head
		if (!N1 || !N2)
			return ;
		else if (N1 == N2)
			return ;

		DNode temp2=*N1;
		*N1=*N2;
		*N2=temp2;

		N2->next = N1->next;
		N2->prev = N1->prev;

		N1->next = temp2.next;
		N1->prev = temp2.prev;
	}
	
	void reverse(){
    DNode *current=head;
    DNode *prev=NULL;
    while(current!=NULL){
        current->prev=current->next; 
        current->next=prev;          
        prev=current;                
        current=current->prev;       
    }
        head=prev;
	}
	void count_nodes(){
		DNode *t=head;
		for(;t->next!=head;t=t->next)
			count++;
	}//this Function Gives Number of Nodes
};

int main(){
	DHCLList list;
	list.addNodeAtTail(23);
	list.addNodeAtTail(13);
	list.addNodeAtTail(53);
	list.addNodeAtTail(83);
	list.addNodeAtTail(73);
	list.addNodeAtTail(43);
	list.addNodeAtTail(93);
	list.count_nodes();
	cout<<"First Doubly List With no Modification"<<endl;
	list.print();cout<<endl;
	list.swapNodes(23,93);
	cout<<"Second Doubly List With Nodes 23 and 93 Swapped.\nHere Head Swap is Tested.\n";
	list.print();cout<<endl;
	cout<<"Now Tried to Swap 733 and 93 where 733 does'nt Exist.\nPrints Nothing Cause Does nothing\n"<<endl;
	list.swapNodes(733,93);
	cout<<"Normal case Tested with Nodes 73 and 83 Swapped.\n";
	list.swapNodes(73,83);
	list.print();cout<<endl;
	cout<<"Reversed the Final List in this Case.\n";
	list.reverse();
	list.print();cout<<endl;
	return 0;
}
