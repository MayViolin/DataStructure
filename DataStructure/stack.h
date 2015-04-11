#define INITAIL_SIZE 20

typedef struct Stack {
    int *base;
    int *top;
    int stackSize;
}Stack;

Stack * initStack(Stack *myStack) {
    myStack->base = (int*)malloc(sizeof(int)*INITAIL_SIZE);
    if (NULL == myStack->base) {
        return NULL;
    }
    myStack->top = myStack->base;
    myStack->stackSize = INITAIL_SIZE;
    return myStack;
}

bool largerStack(Stack *myStack) {
    // Attention! If realloc() failed and return NULL, may lose the base of myStack!
    int * newBase = (int*)realloc(myStack->base, (myStack->stackSize + INITAIL_SIZE)*sizeof(int));
    if (NULL == newBase) {
        return false;
    }
    myStack->base = newBase;
    myStack->top = myStack->base + myStack->stackSize;
    myStack->stackSize = myStack->stackSize + INITAIL_SIZE;
    return true;
}

bool push(Stack *myStack, int elem) {
    if ((myStack->top - myStack->base) == myStack->stackSize) {
        bool res = largerStack(myStack);
        if (!res) {
            return false;
        }
    }
    myStack->top++ = elem;
    return true;
}

bool pop(Stack *myStack, int *elem) {
    if (myStack->base == myStack->top) {
        return false;
    }
    *elem = *(--myStack->top);
    return true;
}


