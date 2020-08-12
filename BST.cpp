

/* Assignment 3: Construct binary search tree by inserting the values in the order given. After constructing a binary search tree,
i. Insert new node
ii. Find number of nodes in longest path along with its height
iii. Minimum data value found in the tree */


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
		 		int h;
		 		h = height(root);
		 		cout<<"Height= "<<h-1<<endl;
		 		minimum();
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
 		 
		int height(node *n) {
			if(n == NULL)
				return 0;
			else {
				int LH =0;
				int RH=0;
				LH = height(n -> left);
				RH = height(n -> right);
				if(LH > RH)
					return(LH + 1);
				else
					return(RH + 1);  
			}
		}

		void minimum() {
			node *temp = root;
			while( temp -> left != NULL) {
				temp = temp -> left;
			}
			cout<<"Minimum value in tree is: "<<endl;
			cout << temp->data << endl;
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
Height= 2
Minimum value in tree is: 
10
*/

