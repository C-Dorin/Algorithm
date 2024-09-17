//
//  SinglyLinkedList.hpp
//  Algorithms
//
//  Created by Dorin Curnic on 13.09.2024.
//

#ifndef SinglyLinkedList_hpp
#define SinglyLinkedList_hpp

struct Node;

void insertNode(Node*& head, int value);
void insertNode(Node*& head, int position, int value);
void deleteNode(Node*& head, int value);
void displayNode(Node* head);
void displaySinglyLinkedList();

#endif /* SinglyLinkedList_hpp */
