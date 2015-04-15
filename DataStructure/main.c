#include <stdio.h>
#include <stdlib.h>
#include "stringAlgorithm.h"
#include "stackOfTree.h"

int main(void)
{
    //const char * a = "ababcababc";
    //const char * b = "abc";
    //printf("%d", kmp(a,b));
    TreeNode *myTree = createTree();
    printf("\nPreTraverse:");
    proOrderTraverse(myTree);
    printf("\nInTraverse:");
    inOrderTraverse(myTree);
    printf("\nPostTraverse:");
    postOrderTraverse(myTree);
    return 0;
}
