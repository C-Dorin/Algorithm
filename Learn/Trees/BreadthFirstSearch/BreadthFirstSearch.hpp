//
//  BreadthFirstSearch.hpp
//  Algorithms
//
//  Created by Dorin Curnic on 29.10.2024.
//

#ifndef BreadthFirstSearch_hpp
#define BreadthFirstSearch_hpp

#include "unordered_map"

void addNodeBFS(int node);
void addEdgeBFS(int u, int v);
bool checkNodeBFS(int node);
void printGraphBFS();
void BFSUtil(int startNode, std::unordered_map<int, bool>& visited);
void BFS(int startNode);
void displayBreadthFirstSearch();

#endif /* BreadthFirstSearch_hpp */
