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

int largerStack(Stack *myStack) {
    // Attention! If realloc() failed and return NULL, may lose the base of myStack!
    int * newBase = (int*)realloc(myStack->base, (myStack->stackSize + INITAIL_SIZE)*sizeof(int));
    if (NULL == newBase) {
        return 0;
    }
    myStack->base = newBase;
    myStack->top = myStack->base + myStack->stackSize;
    myStack->stackSize = myStack->stackSize + INITAIL_SIZE;
    return 1;
}

int push(Stack *myStack, int elem) {
    if ((myStack->top - myStack->base) == myStack->stackSize) {
        int res = largerStack(myStack);
        if (!res) {
            return 0;
        }
    }
    //Attention! may be wrong here!
    *(myStack->top) = elem;
    myStack->top++;
    return 1;
}

int pop(Stack *myStack, int *elem) {
    if (myStack->base == myStack->top) {
        return 0;
    }
    *elem = *(--myStack->top);
    return 1;
}

int printStack(Stack * myStack) {
    if (NULL == myStack) {
        return 0;
    }
    int * cur = myStack->base;
    while (cur != myStack->top) {
        printf("%d ",*cur);
        cur++;
    }
    return 1;
}


