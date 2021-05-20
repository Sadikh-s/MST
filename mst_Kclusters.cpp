// C++ program for Kruskal's algorithm to find Minimum
// Spanning Tree of a given connected, undirected and
// weighted graph
#include "mst_Kclusters.hpp"
#include<bits/stdc++.h>
using namespace std;
#include "point.hpp"
#include <iostream>
#include <vector>


int Graph::find(int u)
	{
		/* Make the parent of the nodes in the path
		from u--> parent[u] point to parent[u] */
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

void Graph::merge(int x, int y)
	{
		x = find(x), y = find(y);

		/* Make tree with smaller height
		a subtree of the other tree */
		if (rnk[x] > rnk[y])
			parent[y] = x;
		else // If rnk[x] <= rnk[y]
			parent[x] = y;

		if (rnk[x] == rnk[y])
			rnk[y]++;
	}
void Graph::add_point(point &p, int label, int n) {
	int d=p.get_dim();
    for(int m = 0; m < d; m++) {
        points[n].coords[m] = p.coords[m];
    }
    points[n].label = label;

    n++;
}
Graph::Graph(int V, point* points_)
	{  
		this->V = V;
		this->E = V*(V-1);
		for(int i=0;i<V;i++){
			add_point(points_[i],0,i);
			for(int j=0;j<i;j++){
				addEdge(j,i);
			}
		}
		this->n = n;
		parent = new int[n];
		rnk = new int[n];

		// Initially, all vertices are in
		// different sets and have rank 0.
		for (int i = 0; i < n; i++)
		{
			rnk[i] = 0;

			//every element is parent of itself
			parent[i] = i;
		}
	}

void Graph::addEdge(int u, int v)
	{
		edges.push_back({points[v].dist(points[u]), {u, v}});
	}

/* Functions returns weight of the MST*/
void Graph::kruskalMST_Kclusters(int k, vector<pair<int, int> >* Edges)
{  

	// Sort edges in increasing order on basis of cost
	sort(edges.begin(), edges.end());

	int i=0;

	// Iterate through all sorted edges
	vector< pair<double, iPair> >::iterator it;
	for (it=edges.begin(); it!=edges.end() && i<V-k; it++)
	{																							
		int u = it->second.first;
		int v = it->second.second;

		int set_u = find(u);
		int set_v = find(v);

		// Check if the selected edge is creating
		// a cycle or not (Cycle is created if u
		// and v belong to same set)
		if (set_u != set_v)
		{
			// Merge two sets
			merge(set_u, set_v);
			Edges->push_back({u,v});
			i++;
		}
	}int* label =new int [V];
	int j=0;
	for(int i=0;i<V;i++){
		if(parent[i]==i)label[i]=j++;
	}
	for(int i =0;i<V;i++){
		points[i].label=label[find(i)];
	}
}

// Driver program to test above functions
int main(){


	return 0;}
