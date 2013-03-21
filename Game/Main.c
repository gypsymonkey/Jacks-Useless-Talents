#include <stdio.h>
#include "CommonFunctions.h"


int main()
{
    char command[8];
    int item;

    //  Inicialization of the piles of cards and the player hands.
    Stack* drawpile = createDeck(52);
    Stack* discardpile = createStack();
    push(discardpile, pop(drawpile));

    Node* hand = initializeHand(drawpile, 7);

    do
    {
        drawUnoBoard(drawpile, discardpile, hand);
        scanf("%s %d", command, &item);

        if (!strcmp(command, "discard"))
        {
            hand = discard(hand, item, discardpile);
        }

    }while(strcmp(command, "exit"));

    return 0;
}
