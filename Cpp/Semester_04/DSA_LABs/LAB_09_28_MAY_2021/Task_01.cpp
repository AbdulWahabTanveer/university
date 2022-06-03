#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cmath>

using namespace std;

class BST{
	struct BTNode{
		int data;
		BTNode *left, *right;
		BTNode(int data, BTNode *left=NULL, BTNode *right=NULL){
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};
	BTNode *root;
public:
	BST(){	root = NULL;	}
	BTNode* add(int d, BTNode *t){	
		if (t==NULL)	return new BTNode(d);
		if (t->data>d) 		t->left = add(d, t->left);
		else if (t->data<d) t->right = add(d, t->right);
		return t;	
	}
	void add(int d){	
		root = add(d, root);
	}
	void inorder(BTNode* t){
		if (t!=NULL){
			inorder(t->left);
			cout << t->data << ' ';
			inorder(t->right);
		}
	}
	void inorder(){
		inorder(root);
		cout << '\n';
	}
	void preorder(BTNode* t){
		if (t!=NULL){
			cout << t->data << ' ';
			preorder(t->left);
			preorder(t->right);
		}
	}
	void preorder(){
		preorder(root);
		cout << '\n';
	}
	
	int countNodes_recursive(BTNode *t){
		int count = 1;
		if (root->left != NULL) {
		count += countNodes_recursive(root->left);
		}
		if (root->right != NULL) {
			count += countNodes_recursive(root->right);
		}
		return count;
	}
	
	int countNodes(BTNode *t){
		int count = 0;
		if (t != NULL) {
			count++;
			count = countNodes(t);
		}
		return count;
	}
	int height(BTNode* node){
		if (node == NULL)
			return 0;
		else{
			int lheight = height(node->left);
			int rheight = height(node->right);
		
			if (lheight > rheight)
				return(lheight + 1);
			else return(rheight + 1);
		}
	}

	int inOrderArray(BTNode *t, int *array, int index){
		
		if (t!=NULL){
			int index = 0; 
			inOrderArray(root->left,array,index); 
			array[index++] = root->data; 
			inOrderArray(root->right,array,index+1); 
			return index;
		}
		return index;
	}
	int inOrderArrayCaller(int *array, int index){
		inOrderArray(root,array,index);
	}
	void addBinarySearch(int *array, int start, int end){
		if (start<=end){
			int middle=(start+end)/2;
			//add element in BST from middle 
			//call same function for left sub-array
			//call same function for right sub-array
		}		
	}
	void storeNodes(BTNode* root, BTNode* nodes[]){
		int count=0;
		if (root==NULL)
			return;
		storeNodes(root->left, nodes);
		nodes[count++]=root;
		storeNodes(root->right, nodes);
		}
	
	BTNode* buildTree(BTNode* nodes[], int start,int end){

		if (start > end)
			return NULL;
	
		int mid = (start + end)/2;
		root = nodes[mid];
  
		root->left  = buildTree(nodes, start, mid-1);
		root->right = buildTree(nodes, mid+1, end);
	
		return root;
	}

	void checkAndBalanceTree(int countNodes){

		BTNode* nodes[countNodes];
		storeNodes(root, nodes);
		int n = countNodes;
		buildTree(nodes, 0, n-1);
	}

	void checkAndBalance(){
		if (!root) {
		return;
		}

		int leftHt = height(root->left);
		int rightHt = height(root->right);

		if (abs(leftHt - rightHt) > 1) {
		checkAndBalanceTree(countNodes(root));}
	}

	void removeNodes(BTNode* t){
	
		if (root == NULL) return; 
	
		removeNodes(t->left); 
		removeNodes(t->right); 
		
		delete t;
	} 

	~BST(){
		removeNodes(root);
	}
};

int main(){
	srand(time(0));
	BST tree;
	for (int i=0;i<20;i++)
		tree.add(rand()%900+100);
	tree.preorder();
	tree.inorder();
	tree.checkAndBalance();
	tree.preorder();
	tree.inorder();
	int array[1000];
	tree.inOrderArrayCaller(array,0);

	return 0;
}