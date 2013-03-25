#include "Commands.c"

/**
    Discard a card from the hand and stacks it on the discard pile.
*/
Node* discard(Node* hand, Card card, Stack* discardpile);

/**
    Draw a card.
*/
Node* draw(Node* hand, Stack* drawpile);

/**
    Barely exists.
*/
void instructions();

/**
    Shows a list of valid commands.
*/
void help();
