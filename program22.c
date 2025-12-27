#include <stdio.h>
#include <stdlib.h>

/* Structure for tree node */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Create a new tree node */
struct node* createNode(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Depth-First Search (Preorder Traversal) */
void DFS(struct node* root) {
    if(root == NULL) return;
    printf("%d ", root->data); // Visit root
    DFS(root->left);           // Visit left subtree
    DFS(root->right);          // Visit right subtree
}

/* Function to insert nodes level-wise using queue */
struct node* insertLevelOrder(int arr[], int i, int n) {
    if(i >= n || arr[i] == -1) return NULL;
    struct node* root = createNode(arr[i]);
    root->left = insertLevelOrder(arr, 2*i + 1, n);
    root->right = insertLevelOrder(arr, 2*i + 2, n);
    return root;
}

int main() {
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter node values (-1 for NULL node):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = insertLevelOrder(arr, 0, n);

    printf("DFS (Preorder) traversal of the tree: ");
    DFS(root);
    printf("\n");
    system("getmac");
    return 0;
}
