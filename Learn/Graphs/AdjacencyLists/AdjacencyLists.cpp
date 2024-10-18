//
//  AdjacencyLists.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 18.10.2024.
//

//
//	Adjacency List = An array/arraylist of linkedlists. Each LinkedList has a unique node at the head.
//					 All adjacent neighbors to that node are added to that node's linkedlist
//
//	Runtime complexity to check an Edge: O(n)
//	Space complexity: O(n+e)
//

#include "AdjacencyLists.hpp"
#include <iostream>
#include <vector>
#include <list>

using namespace std;

void addNodeLists(vector<char>& nodes, char node){
	nodes.push_back(node);
}

void addEdgeLists(vector<list<int>>& list, int source, int destination){
	list[source].push_back(destination);
}

bool checkEdgeLists(vector<list<int>>& list, int source, int destination){
	for (int node : list[source]) {
		if (node == destination) {
			return true;
		}
	}
	return false;
}

void printGraphLists(const vector<list<int>>& list, const vector<char>& nodes, int size){
	for (int i = 0; i < size; i++) {
		cout << nodes[i] << " -> ";
		for (int adj : list[i]) {
			cout << nodes[adj] << " -> ";
		}
		cout << "nullptr" << endl;
	}
}

void displayAdjacencyLists(){
	int vertices = 5;

	vector<char> nodes;
	vector<list<int>> list(vertices);

	// Add nodes
	addNodeLists(nodes, 'A');
	addNodeLists(nodes, 'B');
	addNodeLists(nodes, 'C');
	addNodeLists(nodes, 'D');
	addNodeLists(nodes, 'E');

	// Add edges between nodes
	addEdgeLists(list, 0, 1); // A -> B
	addEdgeLists(list, 1, 2); // B -> C
	addEdgeLists(list, 1, 4); // B -> E
	addEdgeLists(list, 2, 3); // C -> D
	addEdgeLists(list, 2, 4); // C -> E
	addEdgeLists(list, 4, 0); // E -> A
	addEdgeLists(list, 4, 2); // E -> C

	// Checking if an edge exists between B and E (1 -> 4)
	if (checkEdgeLists(list, 1, 4)) {
		cout << "Edge exists between A and B." << endl;
	} else {
		cout << "No edge between A and B." << endl;
	}

	// Print the adjacency matrix
	printGraphLists(list, nodes, vertices);
}
