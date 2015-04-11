#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(void)
{
    int a[] = {1,3,5,7,9};
    int b[] = {2,4,6};
    int size = 5;

    LinkedList *listOne;
    LinkedList *listTwo;
    LinkedList *listThree;
    listOne = createList(a,size);
    listTwo = createList(b,3);

    listThree = mergeList(listOne, listTwo);
    printList(listThree);
    //printf("\n%d\n",findInsertPos(listOne,8));
    listOne = insertElem(listOne, 8);
    printList(listOne);
    releaseList(listOne);
    releaseList(listTwo);
    releaseList(listThree);
    return 0;
}
