// heap[] is array, n is size of heap, t is root
// to build a big heap
void swapElem(int arr[], int indexOne, int indexTwo) {
    int temp = arr[indexOne];
    arr[indexOne] = arr[indexTwo];
    arr[indexTwo] = temp;
}


void heapify(int heap[], int heapSize, int root) {
    int leftChild = 2 * root + 1;
    int rightChild = 2 * (root + 1);
    int maxIndex = root;
    if (leftChild < heapSize)
        maxIndex = heap[maxIndex] > heap[leftChild] ? maxIndex : leftChild;
    if (rightChild < heapSize)
        maxIndex = heap[maxIndex] > heap[rightChild] ? maxIndex : rightChild;
    if (maxIndex > root) {
        swapElem(heap, maxIndex, root);
        heapify(heap, heapSize, maxIndex);
    }
}

int getMaxNum(int heap[], int heapSize) {
    int maxNum = heap[0];
    heap[0] = heap[heapSize - 1];
    --heapSize;
    heapify(heap, heapSize, 0);
    return maxNum;
}

void buildHeap(int arr[], int arrSize) {
    int i = arrSize / 2 - 1;
    for (; i >= 0; --i) {
        heapify(arr, arrSize, i);
    }
}

void printHeap(int arr[], int arrSize) {
    int i = 0;
    for (; i < arrSize; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heapSort(int heap[], int heapSize) {
    buildHeap(heap, heapSize);
    printHeap(heap, heapSize);
    int i = heapSize - 1;
    for (; i >= 0; --i) {
        swapElem(heap, 0, i);
        heapify(heap, i, 0);
    }
}
