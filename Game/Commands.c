#include "DataStructures/DoublyLinkedList.h"
#include "DataStructures/Stack.h"

Node* discard(Node* hand, int item, Stack* discardpile)
{
    push(discardpile, item);
    return removeNode(hand, item);
}
