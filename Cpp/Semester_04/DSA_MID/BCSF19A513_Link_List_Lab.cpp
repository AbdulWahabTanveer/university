#include <iostream>
#include <bits/stdc++.h>
#include "Node.cpp"

using namespace std;

#define DUMMY 0

class LinkedList{
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

    //Part B
    void split_function(){
        Node *t = first;
        for ( ; t != NULL; t = t -> next )
            if(t->data>50){
                addNodeAfter(t->data,0);
                if(t->data%2==0){
                    t->data/=2;
                    t->next->data=t->data;
                }
                else if(t->data%2!=0){
                    t->data/=2;// 53\2 == 26  so we store 27 and 26
                    t->next->data=t->data;
                    t->data++;
                }
            }
    }
    //Ends here (B)

    //Part C starts here
    bool check_through_stack(){
        Node *t=first->next;stack <int> s;
        for ( ; t != NULL; t = t -> next ){
            s.push(t->data);
        }
        t=first->next;
        for ( ; t != NULL; t = t -> next ){
            if(t->data != s.top()){
                return false;
            };
            s.pop();
        }
        return true;
    }
    //imlplemented stacks rule of 1st in last out to check the
    //array in reverse order

    void reverse(Node *t){
        if(t->next==NULL){
		    return;
        }
        else{
            t=t->next;
            reverse(t);
            cout<<t->data<<" ";
            return;
        }
    }
    //Recursive Function to print link List in reverse Order

    bool palindrome(){
		if ( first -> next == NULL)
			cout << "List is empty\n";
		else{
            for ( Node *t = first -> next ; t != NULL ; t = t -> next )
			cout << t -> data << ' ';
		    cout << '\n' ;
            reverse(first);}
        cout<<endl;
        return check_through_stack();
	}
    //Main Palindromic Function to Call other As well

    //Part C ends Here


    //Part D starts Here
    void Delete_Neg(){
         Node *t = first,*temp;
        for ( ; t->next != NULL; t = t -> next ){
            
            if(t->next->data<0){//Checks for the next node's value for negative
                
                first->data-=1;//To update Dummy
                
                temp=t->next->next;
                delete t->next;
                t->next=temp;
                }//If the value is negative we delete that node but 
                //preserve the address of the next node after it
        }
        t=first;
        for ( ; t->next != NULL; t = t -> next ){
            if(t->next->data<0){
                first->data-=1;
                temp=t->next->next;
                delete t->next;
                t->next=temp;
                }
        }
    //In order to remove consective Negative value
    //according to my algo I used 2 passes 
    //Because in first pass only 1 of the consective negative value
    //will be deleted

    }
    //Part D ends Here


	//Part E starts from here
    void add_element(int element){
        Node *t=first;bool check=false;
        for(;t!=NULL;t=t->next){
            if(t->data==element)
                check=true;
        }//Checks for repeatition
        if(!check)
            addNodeAtEnd(element);
    }//Adds Otherwise
    
    void add_array(int arr[],int element_count){
        for(int i=0;i<element_count;i++)
            add_element(arr[i]);
    }
    //Part E ends Here

    // F starts here
    void show_in_pairs(){
		if ( first -> next == NULL)
			cout << "List is empty\n";
		for ( Node *t = first -> next ; t -> next!= NULL ; t = t -> next )
			cout << t -> data << ' '<<t -> next -> data << endl;
		cout << '\n' ;
	}
    //Ends here (F)


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

    //Preparing list 2 for Palindromic Example
    list_2.addNodeAtEnd(3);
    list_2.addNodeAtEnd(6);
    list_2.addNodeAtEnd(0);
    list_2.addNodeAtEnd(6);
    list_2.addNodeAtEnd(3);

    //Demonstration of A
    cout<<"This part Demostrates Part A";
    cout<<endl<<"The First Value is The data of the Dummy Node Which Represents the Count of Nodes"<<endl;
	list.addNodeAtStart(23);    
	list.addNodeAtStart(-31);
	list.addNodeAtEnd(45);
	list.addNodeAtEnd(13);
	list.show();
	list.addNodeAtStart(-11);
	list.addNodeAtEnd(63);
	list.show();
	list.addNodeAfter(63,66);
	list.show();
    list.addNodeAtStart(23);
    list.show();
	list.deleteNodeFromStart();
	list.deleteNodeFromEnd();
    list.show();

cout<<"-----------------------------------------------------"<<endl<<endl;

    //Demonstration of B
    cout<<"List After the Split Function is Called. Demostration of B"<<endl;
    list.split_function();
    list.show();

cout<<"-----------------------------------------------------"<<endl<<endl;

    //Demonstration of C
    cout<<"Demostration of Palindrome"<<endl;
    cout<<"Note that the Dummy Count is not a Part of Output Here"<<endl<<endl;
    if(list.palindrome())
        cout<<"Its A Palindrome"<<endl<<endl;
    else 
        cout<<"Its Not A Palindrome"<<endl<<endl;
    if(list_2.palindrome())
        cout<<"Its A Palindrome"<<endl;
    else 
        cout<<"Its Not A Palindrome"<<endl;

cout<<"-----------------------------------------------------"<<endl<<endl;

    //Demonstration of D
    cout<<"Demonstration of D Removing Negative Values"<<endl;
    list.Delete_Neg();
    list.show();

cout<<"-----------------------------------------------------"<<endl<<endl;

    //Demonstration of E
    cout<<"Demonstration of E Adding an Array in the List"<<endl;
    int arr[5]={13,23,66,96,109};
    list.add_array(arr,5);
    list.show();

cout<<"-----------------------------------------------------"<<endl<<endl;

    //Demonstration of F
    cout<<"Demonstration of F Showing Values in Pairs"<<endl;
    cout<<"Note that the Dummy Count is not a Part of Output Here"<<endl;
    list.show_in_pairs();
	return 0;
}