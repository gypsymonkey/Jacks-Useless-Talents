#include <stdio.h>
#include <stdlib.h>
#ifndef DOUBLY_LINKED_LIST_C
#define DOUBLY_LINKED_LIST_C

struct card
{
    int value;
    int color;
};

struct node
{
	struct card item;
	struct node* next;
	struct node* previous;
};

struct node* createDoublyLinkedList()
{
	return NULL;
}

struct node* insertNode(struct node* first, struct card item)
{
	struct node* newNode = (struct node*)malloc (sizeof(struct node));
	newNode->next = first;
	newNode->previous = NULL;
	newNode->item = item;

	if(first != NULL)
		first->previous = newNode;

	return newNode;
}

struct node* removeNode(struct node* first, struct card item)
{
	struct node* current = first;


	while (current != NULL && current->item.value != item.value && current->item.color != item.color)
		current = current->next;

	if (first  == current)
		first = current->next;
	else
		current->previous->next = current->next;


	if (current->next != NULL)
		current->next->previous = current->previous;

	free(current);

	return first;
}

int isEmptyList(struct node* first)
{
	return (first == NULL);
}

void printDoublyLinkedList(struct node* first)
{
	struct node* current = first;
	while (current != NULL)
	{
		printf ("[%d%c] <=> ", current->item.value, current->item.color);
		current = current->next;
	}

	printf ("NULL\n");
}

#endif
