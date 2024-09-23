//
//  DoublyLinkedList.hpp
//  Algorithms
//
//  Created by Dorin Curnic on 13.09.2024.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

struct Node;

extern void insertNodeDoublyLinkedList(Node*& head, int value);
extern void insertNodeDoublyLinkedList(Node*& head, int position, int value);
extern void deleteNodeDoublyLinkedList(Node*& head, int value);
extern void displayNodeDoublyLinkedList(Node* head);
extern void displayDoublyLinkedList();

#endif /* DoublyLinkedList_hpp */
