typedef struct Node {
    int data;
    struct Node * next;
}Node;

typedef struct Queue {
    Node *head;
    Node *tail;
}Queue;

Queue *initQueue(Queue * myQueue) {
    myQueue->head = myQueue->tail = (Node*)malloc(sizeof(Node));
    if (NULL == myQueue->head) return NULL;
    myQueue->head->next = NULL;
    return myQueue;
}

int enQueue(Queue * myQueue, int elem) {
    if (NULL == myQueue) {
        return 0;
    }
    Node *temp = (Node*)malloc(sizeof(Node));
    if (NULL == temp) {
        return 0;
    }
    temp->data = elem;
    temp->next = NULL;
    myQueue->tail->next = temp;
    myQueue->tail = temp;
    return 1;
 }

int deQueue(Queue * myQueue, int *elem) {
    if (NULL == myQueue) {
        return 0;
    }
    Node *temp = myQueue->head->next;
    *elem = temp->data;
    myQueue->head->next = temp->next;
    free(temp);
    return 1;
}

int printQueue(Queue * myQueue) {
    if (NULL == myQueue) {
        return 0;
    }
    Node *cur = myQueue->head->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    return 1;
}
