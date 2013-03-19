#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 	100
#ifndef STACK_C
#define STACK_C

struct stack {
	int size;
	int items[MAX_STACK_SIZE];
};

struct stack* createStack()
{
	struct stack* newStack = (struct stack*) malloc(sizeof(struct stack));
	newStack->size = 0;

	return newStack;
}

void push(struct stack* stack, int item)
{
    if (stack->size == MAX_STACK_SIZE)
    {
        printf ("Stack overflow!\n");
    } else {
        stack->items[stack->size] = item;
        ++stack->size;
    }
}

int pop(struct stack* stack)
{
    if (isEmptyStack(stack))
    {
        printf ("Empty stack!\n");
        return -1;
    } else {
        return stack->items[--stack->size];
    }
}

int peek(struct stack* stack)
{
    if (isEmptyStack(stack))
    {
        printf ("Empty stack!\n");
        return -1;
    } else {
        return stack->items[stack->size - 1];
    }
}

int isEmptyStack(struct stack* stack)
{
    return (stack->size == 0);
}

#endif
