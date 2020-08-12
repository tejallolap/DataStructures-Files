
/*Assignment 5: Represent a given graph using adjacency matrix and traverse each node using Depth first search*/

#include<iostream>
using namespace std;

class graph {
	int** gmatrix;
	int *visited;
	int *stack;
	int top;
	public:
		graph(int n) {
			gmatrix = new int*[n];
			visited = new int[n];
			stack = new int[n];
			top = -1;
			for ( int i = 1; i <= n; i++ ) {
				gmatrix[i] = new int[n];
				visited[i] = 0;
				//stack[i] = 0;
				for ( int j = 1; j <= n; j++ ) {
					gmatrix[i][j] = 0;
				}
			}
		}
		
		void addedge (int v1, int v2) {
			gmatrix[v1][v2] = 1;
			//gmatrix[v2][v1] = 1;
		}
		
		/*void removeedge ( int v1, int v2) {
			gmatrix[v1][v2] = 0;
			gmatrix[v2][v1] = 0;
		}*/
		
		void display (int n) {
			cout << "The adjacency matrix is: " <<endl;
			for( int i = 1; i <= n; i++) {
				for( int j = 1; j <= n; j++) {
					cout << gmatrix[i][j];
					cout << " ";
				}
				cout<<endl;
			}
			cout << "where 1 denotes an edge is present" <<endl;
		}
		
		/*void dfs (int v, int n ) {			
			int  i;						
			cout << v << " ";
			visited[v] = 1;
			for( i = 0; i < n; i++ ) {
				if (gmatrix[v][i] == 1 && !visited[i]) {	
					dfs(i,n);						
				}
			}
		}*/
		
		void push (int val) {
			
				top ++;
				stack[top] = val;				
			
		}
		
		int pop() {
		
				int v = stack[top];
				top --;				
				return(v);
			
		}
				
			
		void dfs ( int n ) {
			int vtx;
			cout << "Enter the vertex you want to begin with: " <<endl;
			cin>>vtx;
			
			cout << "Depth First Search: " << endl;
			int v, i;
			push (vtx);
			while (top != -1){ 
				v = pop();
				
				if( !visited[v] ) {
					cout << v << " ";
					visited[v] = 1;
				}
			
			
				for( i = 1; i <= n; i++ ) {
					if ( gmatrix[v][i] == 1 && !visited [i] ) {
							push (i);
					}						
				}			
			}
		}
		
									
};		
			

int main() {
	int v, n = 0, i;
	char ch = 'y', ch2 = 'y';
	while(ch == 'y') {
		cout << "Enter the vertex: " << endl;
		cin >> v;
		n ++;
		cout << "Enter y to continue or n to exit: " << endl;
		cin >> ch;
	}
	
	cout << "The number of vertices are: " << n << endl;
	
	int v1, v2;
	graph g(n);
	while (ch2 == 'y') {
		cout << "Enter vertices to add an edge in between : " << endl;
		cin >> v1;
		cin >> v2;
		g.addedge(v1, v2);
		cout << "Enter y to add more edges or n to exit: " << endl;
		cin >> ch2;
	}
	
	g.display(n);
	
	g.dfs(n);
	return 0;
}

/* Output - Enter the vertex: 
1
Enter y to continue or n to exit: 
y
Enter the vertex: 
2
Enter y to continue or n to exit: 
y
Enter the vertex: 
3
Enter y to continue or n to exit: 
y
Enter the vertex: 
4
Enter y to continue or n to exit: 
n
The number of vertices are: 4
Enter vertices to add an edge in between : 
1
2
Enter y to add more edges or n to exit: 
y
Enter vertices to add an edge in between : 
1
3
Enter y to add more edges or n to exit: 
y
Enter vertices to add an edge in between : 
2
3
Enter y to add more edges or n to exit: 
y
Enter vertices to add an edge in between : 
3
1
Enter y to add more edges or n to exit: 
y
Enter vertices to add an edge in between : 
3
4
Enter y to add more edges or n to exit: 
y
Enter vertices to add an edge in between : 
4
4
Enter y to add more edges or n to exit: 
n
The adjacency matrix is: 
0 1 1 0 
0 0 1 0 
1 0 0 1 
0 0 0 1 
where 1 denotes an edge is present
Enter the vertex you want to begin with: 
2
Depth First Search: 
2 3 4 1
*/	
	
		
		
