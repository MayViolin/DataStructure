#include <string.h>

//KMP Algorithm
void getNext(const char * str, int *next) {
    int i = 0;
    int j = -1;
    next[0] = -1;
    while (i < strlen(str)) {
        if (j == -1 || str[i] == str[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int kmp(const char * a, const char * b) {
    if (NULL == a || NULL == b || strlen(b) > strlen(a)) {
        return -1;
    }
    int *next = (int*)malloc(sizeof(int)*strlen(b));
    if (NULL == next) return -1;
    getNext(b,next);
    int i;
    for (i = 0; i < strlen(b); i++) {
        printf("%d,", next[i]);
    }
    printf("\n");
    i = 0;
    int j = -1;
    while ((strlen(a) - i > 0) && (strlen(b) - j > 0)) {
        if (j == -1 && i == 0) {
            j++;
        } else if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (strlen(b) - j <= 0)
        return i - strlen(b);
    else
        return -1;
}


//BM Algorithm



//Sunday Algorithm
