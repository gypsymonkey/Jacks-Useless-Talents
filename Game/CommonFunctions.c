#include "DataStructures/DoublyLinkedList.h"
#include "DataStructures/Stack.h"

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

void drawUnoBoard(Stack* deck, Node* hand)
{
    if (!isEmptyStack(deck))
    {
        printf("  _____\n/|     |\n |  U  |\n |  N  | ---------> This was supposed to be a deck.\n |  O  |\n |_____|\n/_____/\n\n\n");
    }

    printDoublyLinkedList(hand);

    return;
}
