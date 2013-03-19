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

Node* removeNode(Node* first, int item);

int isEmptyNode(Node* first);

/*
    Print function for debugging porpose.
*/
void printDoublyLinkedList(Node* first);

#endif
