#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    Stack mystack;
    Stack * myStack = initStack(&mystack);
    push(myStack, 3);
    push(myStack, 4);
    push(myStack, 5);
    printStack(myStack);
    int elem;
    pop(myStack, &elem);
    printf("\n%d\n",elem);
    printStack(myStack);
    return 0;
}
