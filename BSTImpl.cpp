// BST
#include <iostream>

using namespace std;

struct Node{
	int data;
	Node *left, *right;
	
	Node(int val){
		data = val;
		left = right = NULL;
	}
};

Node* newNode(int val){
	return (new Node(val));	
}

Node* insert(Node *&node, int val){
	if (!node)	
		return newNode(val);
		
	else if (val > node->data) node->right = insert(node->right, val);
	else node->left = insert(node->left, val);
	
	return node;
}

void inorder(Node *node){
	if (!node)
		return;
	
	inorder(node->left);
	cout << node->data << " : ";
	inorder(node->right);	
}

void preorder(Node *node){
	if (!node)
		return;
	
	cout << node->data << " : ";
	preorder(node->left);
	preorder(node->right);
}

void search(Node *node, int val){
	if (!node)
		cout << "Node not found!";
		
	else if (node->data == val)
		cout << "Node found!";
		
	else if (val > node->data) search(node->right, val);
	else search(node->left, val);
}

int lowestCommonAncestor(Node *node, int v1, int v2){
	if(!node)
		return NULL;
		
	else if (v1 > node->data && v2 > node->data) lowestCommonAncestor(node->right, v1, v2); 
	else if (v1 < node->data && v2 < node->data) lowestCommonAncestor(node->left, v1, v2);
	
	else return node->data; 
}

int main(){
	Node *root = NULL;
	root = newNode(100);
	int choice = 1, val;
	
	while (choice){
		cout << "\nMenu\n------\n1. Insert node\n2. Inorder\n3. Preorder \n4. Search a node\n5. Lowest Common Ancestor \n6. Exit(0)\nEnter choice : ";
		cin >> choice;
		
		if (choice == 1){
			cout << "Enter value to be inserted : ";
			cin >> val;
			
			insert(root, val);
		}
		
		else if (choice == 2)
			inorder(root);
			
		else if (choice == 3)
			preorder(root);
			
		else if (choice == 4){
			cout << "Enter value to be searched : ";
			cin >> val;
			search(root, val);
		}	
	
		else if (choice == 5){
			int v1, v2;
			cout << "Enter the values : ";
			cin >> v1 >> v2;
			
			cout << lowestCommonAncestor(root, v1, v2);	
		}
		
		else if (choice == 6)
			choice = 0;
	}
	return 1;
}
