#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(void)
{
    String myString;
    String myString2;
    char a[] = {'a','b','c','d'};
    char b[] = {'a','b','c'};
    String * test = initString(&myString, a, 4);
    String * testForEaqual = initString(&myString2,b,3);
    String myStringTwo;
    String * testTwo = copyString(&myStringTwo, test);
    printString(test);
    printf("\n");
    printString(testForEaqual);
    printf("%d",compareString(test, testForEaqual));
    return 0;
}
