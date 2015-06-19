#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(void)
{
    int arr[] = {9,2,1,7,6,8,5,3,4};
    heapSort(arr, 9);
    printHeap(arr, 9);
    return 0;
}
