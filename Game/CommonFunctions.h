#include "CommonFunctions.c"
#include "DataStructures/DoublyLinkedList.h"
#include "DataStructures/Stack.h"

/*
    Returns a new deck not shuffled with the amount of items especified.
*/
Stack* createDeck(int amount);

/*
    Fill a hand with cards from a deck. The second parameter is the amount of cards.
*/
Node* initializeHand(Stack* deck, int amount);

/*
    Still does nothing.
*/
void drawUnoBoard(Stack* drawpile, Stack* discardpile, Node* hand);
