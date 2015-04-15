typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode * createTree() {
    TreeNode *root;
    int elem;
    scanf("%d",&elem);
    if (elem == 0) {
        return NULL;
    } else {
        root = (TreeNode*)malloc(sizeof(TreeNode));
        root->data = elem;
        root->left = createTree();
        root->right = createTree();
    }
    return root;
}

void proOrderTraverse(TreeNode *root) {
    if (NULL == root) {
        //printf("ERROR!");
        return;
    }
    printf("%d", root->data);
    if (root->left) {
        proOrderTraverse(root->left);
    }
    if (root->right) {
        proOrderTraverse(root->right);
    }
}

void inOrderTraverse(TreeNode *root) {
    if (NULL == root) {
        return;
    }
    if (root->left) {
        inOrderTraverse(root->left);
    }
    printf("%d", root->data);
    if (root->right) {
        inOrderTraverse(root->right);
    }
}

void postOrderTraverse(TreeNode *root) {
    if (NULL == root) {
        return;
    }
    if (root->left) {
        postOrderTraverse(root->left);
    }
    if (root->right) {
        postOrderTraverse(root->right);
    }
    printf("%d", root->data);
}

void levelTraverse(TreeNode *root) {

}
