/***********
    Created by José Leandro.
************/

#include "Stack.c"
#ifndef STACK_H
#define STACK_H

/**
    The type Stack has two members. An integer storing the stack size and an array with the items.
*/
typedef struct stack Stack;

/**
    Create an empty stack.
*/
struct stack* createStack();

/**
    Add an item to the top of the stack.
*/
void push(struct stack* stack, Card item);

/**
    Remove the top of the stack.
*/
Card pop(struct stack* stack);

/**
    Returns the item from the top of the stack.
*/
Card peek(struct stack* stack);

/**
    Returns if the stack is empty.
*/
int isEmptyStack(struct stack* stack);

/**
    Print function for debuging purpose.
*/
void printStack(struct stack* stack);

#endif
