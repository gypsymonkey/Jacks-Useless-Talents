#include <stdio.h>
#include <limits.h>
#include "Uno.h"
#define AMOUNT_D 26             /// Amount of cards on the deck.
#define NUMBER_O 1              /// Amount of opponents doing stupid things.
#define AMOUNT_H 5              /// Initial amount of cards on the players hands.


int main()
{
    char command[15];
    int playerHand = 5;


    Stack* drawpile = createDeck(AMOUNT_D);                     ///  Initialization of the shuffled draw pile.
    shuffle(drawpile);

    Stack* discardpile = createStack();                         ///  Initialization of the discard pile.
    push(discardpile, pop(drawpile));

    Node* hand = initializeHand(drawpile, AMOUNT_H, 1);         /// Initialization of the hands.

    Player opponent[NUMBER_O];
    initializeOpponents(opponent, NUMBER_O, drawpile, AMOUNT_H);

    strcpy(opponent[0].name, "Tommy");
    //strcpy(opponent[1].name, "Harry");

    int smallestHand = INT_MAX;

    do
    {
        do
        {
            drawUnoBoard(drawpile, discardpile, hand, opponent, NUMBER_O);      ///This function refresh the screen every time it changes.
            Card c = peek(discardpile);

            scanf("%s", command);

            /// Commands

            if(!strcmp(command, "discard"))
            {
                Card card;

                scanf("%d %c", &card.value, &card.color);
                hand = discard(hand, card, discardpile);
                if(--playerHand < smallestHand)
                    smallestHand = playerHand;
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
            if(!strcmp(command, "instructions"))
            {
                instructions();
            }

            /**
                The commands below were used for debug and stuff.
            */
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
            opponentTurn(opponent, NUMBER_O, drawpile, discardpile);             /// The opponent turn starts here if the command quit is not typed.

        if (smallestHand == 0)
        {
            drawUnoBoard(drawpile, discardpile, hand, opponent, NUMBER_O);
            printf("\n#############################################\n");
            printf("#   Congratulations, you are the winner!    #\n");
            printf("#############################################\n");
            strcpy(command, "quit");
        }

    }while (endGame(command));

    return 0;
}
