#include <stdio.h>
#include <stdlib.h>
#ifndef DOUBLY_LINKED_LIST_C
#define DOUBLY_LINKED_LIST_C
struct node
{
	int item;
	struct node* next;
	struct node* previous;
};

struct node* createDoublyLinkedList()
{
	return NULL;
}

struct node* insertNode(struct node* first, int item)
{
	struct node* newNode = (struct node*)malloc (sizeof(struct node));
	newNode->next = first;
	newNode->previous = NULL;
	newNode->item = item;

	if(first != NULL)
		first->previous = newNode;

	return newNode;
}

struct node* removeNode(struct node* first, int item)
{
	struct node* current = first;

	while (current != NULL && current->item != item)
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

int isEmptyNode(struct node* first)
{
	return (first == NULL);
}

void printDoublyLinkedList(struct node* first)
{
	struct node* current = first;
	while (current != NULL)
	{
		printf ("[%d] <=> ", current->item);
		current = current->next;
	}

	printf ("NULL\n");
}
#endif
