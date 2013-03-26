#include "DataStructures/DoublyLinkedList.h"
#include "DataStructures/Stack.h"
#include <stdlib.h>

Node* discard(Node* hand, Card card, Stack* discardpile)
{
    Card topCard = peek(discardpile);
    //printf("%d%c", card.value, card.color);


    if(card.value == topCard.value || card.color == topCard.color)
    {
        printf("Hooray!\n");

    }
    //getch();

    push(discardpile, card);
    return removeNode(hand, card);
}

Node* draw(Node* hand, Stack* drawpile)
{
    if (isEmptyStack(drawpile))
    {
        printf ("There's no more cards left on the deck :(\n");
        return NULL;
    }

    return insertNode(hand, pop(drawpile));
}

void instructions()
{
    printf("######################################################################\n");
    printf("#   Instructions:                                                    #\n");
    printf("#                                                                    #\n");
    printf("#       This game is not working properly, you just have to type the #\n");
    printf("#   commands randomly. You're probaply gonna win.                    #\n");
    printf("#                                                  Try to have fun.  #\n");
    printf("######################################################################\n");

    getch();
}

void help()
{
    printf("#####################################################################\n");
    printf("#   Commands:                                                       #\n");
    printf("#                                                                   #\n");
    printf("#   - draw                  Draws a card.                           #\n");
    printf("#   - discard [card_id]     Discards a card from your hand          #\n");
    printf("#   - instructions          Shows the game rules.                   #\n");
    printf("#   - quit                  Guess what.                             #\n");
    printf("#####################################################################\n");

    getch();
}
