#include "DataStructures/DoublyLinkedList.h"
#include "DataStructures/Stack.h"

Node* discard(Node* hand, int item, Stack* discardpile)
{
    push(discardpile, item);
    return removeNode(hand, item);
}

Node* draw(Node* hand, Stack* drawpile)
{
    return insertNode(hand, pop(drawpile));
}

void instructions()
{
    /* Show game instructions. */
}

void help()
{
    printf("#####################################################################\n");
    printf("#   Commands:                                                       #\n");
    printf("#                                                                   #\n");
    printf("#   - draw                  Draws a card.                           #\n");
    printf("#   - discard [card_id]     Discards a card from your hand          #\n");
    printf("#   - instructions          Show the game rules. (not implemented)  #\n");
    printf("#   - quit                  Guess what.                             #\n");
    printf("#####################################################################\n");

    getchar();
    getchar();
    getchar();

}
