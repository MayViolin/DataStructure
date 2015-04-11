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
    printf("%d ", cur->data);
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
  return NULL;
}

int findPosition(LinkedList *list, int elem) {
  if (NULL == list) {
    return -1;
  }
  Node* cur = list->next;
  int position = 0;
  while (cur) {
    if (cur->data == elem) {
      return position;
    }
    cur = cur->next;
    position++;
  }
  return -1;
}

int findInsertPos(LinkedList *list, int elem) {
  if (NULL == list) {
    return -1;
  }
  int position = 0;
  Node *cur = list->next;
  while (cur) {
    if (elem < cur->data) {
      return position;
    }
    cur = cur->next;
    position++;
  }
  return position - 1;
}

LinkedList * insertElem(LinkedList *list, int elem) {
  if (NULL == list) {
    return -1;
  }
  Node *pre = list;
  Node *cur = list->next;
  while (cur) {
    if (elem < cur->data) {
      Node* temp = (Node*)malloc(sizeof(Node));
      temp->data = elem;
      temp->next = cur;
      pre->next = temp;
      return list;
    }
    pre = pre->next;
    cur = cur->next;
  }
  return list;
}

LinkedList * deleteElem(LinkedList *list, int elem) {

}

LinkedList * mergeList(LinkedList *listOne, LinkedList *listTwo) {
  if (NULL == listOne && NULL == listTwo) {
    return NULL;
  } else if (NULL == listOne && NULL != listTwo) {
    return listTwo;
  } else if (NULL != listTwo && NULL == listOne) {
    return listOne;
  } else {
    int mergeListSize = listOne->data + listTwo->data;
    LinkedList * listMergeCur = (LinkedList*)malloc(sizeof(Node)*mergeListSize);
    if (NULL == listMergeCur) return NULL;
    Node* listOneCur = listOne->next;
    Node* listTwoCur = listTwo->next;
    listMergeCur->data = mergeListSize;
    listMergeCur->next = NULL;
    Node* listMerge = listMergeCur;
    while (listOneCur && listTwoCur) {
      Node* temp = (Node*)malloc(sizeof(Node));
      if (NULL == temp) return NULL;
      if (listOneCur->data < listTwoCur->data) {
        temp->data = listOneCur->data;
        temp->next = NULL;
        listMergeCur->next = temp;
        listMergeCur = temp;
        listOneCur = listOneCur->next;
      } else if (listOneCur->data > listTwoCur->data) {
        temp->data = listTwoCur->data;
        temp->next = NULL;
        listMergeCur->next = temp;
        listMergeCur = temp;
        listTwoCur = listTwoCur->next;
      } else {
        temp->data = listTwoCur->data;
        temp->next = NULL;
        listMergeCur->next = temp;
        listMergeCur = temp;
        listOneCur = listOneCur->next;
        listTwoCur = listTwoCur->next;
      }
    }
    while (listOneCur) {
      Node* temp = (Node*)malloc(sizeof(Node));
      if (NULL == temp) return NULL;
      temp->data = listOneCur->data;
      temp->next = NULL;
      listMergeCur->next = temp;
      listMergeCur = temp;
      listOneCur = listOneCur->next;
    }
    while (listTwoCur) {
      Node* temp = (Node*)malloc(sizeof(Node));
      if (NULL == temp) return NULL;
      temp->data = listTwoCur->data;
      temp->next = NULL;
      listMergeCur->next = temp;
      listMergeCur = temp;
      listTwoCur = listTwoCur->next;
    }
    return listMerge;
  }
}
