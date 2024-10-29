//
//  BreadthFirstSearch.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 29.10.2024.
//

//
//	BFS = a search algorithm for traversing a tree or a graph data structure
//		Traverse a graph level by level
//		Utilizes a Queue
//		Better if destination is on average close to start
//		Siblings are visited before children
//		More popular for GPS/Peer-to-peer Network
//

#include "BreadthFirstSearch.hpp"
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

unordered_map<int, list<int>> BFSList;

void addNodeBFS(int node){
	if (BFSList.find(node) == BFSList.end()) {
		BFSList[node] = list<int>();
	}
}

void addEdgeBFS(int u, int v){
	if (BFSList.find(u) != BFSList.end() && BFSList.find(v) != BFSList.end()) {
		BFSList[u].push_back(v);
		BFSList[v].push_back(u);
	}
}

bool checkNodeBFS(int node){
	return BFSList.find(node) != BFSList.end();
}

void printGraphBFS(){
	for (auto& pair : BFSList) {
		cout << "Node " << pair.first << ": ";
		for (int neighbor : pair.second) {
			cout << neighbor << " ";
		}
		cout << endl;
	}
}

void BFSUtil(int startNode, std::unordered_map<int, bool>& visited){
	queue<int> q;
	visited[startNode] = true;
	q.push(startNode);

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();
		cout << currentNode << " ";

		// Visit all neighbors of the current node
		for (int neighbor : BFSList[currentNode]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
	cout << endl;
}

void BFS(int startNode){
	if (!checkNodeBFS(startNode)) {
		cout << "Start node does not exist in the graph." << endl;
		return;
	}

	unordered_map<int, bool> visited;
	for (auto& pair : BFSList) {
		visited[pair.first] = false;
	}

	BFSUtil(startNode, visited);
}

void displayBreadthFirstSearch(){
	// Adding nodes to the graph
	addNodeBFS(0);
	addNodeBFS(1);
	addNodeBFS(2);
	addNodeBFS(3);
	addNodeBFS(4);
	addNodeBFS(5);
	addNodeBFS(6);

	// Adding edges to the graph
	addEdgeBFS(0, 1);
	addEdgeBFS(0, 2);
	addEdgeBFS(1, 3);
	addEdgeBFS(1, 4);
	addEdgeBFS(2, 5);
	addEdgeBFS(2, 6);

	// Print the graph's adjacency list
	cout << "Graph adjacency list:" << endl;
	printGraphBFS();

	// Check if a specific node exists
	cout << "\nChecking if node 3 exists: " << (checkNodeBFS(3) ? "Yes" : "No") << endl;
	cout << "Checking if node 7 exists: " << (checkNodeBFS(7) ? "Yes" : "No") << endl;

	// Perform BFS starting from node 0
	cout << "\nDFS Traversal from node 0:" << endl;
	BFS(0);
}
