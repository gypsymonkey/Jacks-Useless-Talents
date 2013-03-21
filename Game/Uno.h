#include "Uno.c"
#include "DataStructures/DoublyLinkedList.h"
#include "DataStructures/Stack.h"

/*
    Returns a new deck not shuffled with the amount of items especified.
*/
Stack* createDeck(int amount);

/*
    Generate a pseudo-random number between the specified range.
*/
int random(int range);

/*
    Shuffle a stack.
*/
void shuffle(Stack* deck);

/*
    Fill a hand with cards from a deck. The second parameter is the amount of cards. The third is the owner of the hand.
*/
Node* initializeHand(Stack* deck, int amount, int player);

/*
    Create a doubly linked list where the last node is linked to the first, representing, this way, the list of players.
*/
Node* playerList(int number);

/*
    Draw the board, basically.
*/
void drawUnoBoard(Stack* drawpile, Stack* discardpile, Node* hand);
