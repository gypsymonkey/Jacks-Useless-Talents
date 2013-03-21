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

Node* initializeHand(Stack* deck, int amount)
{
    int i;
    Node* newHand = createDoublyLinkedList();

    for (i = 0;i < amount; ++i)
    {
        newHand = insertNode(newHand, pop(deck));
    }

    return newHand;
}

void drawUnoBoard(Stack* drawpile, Stack* discardpile, Node* hand)
{
    system("cls");
    if (!isEmptyStack(drawpile))
    {
        int value = peek(discardpile);
        printf("    _____\n  /|     |\n   |  U  |\n   |  N  |\n   |  O  |\n   |_____|\n  /_____/\n");
        printf("  _____\n |%2d   |\n |     |\n |     |\n |     |\n |___%2d|\n\n", value, value);
    }

    if (!isEmptyList(hand))
        printDoublyLinkedList(hand);

    printf("\n>");
}
