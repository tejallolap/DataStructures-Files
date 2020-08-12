

/* Assignment 4: Modify the BST in assignment 3 such that the roles of the left and right pointers are swapped at every node. */

#include<iostream>
using namespace std;

class node {
	friend class bst;
	int data;
	node *left;
	node *right;
	
	public:
		node() {
			data = 0;
			left = right = NULL;
		}
};

class bst {
	node *root;
	public:
		bst() {
			root = NULL;
		}
		
		void create( int x ) {
			node *n = new node;
			n -> data = x;
			n -> left = n -> right = NULL;
			
			if( root == NULL) {
				root = n;
			}
			else {
				insert( root , n );
			}
		}
		
		void insert( node *root, node *n ) {
			node *temp;
			while( root != NULL) {			
			temp = root;
			if( n -> data < root -> data ) 
				root = root -> left;
			else
				root = root -> right;
			}	
			if( n -> data < temp -> data)
				temp -> left = n;
			else
				temp -> right = n;
		}
		
		
		void display() {
			if(root == NULL) {
          		 cout << "No elements" << endl;
       		}
      		 else {
      		 	cout<<"Inorder traversal: "<<endl;
           			inorder(root);
           			cout<<endl;
           			mirror(root);
       		}
       		
  		 }
		
		void inorder( node *root) {
			if (root)
			{
				inorder (root->left);
				cout << root->data << " ";
				inorder (root->right);
 			}
 			
 		 }
 		 
	void mirror(node *Node) {
		if( Node == NULL)
			return;
		else {
			node *t;
			//mirror(Node -> left);
			//mirror(Node -> left);
       
			t = Node -> left;
			Node -> left = Node -> right;
			Node -> right = t;
		}
		cout<<"Inorder of mirror-ed tree: "<<endl;
		inorder(Node);
		cout<<endl;
	}

	
};
 
 int main() {
    bst t;
    int ch = 1;
    int num;
    while(ch == 1) {
        cout << "Enter element to tree: " << endl;
        cin >> num;
        t.create(num);
        cout << "Enter 1 to continue or 0 to exit: "<< endl;
        cin >> ch;
    }
   
    t.display();

    return 0;
}

/* Output - Enter element to tree: 
40
Enter 1 to continue or 0 to exit: 
1
Enter element to tree: 
25
Enter 1 to continue or 0 to exit: 
1
Enter element to tree: 
78
Enter 1 to continue or 0 to exit: 
1
Enter element to tree: 
10
Enter 1 to continue or 0 to exit: 
1
Enter element to tree: 
32
Enter 1 to continue or 0 to exit: 
0
Inorder traversal: 
10 25 32 40 78 
Inorder of mirror-ed tree: 
78 40 10 25 32 
*/
