//
//  BinarySearchTree.hpp
//  Algorithms
//
//  Created by Dorin Curnic on 30.10.2024.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

struct Node;

Node* insertBinarySearchTree(Node* root, int value);
Node* deleteBinarySearchTree(Node* root, int value);
bool searchBinarySearchTree(Node* root, int value);
Node* findMinValueBinarySearchTree(Node* root);
void inorderBinarySearchTree(Node* root);
void displayBinarySearchTree();

#endif /* BinarySearchTree_hpp */
