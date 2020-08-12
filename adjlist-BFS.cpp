
/* Assignment 6 - Represent a given graph using adjacency list and traverse each node using Breadth first search. */

#include<iostream>
#include<queue>
using namespace std;

class node {
	friend class link;
	private:
		int data;
		node *next;
	public:
		void assign(int d) {
			data = d;
		}
		int get_data() {
			return data;
		}
		node* get_next() {
			return next;
		}
};

class link {
	private:
		node *start;
		int v;
	public:
		link(int x) {
			start = NULL;
			v =x;
		}
		void append(int y) {
			node *n = new node;
			n->assign(y); //n->data = y
			if(start == NULL) {
				start = n;
			}
			else {
				node *temp = start;
				while(temp->next != NULL)
					temp = temp->next;
				temp->next = n;
			}
		}
		void print() {
			node *temp = start;
			while(temp != NULL) {
				cout<<temp->data<<" ";
				temp = temp->next;
			}
		}
		
		node* get_start() {
			return start;
		}
};


void make_graph(link *g[], int v) {
    //cout<<"Enter 1 if edge is present between x->y. If not, enter 0.\n";
	char ch;
	do {
		cout<<"Enter the edge pair : ";
		int x,y;
		cin>>x>>y;
		if(x>0 && y>0 && x<=v && y<=v) {
			g[x-1]->append(y);
		}
		cout<<"Do you want to enter any other edge ? (y/n) : ";
		cin>>ch;
	} while(ch=='y' || ch=='Y');
}

void display(link *g[], int v) {
	for(int i=0; i<v; i++) {
		g[i]->print();
		cout<<endl;
	}
}

void bfs(link *g[], int v) {
	queue <int> q;
	int *check = new int[v]; //visited array
	node *temp = g[0]->get_start(); //access head of linked list of first vertex
	q.push(temp->get_data());
	while(!q.empty()) {
		int d = q.front();
		q.pop();
		
		if(check[d-1]==0) { //checks if visited
			cout<<d<<"  ";
			check[d-1] =1; //marks as visited
		}
		temp = g[d-1]->get_start(); //access head of linked list of vertex in 'd'
		
		if(temp->get_next() != NULL) { //checks if it has adjacent vertices in the adjacency list
			temp = g[d-1]->get_start()->get_next(); //goes to adjacent vertex // head -> next
			while(temp!=NULL) {
				q.push(temp->get_data()); //pushes all adjacent vertices onto queue
				temp = temp->get_next(); //goes to next adjacent vertex
			}
		}
	}
}

int main() {
	cout<<"Enter the number of vertices in the graph : ";
	int v;
	cin>>v;
	link *g1[v]; // array of linked lists
	for(int i =0;i<v;i++) {
		g1[i] = new link(v);
		g1[i]->append(i+1);
	}
	make_graph(g1,v);
	cout << "Adjacency list: " <<endl;
	display(g1,v);
	cout<<"The Breadth First Search traversal is: "<<endl;
	bfs(g1,v);
	cout<<endl;	
	return 0;
}

