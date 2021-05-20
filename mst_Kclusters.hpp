#pragma once
#include "point.hpp"
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
// Creating shortcut for an integer pair
typedef pair<int, int> iPair;

// Structure to represent a graph
class Graph
{
public:
	point* points;
	vector< pair<double, iPair> > edges;
	int V,E;
	// Constructor
	Graph(int V, point* points);

	// Utility function to add an edge
	void addEdge(int u, int v);
	int *parent, *rnk;
	int n;


	// Find the parent of a node 'u'
	// Path Compression
	int find(int u);

	// Union by rank
	void merge(int x, int y);


// Function to find MST using Kruskal's
	// MST algorithm
	void kruskalMST_Kclusters(int k,vector<pair<int, int> >* Edges);
	void add_point(point &p, int label, int n);
};
