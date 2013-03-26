#include "DataStructures/DoublyLinkedList.h"
#include "DataStructures/Stack.h"
#include "Commands.h"
#include <string.h>
#include <time.h>

struct player
{
    int amount_h;
    char name[7];
    Node* hand;
};

Stack* createDeck(int amount)
{
    int i;

    Stack* newDeck = createStack();
    Card current;

    FILE* deck = fopen("deck.uno", "r");

    for (i = 0; i < amount; ++i)
    {

        fscanf(deck ,"%d %c", &current.value, &current.color);
        printf("Estamos aqui!\n");
        push(newDeck, current);
    }

    return newDeck;
}

int random(int range)
{
    return rand() % range;
}

void shuffle(Stack* deck)
{
    int i;
    Card aux;
    Card* stack = deck->items;

    for(i = 1; i < deck->size; ++i)
    {
        int r = random(i);
        aux = stack[r];
        stack[r] = stack[i];
        stack[i] = aux;
    }
}

Node* initializeHand(Stack* deck, int amount, int player)
{
    int i;
    Node* newHand = createDoublyLinkedList();

    for (i = 0;i < amount; ++i)
    {
        newHand = insertNode(newHand, pop(deck));
    }

    return newHand;
}

struct card getCard(int index)
{
    int i;
    struct card c;
    ++index;
    FILE* deck = fopen("deck.uno", "r");

    for(i = 0; i < index; ++i)
    {
        fscanf(deck, "%d %c", &c.value, &c.color);
    }
    return c;
}

void printHand(Node* hand)
{
    Node* current = hand;
    while(current != NULL)
    {
        printf("%d%c ", current->item.value, current->item.color);

        current = current->next;
    }
    printf("\n");
}

void drawUnoBoard(Stack* drawpile, Stack* discardpile, Node* hand, struct player opponent[], int number)
{
    system("cls");
    int i;

    printf("#############################################\n");
    printf("#   Type help for a list of valid commands. #\n");
    printf("#############################################\n");

    for (i = 0; i < number; ++i)
    {
        printf("%s\n", opponent[i].name);
        printf("%d card(s).\n", opponent[i].amount_h);
        printHand(opponent[i].hand);
        //printDoublyLinkedList(opponent[i].hand);

        printf("\n");
    }

    printf("#############################################\n");
    if (!isEmptyStack(drawpile))
    {
        printf("#    _____                                  #\n");
        printf("#  /|     |                                 #\n");
        printf("#  ||  U  |                                 #\n");
        printf("#  ||  N  |                                 #\n");
        printf("#  ||  O  |                                 #\n");
        printf("#  ||_____|                                 #\n");
        printf("#  /-----/                                  #\n");

    }

    if (!isEmptyStack(discardpile))
    {
        Card topcard = peek(discardpile);;

        printf("#  _____                                    #\n");
        printf("# |%2d   |                                   #\n", topcard.value);
        printf("# |     |                                   #\n");
        printf("# |  %c  |                                   #\n", topcard.color);
        printf("# |     |                                   #\n");
        printf("# |___%2d|                                   #\n", topcard.value);
        printf("#                                           #\n");
        printf("#############################################\n");
    }


    if (!isEmptyList(hand))
        printHand(hand);
    //printDoublyLinkedList(hand);
    printf(">");
}

void opponentTurn(struct player opponent[], int number, Stack* drawpile, Stack* discardpile)
{
    int i;

    for (i = 0; i < number; ++i)
    {
            opponent[i].hand = draw(opponent[i].hand, drawpile);
            ++opponent[i].amount_h;

            printf ("%s has drawn a card.\n", opponent[i].name);
            getch();
    }
}

struct player* initializeOpponents(struct player* opponent, int number_o, Stack* drawpile, int amount_h)
{
    int i;

    for (i = 0; i < number_o; ++i)
    {
        opponent[i].hand = initializeHand(drawpile, amount_h, 1);
        opponent[i].amount_h = amount_h;
    }

    return opponent;
}

int endGame(char* command)
{
    return (strcmp(command, "quit"));
}
