#include <stdio.h>
#include <stdlib.h>

/* Structure for tree node */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Create new node */
struct node* createNode(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Inorder traversal */
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Insert node (simple insertion for demo: left if possible, else right) */
struct node* insert(struct node* root, int x) {
    if (root == NULL) return createNode(x);

    if (!root->left)
        root->left = insert(root->left, x);
    else if (!root->right)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left, x); // simple insertion strategy
    return root;
}

int main() {
    struct node* root = NULL;
    int n, i, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter node %d value: ", i+1);
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Inorder traversal of the tree: ");
    inorder(root);
    printf("\n");
    system("getmac");
    return 0;
}
