#include "Stack.c"
#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

/*
    Create an empty stack.
*/
struct stack* createStack();

/*
    Add an item to the top of the stack.
*/
void push(struct stack* stack, int item);

/*
    Remove the top of the stack.
*/
int pop(struct stack* stack);

/*
    Returns the item from the top of the stack.
*/
int peek(struct stack* stack);

/*
    Returns if the stack is empty.
*/
int isEmptyStack(struct stack* stack);

#endif
