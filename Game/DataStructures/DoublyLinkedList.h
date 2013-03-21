#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "DoublyLinkedList.c"

typedef struct node Node;

/*
    Returns NULL.
*/
Node* createDoublyLinkedList();

/*
    Inserts a new node to the list and returns it.
*/
Node* insertNode(Node* first, int item);

/*
    Removes a node from the list and returns the first node.
*/
struct node* removeNode(Node* first, int item);

/*
    Returns if the list is empty.
*/
int isEmptyList(Node* first);

/*
    Print function for debugging purposes.
*/
void printDoublyLinkedList(Node* first);

#endif
