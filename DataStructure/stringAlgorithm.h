#include <string.h>
//KMP Algorithm
void getNext(const char * str, int *next) {
    int i = 1;
    int j = 0;
    next[0] = next[1] = 0;
    while (i < strlen(str)) {
        if (j == 0 && str[i] == str[j]) {
            i++;
            j++;
            next[i] = j;
        } else if (j == 0 && str[i] != str[j]) {
            i++;
            next[i] = 0;
        } else if (j != 0 && str[i] == str[j]) {

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
    i = 0;
    int j = 0;
    while (i < strlen(a) && j < strlen(b)) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else if (j == 0) {
            i++;
        } else {
            j = next[j];
        }
    }
    if (j > strlen(b))
        return i - strlen(b);
    else
        return -1;
}


//BM Algorithm



//Sunday Algorithm
