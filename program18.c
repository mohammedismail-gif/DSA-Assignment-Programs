#include <stdio.h>

void inorder(int tree[], int n, int index) {
    if (index >= n || tree[index] == -1) return; // -1 indicates empty node

    inorder(tree, n, 2*index + 1); // left child
    printf("%d ", tree[index]);
    inorder(tree, n, 2*index + 2); // right child
}

int main() {
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int tree[n];
    printf("Enter node values (-1 for NULL node):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &tree[i]);

    printf("Inorder traversal of the tree: ");
    inorder(tree, n, 0);
    printf("\n");
    system("getmac");
    return 0;
}
