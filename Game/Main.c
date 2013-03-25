#include <stdio.h>
#include <limits.h>
#include "Uno.h"
#define AMOUNT_D 26
#define NUMBER_O 2
#define AMOUNT_H 5


int main()
{
    char command[8];
    int playerHand = 5;


    Stack* drawpile = createDeck(AMOUNT_D);                     ///  Initialization of the shuffled draw pile.
    shuffle(drawpile);

    Stack* discardpile = createStack();                         ///  Initialization of the discard pile.
    push(discardpile, pop(drawpile));

    Node* hand = initializeHand(drawpile, AMOUNT_H, 1);         /// Initialization of the hands.

    Player opponent[NUMBER_O];
    initializeOpponents(opponent, NUMBER_O, drawpile, AMOUNT_H);

    strcpy(opponent[0].name, "Tommy");
    strcpy(opponent[1].name, "Harry");

    int smallestHand = INT_MAX;

    do
    {
        do
        {
            drawUnoBoard(drawpile, discardpile, hand, opponent, NUMBER_O);
            Card c = peek(discardpile);

            scanf("%s", command);

            if(!strcmp(command, "discard"))
            {
                Card card;

                scanf("%d %c", &card.value, &card.color);
                hand = discard(hand, card, discardpile);
                //if(--playerHand < smallestHand)
                //    smallestHand = playerHand;
                break;
            }
            if(!strcmp(command, "draw"))
            {
                hand = draw(hand, drawpile);
                break;
            }
            if(!strcmp(command, "help"))
            {
                help();
            }
            if(!strcmp(command, "print"))
            {
                char pile[12];
                scanf("%s", pile);

                if(!strcmp(pile, "draw"))
                {
                    printStack(drawpile);
                }
                if(!strcmp(pile, "discard"))
                    printStack(discardpile);
            }

        }while(strcmp(command, "quit"));

        drawUnoBoard(drawpile, discardpile, hand, opponent, NUMBER_O);
        printf("\n");

        if (strcmp(command, "quit"))
            opponentTurn(opponent, NUMBER_O, drawpile, discardpile);


        //printf("%d", smallestHand);
        //getchar();
        //getchar();

        if (smallestHand == 0)
        {
            printf("Congratulations, you won!\n");
            strcpy(command, "quit");
        }


    }while (endGame(command));

    return 0;
}
