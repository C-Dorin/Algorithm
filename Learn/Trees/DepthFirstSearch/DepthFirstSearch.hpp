//
//  DepthFirstSearch.hpp
//  Algorithms
//
//  Created by Dorin Curnic on 18.10.2024.
//

#ifndef DepthFirstSearch_hpp
#define DepthFirstSearch_hpp

#include "unordered_map"

void addNodeDFS(int node);
void addEdgeDFS(int u, int v);
bool checkNodeDFS(int node);
void printGraphDFS();
void DFSUtil(int node, std::unordered_map<int, bool>& visited);
void DFS(int startNode);
void displayDepthFirstSearch();

#endif /* DepthFirstSearch_hpp */
