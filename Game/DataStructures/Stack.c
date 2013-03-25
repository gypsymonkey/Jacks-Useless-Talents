#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedList.h"
#define MAX_STACK_SIZE 	100
#ifndef STACK_C
#define STACK_C

struct stack {
	int size;
	Card items[MAX_STACK_SIZE];
};

struct stack* createStack()
{
	struct stack* newStack = (struct stack*) malloc(sizeof(struct stack));
	newStack->size = 0;

	return newStack;
}

void push(struct stack* stack, Card item)
{
    if (stack->size == MAX_STACK_SIZE)
    {
        printf ("Stack overflow!\n");
    } else {
        memcpy(&stack->items[stack->size], &item, sizeof(struct card));
        ++stack->size;
    }
}

Card pop(struct stack* stack)
{
    if (isEmptyStack(stack))
    {
        printf ("Empty stack!\n");
        return;
    } else {
        return stack->items[--stack->size];
    }
}

Card peek(struct stack* stack)
{
    if (isEmptyStack(stack))
    {
        printf ("Empty stack!\n");
        return;
    } else {
        return stack->items[stack->size - 1];
    }
}

int isEmptyStack(struct stack* stack)
{
    return (stack->size == 0);
}

void printStack(struct stack* stack)
{
    int i;
    for (i = stack->size; i > 0; --i)
    {
        printf("[%d%c]\n", stack->items[i].value, stack->items[i].color);
    }
    getchar();
    getchar();
}

#endif
