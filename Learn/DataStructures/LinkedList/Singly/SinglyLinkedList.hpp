//
//  SinglyLinkedList.hpp
//  Algorithms
//
//  Created by Dorin Curnic on 13.09.2024.
//

#ifndef SinglyLinkedList_hpp
#define SinglyLinkedList_hpp

struct Node;

void insertNodeSinglyLinkedList(Node*& head, int value);
void insertNodeSinglyLinkedList(Node*& head, int position, int value);
void deleteNodeSinglyLinkedList(Node*& head, int value);
void displayNodeSinglyLinkedList(Node* head);
extern void displaySinglyLinkedList();

#endif /* SinglyLinkedList_hpp */
