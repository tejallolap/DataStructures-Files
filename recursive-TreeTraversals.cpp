

/*Assignment 1: Construct an expression tree from postfix expression and perform recursive
Inorder, Preorder and Post order traversals*/



#include<iostream>
using namespace std;
// treenode class containing data as well as create() function for creating a tree-node

class treenode{
		public:
			char expression;
			treenode *lptr;
			treenode *rptr;

			treenode()
			{
				lptr=rptr=NULL;
			}

		treenode *create(char c,treenode *l,treenode *r)
		{
			treenode *newnode;
			newnode=new treenode;
			newnode->expression=c;
			newnode->lptr=l;
			newnode->rptr=r;
			return newnode;
		}
};

// node() function for having data which we want the node of a stack to contain

class node{

		public:
			treenode *tptr;
			node *nxt;
};

// stack() function containing push(),pop() and display() functions

class stack{

		public:
		node *top;
		stack()
		{
			top=NULL;
		}

		void push(treenode *a){
			node *b;
			b=new node;
			b->tptr=a;
			b->nxt=NULL;
			if(top)
			{
				b->nxt=top;
				top=b;		}
			else{
				top=b;
			}
		}

		treenode *pop()
		{
				node *a;
				a=top;
				top=top->nxt;
				treenode *tn=a->tptr;
				delete a;
				return (tn);
		}

		void display()
		{
			cout<<"\n The inorder traversal of entered postfix expression : ";
			displayinorder(top->tptr);
			cout<<"\n The pre-order traversal of entered postfix expression : ";
			displaypreorder(top->tptr);
			/*cout<<"\n The post-order traversal of entered postfix expression : ";
			displaypostorder(top->tptr);*/
			cout<<"\n\n";
		}
		void displayinorder(treenode *root)
		{
			if(root)
			{
				displayinorder(root->lptr);
				cout<<root->expression;
				displayinorder(root->rptr);
			}	
		}

		void displaypreorder(treenode *root)
		{
			if(root)
			{
				cout<<root->expression;
				displaypreorder(root->lptr);
				displaypreorder(root->rptr);
			}
		}

		/*void displaypostorder(treenode *root)
		{
			if(root)
			{
				displaypostorder(root->lptr);
				displaypostorder(root->rptr);
				cout<<root->expression;
			}
		}*/
	};
int main()
{
		char e[50];
		// we'll enter a postfix expression having maximum length of 50 characters
		cout<<"\n enter the postfix expression : ";
		cin>>e;

		stack s;
		treenode t,*tn,*l,*r;

		for(int i=0;e[i]!='\0';i++)
		{
			// checking if the entered character is an alphabet (operand)
			if(((e[i]>=65)&&(e[i]<=90))||((e[i]>=97)&&(e[i]<=122)))
			{
				tn=t.create(e[i],NULL,NULL);
				s.push(tn);
			}
			else
			{
				// checking if the entered character is an operator
				r=s.pop();
				l=s.pop();
				tn=t.create(e[i],l,r);
				s.push(tn);
			}
}		
s.display();		
return 0;	
}