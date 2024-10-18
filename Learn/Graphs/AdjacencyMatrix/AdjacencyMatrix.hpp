//
//  AdjacencyMatrix.hpp
//  Algorithms
//
//  Created by Dorin Curnic on 10.10.2024.
//

#ifndef AdjacencyMatrix_hpp
#define AdjacencyMatrix_hpp
#include "vector"

void addNodeMatrix(std::vector<char>& nodes, char node);
void addEdgeMatrix(std::vector<std::vector<int>>& matrix, int source, int destination);
bool checkEdgeMatrix(std::vector<std::vector<int>>& matrix, int source, int destination);
void printGraphMatrix(const std::vector<std::vector<int>>& matrix, const std::vector<char>& nodes, int size);
void displayAdjacencyMatrix();

#endif /* AdjacencyMatrix_hpp */
