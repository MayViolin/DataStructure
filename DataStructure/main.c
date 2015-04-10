#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(void)
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int size = 10;

    LinkedList *list;
    list = createList(a,size);
    if (NULL != list) {
      printList(list);
    } else {
      printf("Error!\n");
    }
    printf("%d",findMiddleNode(list));
    releaseList(list);
    return 0;
}
