//
//  BinarySearchTree.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 30.10.2024.
//

//	Binary Search Tree = A tree data structure, where each node is greater than it's left child,
//						 but less than it's right.
//
//	Benefit: easy to locate a node when they are in this order
//
//	Time complexity:	best case  O(log n)
//						worst case O(n)
//
//	Space complexity:	O(n)
//

#include "BinarySearchTree.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int value): data(value), left(nullptr), right(nullptr) {}
};

Node* insertBinarySearchTree(Node* root, int value){
	if (root == nullptr) {
		return new Node(value);
	}

	if (value < root->data) {
		root->left = insertBinarySearchTree(root->left, value);
	} else if (value > root->data){
		root->right = insertBinarySearchTree(root->right, value);
	}

	return root;
}

Node* deleteBinarySearchTree(Node* root, int value){
	if (root == nullptr) {
		return root;
	}

	if (value < root->data) {
		root->left = deleteBinarySearchTree(root->left, value);
	} else if (value > root->data){
		root->right = deleteBinarySearchTree(root->right, value);
	} else {
		if (root->left == nullptr) {
			Node* temp = root->right;
			delete root;
			return temp;
		} else if (root->right == nullptr){
			Node* temp = root-> right;
			delete root;
			return temp;
		}

		Node* temp = findMinValueBinarySearchTree(root->right);
		root->data = temp->data;
		root->right = deleteBinarySearchTree(root->right, temp->data);
	}

	return root;
}

bool searchBinarySearchTree(Node* root, int value){
	if (root == nullptr) {
		return false;
	}
	if (value == root->data) {
		return true;
	}
	if (value < root->data) {
		return searchBinarySearchTree(root->left, value);
	}

	return searchBinarySearchTree(root->right, value);
}

Node* findMinValueBinarySearchTree(Node* root){
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

void inorderBinarySearchTree(Node* root){
	if (root == nullptr) return;
	inorderBinarySearchTree(root->left);
	cout << root->data << " ";
	inorderBinarySearchTree(root->right);
}

void displayBinarySearchTree(){
	Node* root = nullptr;

	root = insertBinarySearchTree(root, 8);
	root = insertBinarySearchTree(root, 3);
	root = insertBinarySearchTree(root, 10);
	root = insertBinarySearchTree(root, 1);
	root = insertBinarySearchTree(root, 6);
	root = insertBinarySearchTree(root, 14);
	root = insertBinarySearchTree(root, 4);
	root = insertBinarySearchTree(root, 7);
	root = insertBinarySearchTree(root, 13);

	cout << "Inorder traversal of the BST: ";
	inorderBinarySearchTree(root);
	cout << endl;

	// Search for a value in the BST
	int searchValue = 6;
	cout << "Searching for " << searchValue << ": ";
	cout << (searchBinarySearchTree(root, searchValue) ? "Found" : "Not Found") << endl;

	// Delete a node from the BST
	int deleteValue = 3;
	cout << "Deleting node " << deleteValue << " from the BST.\n";
	root = deleteBinarySearchTree(root, deleteValue);

	cout << "Inorder traversal after deletion: ";
	inorderBinarySearchTree(root);
	cout << endl;
}
