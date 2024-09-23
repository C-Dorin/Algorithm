//
//  SinglyLinkedList.cpp
//  Algorithms
//
//  Created by Dorin Curnic on 13.09.2024.
//

//
// LinkedLists = stores in 2 parts (data + address)
// 				 Nodes are in non-consecutive memory locations
//				 Elements are linked using pointers
//
//		small data set:    							  LinkedList = BAD
//		large data set + lots of searching:           LinkedList = BAD
//		large data set + lots of inserting/deleting:  LinkedList = GOOD
//
//		Insertion or Deletion - Time Complexity: O(1)
//		Accesing or Searching - Time Complexity: O(n)
//
//		Uses of Linked lists:
//		1. Implement Stacks / Queues
//		2. GPS Navigation
//		3. Music playlist

//
// 					     Singly Linked List
//          Node                Node                Node
//     [data | address] -> [data | address] -> [data | address]
//

#include "SinglyLinkedList.hpp"
#include <iostream>

using namespace std;

// Declare Node structure
struct Node {
	int data;
	Node* next;
};

// Function to insert a node at the end of the list
void insertNodeSinglyLinkedList(Node*& head, int value){
	// Create a new node with the provided value
	Node* newNode = new Node{value, nullptr};

	// If the list is empty, the new node becomes the head
	if (head == nullptr) {
		head = newNode;
		return;
	}

	// Traverse to the end of the list
	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}

	// Link the new node at the end
	temp->next = newNode;
}

// Function to insert a node at a specific position
void insertNodeSinglyLinkedList(Node*& head, int position, int value){
	// Create a new node with the provided value
	Node* newNode = new Node{value, nullptr};

	// If the list is empty or inserting at the head
	if (position == 1) {
		newNode->next = head;
		head = newNode;
		return;
	}

	// Traverse to the node before the desired position
	Node* temp = head;
	for (int i = 1; i < position - 1 && temp != nullptr; i++) {
		temp = temp->next;
	}

	// Check if the position is out of bounds
	if (temp == nullptr) {
		cerr << "Position out of bounds!" << endl;
		delete newNode;
		return;
	}

	// Insert the new node at the desired position
	newNode->next = temp->next;
	temp->next = newNode;
}

// Function to delete a node by value
void deleteNodeSinglyLinkedList(Node*& head, int value){
	// If the list is empty
	if (head == nullptr) {
		cerr << "List is empty, nothing to delete." << endl;
		return;
	}

	// If the node to be deleted is the head
	if (head->data == value) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	// Traverse the list to find the node to delete
	Node* temp = head;
	Node* prev = nullptr;
	while (temp != nullptr && temp->data != value) {
		prev = temp;
		temp = temp->next;
	}

	// If the node was not found
	if (temp == nullptr) {
		cerr << "Node with value " << value << " not found." << endl;
		return;
	}

	// Unlink the node and delete it
	prev->next = temp->next;
	delete temp;
}

// Function to display the entire linked list
void displayNodeSinglyLinkedList(Node* head) {
	// If the list is empty
	if (head == nullptr) {
		cerr << "The list is empty." << endl;
		return;
	}

	// Traverse the list and display each node's data
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

void displaySinglyLinkedList(){
	// Initialize the head of the list
	Node* head = nullptr;

	// Insert elements into the list
	insertNodeSinglyLinkedList(head, 10);
	insertNodeSinglyLinkedList(head, 20);
	insertNodeSinglyLinkedList(head, 30);
	insertNodeSinglyLinkedList(head, 40);
	insertNodeSinglyLinkedList(head, 2, 25);

	// Display the linked list
	cout << "Linked List: ";
	displayNodeSinglyLinkedList(head);

	// Delete a node
	deleteNodeSinglyLinkedList(head, 20);
	cout << "After deleting 20: ";
	displayNodeSinglyLinkedList(head);
}
