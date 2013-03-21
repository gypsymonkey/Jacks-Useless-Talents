#include <stdio.h>
#include "Uno.h"
#define AMOUNT_D 52
#define NUMBER_P 3
#define AMOUNT_H 5


int main()
{
    char command[8];
    int item, i;

    //Node* players = playerList(NUMBER_P);

    //  Inicialization of the shuffled draw pile.
    Stack* drawpile = createDeck(AMOUNT_D);
    shuffle(drawpile);
    //  Inicialization of the discard pile.
    Stack* discardpile = createStack();
    push(discardpile, pop(drawpile));

    // Inicialization of the hands.
    Node* hand = initializeHand(drawpile, AMOUNT_H, 1);

    do
    {
        drawUnoBoard(drawpile, discardpile, hand);
        scanf("%s", command);
        if(!strcmp(command, "quit"))
            break;

        scanf("%d", &item);

        if(!strcmp(command, "discard"))
        {
            hand = discard(hand, item, discardpile);
        }
        if(!strcmp(command, "draw"))
        {
            hand = draw(hand, drawpile);
        }
        if(!strcmp(command, "help"))
        {
            help();
        }

    }while(strcmp(command, "quit"));

    return 0;
}
