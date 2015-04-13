typedef struct String {
    char *base;
    int length;
}String;

// init string
String *initString(String * myString, char a[], int n) {
    char *temp = (char*)malloc(sizeof(char)*n);
    if (NULL == temp) {
        return NULL;
    }
    myString->base = temp;
    int i;
    for (i = 0; i < n; i++) {
        *temp = a[i];
        temp++;
    }
    myString->length = n;
    return myString;
}

// copy string
String * copyString(String * myString, String *existString) {
    if (NULL == existString) {
        return NULL;
    }
    myString->length = existString->length;
    if (0 == existString->length) {
        free(myString->base);
        return myString;
    }
    if (NULL != myString->base) {
        free(myString->base);
        myString->base = (char*)malloc(sizeof(char)*(myString->length));
    }
    int i;
    char *cur = myString->base;
    for (i = 0; i < (existString->length); i++) {
        *cur = (existString->base)[i];
        cur++;
    }
    return myString;
}

// print string
void printString(String * myString) {
    char *cur = myString->base;
    int i;
    for (i = 0; i < myString->length; i++) {
        printf("%c",(*cur)++);
    }
}

int compareString(String * a, String * b) {
    if (NULL == a || NULL == b) {
        return 0;
    }
    if (a->length == b->length) {
        int i;
        for (i = 0; i < a->length; i++) {
            if ((a->base)[i] != (b->base)[i]) {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

int findIndex(String * parentString, String * targetString) {

}


