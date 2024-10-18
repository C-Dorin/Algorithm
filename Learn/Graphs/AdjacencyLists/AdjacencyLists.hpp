//
//  AdjacencyLists.hpp
//  Algorithms
//
//  Created by Dorin Curnic on 18.10.2024.
//

#ifndef AdjacencyLists_hpp
#define AdjacencyLists_hpp
#include "vector"
#include "list"

void addNodeLists(std::vector<char>& nodes, char node);
void addEdgeLists(std::vector<std::list<int>>& list, int source, int destination);
bool checkEdgeLists(std::vector<std::list<int>>& list, int source, int destination);
void printGraphLists(const std::vector<std::list<int>>& list, const std::vector<char>& nodes, int size);
void displayAdjacencyLists();

#endif /* AdjacencyLists_hpp */
