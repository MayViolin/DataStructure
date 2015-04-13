#include <stdio.h>
#include <stdlib.h>
#include "stringAlgorithm.h"

int main(void)
{
    const char * a = "abaabc";
    const char * b = "abc";
    printf("%d", kmp(a,b));
    return 0;
}
