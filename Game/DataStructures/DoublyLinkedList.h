/***********
    Created by José Leandro.
************/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "DoublyLinkedList.c"

/**
    The type Card has two members. An integer representing the value (0~9) and a char representing
    the color of the card (R, B, Y, G or S).
*/
typedef struct card Card;

/**
    The type Node has three members. A struct card named item and two pointers linking the node tho its
    next ann previous node, respectively.
*/
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
