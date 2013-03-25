#include "Uno.c"
#include "DataStructures/DoublyLinkedList.h"
#include "DataStructures/Stack.h"

typedef struct player Player;

/**
    Returns a new deck not shuffled with the amount of items especified.
*/
Stack* createDeck(int amount);

/**
    Generate a pseudo-random number between the specified range.
*/
int random(int range);

/**
    Shuffle a stack.
*/
void shuffle(Stack* deck);

/**
    Fill a hand with cards from a deck. The second parameter is the amount of cards. The third is the owner of the hand.
*/
Node* initializeHand(Stack* deck, int amount, int player);


/**
    Returns the card associated with the index.
*/
struct card getCard(int index);

/**
    Print the hand.
*/
void printHand(Node* hand);

/**
    Draw the board, basically.
*/
void drawUnoBoard(Stack* drawpile, Stack* discardpile, Node* hand, struct player opponent[], int number);

/**
    Opponent moves.
*/
void opponentTurn(struct player opponent[], int number, Stack* drawpile, Stack* discardpile);

/**
    Initialize the opponents with their hands and names.
*/
Player* initializeOpponents(struct player* opponent, int number_o, Stack* drawpile, int amount_c);

/**
    Check if the game is over.
*/
int endGame(char* command);
