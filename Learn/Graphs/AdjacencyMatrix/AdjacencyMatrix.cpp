//
//  AdjacencyMatrix.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 10.10.2024.
//

//	Adjacency Matrix = An array to store (0 / 1) to represent edges
//		# of rows = number of unique nodes
//		# of columns = number of unique nodes

//	Runtime complexity to check an Edge: O(1)
//	Space complexity: O(n^2)

#include "AdjacencyMatrix.hpp"
#include <iostream>
#include <vector>

using namespace std;

void addNode(vector<char>& nodes, char node){
	nodes.push_back(node);
}

void addEdge(vector<vector<int>>& matrix, int source, int destination){
	matrix[source][destination] = 1;
}

bool checkEdge(vector<vector<int>>& matrix, int source, int destination){
	return matrix[source][destination] == 1;
}

void printGraph(const vector<vector<int>>& matrix, const vector<char>& nodes, int size){
	// Print the node labels for columns
	cout << "  ";
	for (int i = 0; i < size; i++) {
		cout << nodes[i] << " ";
	}
	cout << endl;

	// Print each row of the adjacency matrix
	for (int i = 0; i < size; i++) {
		cout << nodes[i] << " ";
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void displayAdjacencyMatrix(){
	int vertices = 5;

	vector<char> nodes;
	vector<vector<int>> matrix(vertices, vector<int>(vertices, 0));

	// Add nodes
	addNode(nodes, 'A');
	addNode(nodes, 'B');
	addNode(nodes, 'C');
	addNode(nodes, 'D');
	addNode(nodes, 'E');

	// Add edges between nodes (as per your Java code)
	addEdge(matrix, 0, 1); // A -> B
	addEdge(matrix, 1, 2); // B -> C
	addEdge(matrix, 1, 4); // B -> E
	addEdge(matrix, 2, 3); // C -> D
	addEdge(matrix, 2, 4); // C -> E
	addEdge(matrix, 4, 0); // E -> A
	addEdge(matrix, 4, 2); // E -> C

	// Checking if an edge exists between B and E (1 -> 4)
	if (checkEdge(matrix, 1, 4)) {
		cout << "Edge exists between A and B." << endl;
	} else {
		cout << "No edge between A and B." << endl;
	}

	// Print the adjacency matrix
	printGraph(matrix, nodes, vertices);
}
