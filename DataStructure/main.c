#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    Stack *myStack;
    myStack = initStack();
    printf("%d",myStack->stackSize);
    return 0;
}
