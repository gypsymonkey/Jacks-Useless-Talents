#include <stdio.h>
#include "CommonFunctions.h"


int main()
{
    //printf("  _____\n/|     |\n |     |\n |     | ---------> This was supposed to be a deck.\n |     |\n |_____|\n/_____/\n");

    Stack* deck = createDeck(52);
    Node* hand = initializeHand(deck, 5);


    drawUnoBoard(deck, hand);

    return 0;
}
