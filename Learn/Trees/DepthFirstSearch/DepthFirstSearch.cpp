//
//  DepthFirstSearch.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 18.10.2024.
//

//
//	DFS = a search algorithm for traversing a tree or a graph data structure
//

#include "DepthFirstSearch.hpp"
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

unordered_map<int, list<int>> DFSList;

void addNodeDFS(int node){
	if (DFSList.find(node) == DFSList.end()) {
		DFSList[node] = list<int>();
	}
}

void addEdgeDFS(int u, int v){
	if (DFSList.find(u) != DFSList.end() && DFSList.find(v) != DFSList.end()) {
		DFSList[u].push_back(v);
		DFSList[v].push_back(u);
	}
}

bool checkNodeDFS(int node){
	return DFSList.find(node) != DFSList.end();
}

void printGraphDFS(){
	for (auto& pair : DFSList) {
		cout << "Node " << pair.first << ": ";
		for (int neighbor : pair.second) {
			cout << neighbor << " ";
		}
		cout << endl;
	}
}

void DFSUtil(int node, unordered_map<int, bool>& visited){
	visited[node] = true;
	cout << "Visited Node " << node << endl;

	for (int neighbor : DFSList[node]) {
		if (!visited[neighbor]) {
			DFSUtil(neighbor, visited);
		}
	}
}

void DFS(int startNode){
	if (!checkNodeDFS(startNode)) {
		cout << "Start node does not exist in the graph." << endl;
		return;
	}

	unordered_map<int, bool> visited;
	for (auto& pair : DFSList) {
		visited[pair.first] = false;
	}

	DFSUtil(startNode, visited);
}

void displayDepthFirstSearch(){
	// Adding nodes to the graph
	addNodeDFS(0);
	addNodeDFS(1);
	addNodeDFS(2);
	addNodeDFS(3);
	addNodeDFS(4);

	// Adding edges to the graph
	addEdgeDFS(0, 1);
	addEdgeDFS(0, 2);
	addEdgeDFS(1, 3);
	addEdgeDFS(1, 4);

	// Print the graph's adjacency list
	cout << "Graph adjacency list:" << endl;
	printGraphDFS();

	// Check if a specific node exists
	cout << "\nChecking if node 3 exists: " << (checkNodeDFS(3) ? "Yes" : "No") << endl;
	cout << "Checking if node 5 exists: " << (checkNodeDFS(5) ? "Yes" : "No") << endl;

	// Perform DFS starting from node 0
	cout << "\nDFS Traversal from node 0:" << endl;
	DFS(0);
}
