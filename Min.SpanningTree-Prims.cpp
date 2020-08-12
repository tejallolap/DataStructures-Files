/* Name- Tejal Lolap
Batch: B1
Roll. No. : 222008
Gr. No. : 17u620 
*/

/* Assignment 4 - For a weighted graph G, find the minimum spanning tree using Prims algorithm */

#include<iostream>
using namespace std;

class prims {
	int w[20][20], p[20], dist[20], visited[20], v, e;
	public:
		void create() {
			int  i, j, a, b, weight;
			cout << "Enter the number of vertices: " << endl;
			cin >> v;
			cout << "Enter the number of edges: " << endl;
			cin >> e;
			for( i = 1; i <= v; i++ ) {
				p[i] = 0;
				visited[i] = 0;
				dist[i] = 32767; //random infinte value
				for ( j = 1; j<= v; j++ ) {
					w[i][j] = 0;
				}
			}
			
			for ( i = 1; i <= e; i++ ) {
				cout << "Enter 2 vertices and weight of the edge between them: " << endl;
				cin >> a >> b;
				cin >> weight;
				w[a][b] = w[b][a] = weight; //undirected graph
			}
		}
			
		void prim() {
			int current = 1, totalvisited = 1, i, j, d;
			dist[current] = 0;
			visited[current] = 1;
			while (totalvisited != v) {
				for ( i = 1; i <= v; i++ ) {
					if (w[current][i] != 0 ) { //edge must exist between current & i
						if (visited[i] == 0) { //vertex i should not be visited before
							if (dist[i] > w[current][i]) {
								dist[i] = w[current][i];
								p[i] = current;
							}
						}
					}
				}
				d = 32767;
				for ( i = 1; i <= v; i++ ) { //to find the edge with least weight
					if ( visited[i] == 0 ) {
						if (dist[i] < d ) {
							d = dist[i];
							current = i;
						} 
					} 
				}
				visited[current] = 1;
				totalvisited ++;
				
			}
			
			d = 0;
			for ( i = 1; i <= v; i++ ) {
				d = d + dist[i];
			}
			
			cout << "Minimum spanning tree = " << d << endl;
			for ( i = 1; i <= v; i++ ) {
				cout << "Vertices selected and the weight of their edge: " << endl;
				cout << i << " and " << p[i] << " : " << dist[i] << endl;
			}
		}	
		
		
};

int main() {
	prims p;
	p.create();
	p.prim();
	return 0;
}
				
				
						
							
			
			
					
			
		
