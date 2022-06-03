#include <iostream>
#include <bits/stdc++.h>
#include "Node.cpp"

using namespace std;

#define DUMMY 0
static int countofpositivenodes=0;

class LinkedList{
public:	
    Node *first, *last;
    
public:
	LinkedList(){	first = new Node(DUMMY);	last = NULL;	}
	void addNodeAtStart(int d){
        
        first->data+=1;//To count number of nodes (A)

		Node *newNode =new Node(d);
		newNode -> next = first -> next;
		first -> next = newNode;
		if (last == NULL)	last = newNode;
	}
	void addNodeAtEnd(int d){
        first->data+=1;
		if (last == NULL)	addNodeAtStart(d);
		else{
			last -> next = new Node(d);
			last = last -> next;
		}
	}
	void addNodeAfter(int d1, int d2){
        
        first->data+=1;//To count number of nodes (A)
		
        Node *t;
		for (t = first->next ; t != NULL && t -> data != d1; t = t -> next);
		if (t != NULL){
			Node *newNode = new Node(d2);
			newNode -> next = t -> next;
			t -> next = newNode;
			if (t == last)	last = newNode;
		}
	}
	void deleteNodeFromStart(){
        
        first->data-=1;//To count number of nodes (A)
		
        if (first->next!=NULL){
			Node *t = first -> next;
			first -> next = t -> next; //t->next may be second node or NULL
			delete t;
			if (first -> next == NULL)		last = NULL;
		}
	}
	void deleteNodeFromEnd(){
        
        first->data-=1;//To count number of nodes (A)
		
        if (last!=NULL){
			if (first -> next == last)		deleteNodeFromStart();						
			else{
				Node *t = first;
				for ( ; t->next != last; t = t -> next );//Move to second last node
				delete t->next;
				t->next = NULL;
				last = t;
			}
		}
	}


    bool printKthPositiveNode(Node *t,int k){
        if(t->next==NULL){
		    return false;
        }
        else{
            if(t->data>=0)
                countofpositivenodes++;
            if(countofpositivenodes==k){
                cout<<"OUTPUT|"<<t->data<<' ';
                return true;
                }
            t=t->next;
            return printKthPositiveNode(t,k);
             
        }
    }

    bool isSumEqual(Node *t,int requiredsum){
        if(t->next==NULL){
		    return false;
        }
        else{
            int sum=0,sum2=0;
            for(Node *check=t;check->next!=NULL;check=check->next){
                sum+=check->data;
                sum2=check->data;
                for(Node *check2=check->next;check2->next!=NULL;check2=check2->next)
                    if(sum+check2->data==requiredsum)
                        return true;
                if(sum==requiredsum)
                    return true;
            }

            t=t->next;
            return isSumEqual(t,requiredsum);
             
        }
    }

    void show(){
		if ( first -> next == NULL)
			cout << "List is empty\n";
		for ( Node *t = first /*-> next*//*to show dummy node (a)*/ ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		cout << '\n' ;
	}

};

int main(){
	LinkedList list,list_2;

cout<<"First I will Print the List After Creation"<<endl<<endl;
    
	list.addNodeAtStart(23);    
	list.addNodeAtEnd(-59);
	list.addNodeAtEnd(-37);
	list.addNodeAtEnd(46);
	list.addNodeAtEnd(64);
	list.addNodeAtEnd(-38);
	list.addNodeAtEnd(29);
	list.addNodeAtEnd(30);
	list.show();
    cout<<endl<<"This part Demostrates Part A of Question 01";
    cout<<endl<<"The First Value is The data of the Dummy Node Which Represents the Count of Nodes"<<endl;
    cout<<endl<<"Now, for same list consider k = 4"<<endl;

    
    
    if(!list.printKthPositiveNode(list.first->next,4))
        cout<<"No output and result is false."<<endl;
    else 
        cout<<"and result is true"<<endl;
    
    cout<<endl<<"Now, for same list consider k = 7"<<endl;
    
countofpositivenodes=0;//resetting Count variable

    if(!list.printKthPositiveNode(list.first->next,7))
        cout<<"No output and result is false."<<endl;
    else 
        cout<<"and result is true"<<endl;

    
    cout<<endl<<endl;
    cout<<endl<<"This part Demostrates Part B of Question 01"<<endl;
    list_2.addNodeAtStart(23);    
	list_2.addNodeAtEnd(59);
	list_2.addNodeAtEnd(37);
	list_2.addNodeAtEnd(46);
	list_2.addNodeAtEnd(64);
	list_2.addNodeAtEnd(29);
	list_2.show();
    
    cout<<"For n=123"<<endl;
    if(list_2.isSumEqual(list_2.first->next,123))
        cout<<"Result is True"<<endl;
    else cout<<"Result is False"<<endl;

    cout<<"For n=118"<<endl;
    if(list_2.isSumEqual(list_2.first->next,118))
        cout<<"Result is True"<<endl;
    else cout<<"Result is False"<<endl;
	cout<<endl<<endl;
    return 0;
}