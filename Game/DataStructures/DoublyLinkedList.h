#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "DoublyLinkedList.c"

typedef struct card Card;

typedef struct node Node;

/**
    Returns NULL.
*/
Node* createDoublyLinkedList();

/**
    Inserts a new node to the list and returns it.
*/
Node* insertNode(Node* first, Card item);

/**
    Removes a node from the list and returns the first node.
*/
Node* removeNode(Node* first, Card item);

/**
    Returns if the list is empty.
*/
int isEmptyList(Node* first);

/**
    Print function for debugging purposes.
*/
void printDoublyLinkedList(Node* first);

#endif
