#include "DataStructures/DoublyLinkedList.h"
#include "DataStructures/Stack.h"
#include "Commands.h"
#include <string.h>

Stack* createDeck(int amount)
{
    int i;
    Stack* newDeck = createStack();

    for (i = 0; i < amount; ++i)
    {
        push(newDeck, i);
    }

    return newDeck;
}

int random(int range)
{
    return rand() % range;
}

void shuffle(Stack* deck)
{
    int i, aux;
    int* stack = deck->items;

    for(i = 1; i < deck->size; ++i)
    {
        int r = random(i);
        aux = stack[r];
        stack[r] = stack[i];
        stack[i] = aux;
    }
}

Node* initializeHand(Stack* deck, int amount, int player)
{
    int i;
    Node* newHand = createDoublyLinkedList();

    for (i = 0;i < amount; ++i)
    {
        newHand = insertNode(newHand, pop(deck));
    }

    return newHand;
}

Node* playerList(int number)
{
    int i;
    Node* newPlayerList = createDoublyLinkedList();
    Node* current = newPlayerList;

    for (i = 0; i < number; ++i)
    {
        newPlayerList = insertNode(newPlayerList, i);
    }

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newPlayerList;

    return newPlayerList;
}

void drawUnoBoard(Stack* drawpile, Stack* discardpile, Node* hand)
{
    system("cls");

    printf("Type help for a list of valid commands.\n");
    if (!isEmptyStack(drawpile))
    {
        printf("    _____\n  /|     |\n   |  U  |\n   |  N  |\n   |  O  |\n   |_____|\n  /_____/\n");
    }

    if (!isEmptyStack(discardpile))
    {
        int value = peek(discardpile);
        printf("  _____\n |%2d   |\n |     |\n |     |\n |     |\n |___%2d|\n\n", value, value);
    }


    if (!isEmptyList(hand))
        printDoublyLinkedList(hand);

    printf("\n>");
}
