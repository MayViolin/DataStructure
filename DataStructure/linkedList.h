#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#endif // LINKEDLIST_H_INCLUDED

typedef struct Node {
  int data;
  struct Node *next;
}Node;

typedef Node LinkedList;

LinkedList * createList(int arr[], int size) {
  if (0 == size || NULL == arr) {
    return NULL;
  }
  LinkedList* head = (LinkedList*)malloc(sizeof(Node)*size);
  if (NULL == head) {
    return NULL;
  }
  head->data = size;
  head->next = NULL;
  Node* cur = head;
  int i;
  for (i = 0; i < size; i++) {
    Node *temp = (Node*)malloc(sizeof(Node)*size);
    if (NULL == temp) {
        return NULL;
    }
    temp->data = arr[i];
    temp->next = cur->next;
    cur->next = temp;
    cur = temp;
  }
  return head;
}

void printList(LinkedList* list) {
  Node* cur = list->next;
  while (NULL != cur) {
    printf("%d", cur->data);
    cur = cur->next;
  }
}

void releaseList(LinkedList *list) {
  Node *cur = list;
  while (NULL != cur) {
    Node *temp = cur->next;
    free(cur);
    cur = temp;
  }
}

int findMiddleNode(LinkedList *list) {
  if (NULL == list) {
    return -1;
  }
  Node *oneStep = list->next;
  Node *twoStep = oneStep;

  while (NULL != twoStep && NULL != twoStep->next) {
    oneStep = oneStep->next;
    twoStep = twoStep->next->next;
  }
  return oneStep->data;
}

LinkedList * reverseList(LinkedList *list) {

}
