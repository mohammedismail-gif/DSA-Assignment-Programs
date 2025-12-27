#include <stdio.h>
#include <stdlib.h>

/* Tree node structure */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Queue node structure */
struct queueNode {
    struct node *treeNode;
    struct queueNode *next;
};

/* Queue pointers */
struct queueNode *front = NULL, *rear = NULL;

/* Enqueue tree node */
void enqueue(struct node *t) {
    struct queueNode *newQ = (struct queueNode*)malloc(sizeof(struct queueNode));
    newQ->treeNode = t;
    newQ->next = NULL;
    if(rear == NULL) {
        front = rear = newQ;
    } else {
        rear->next = newQ;
        rear = newQ;
    }
}

/* Dequeue tree node */
struct node* dequeue() {
    if(front == NULL) return NULL;
    struct queueNode *temp = front;
    struct node *t = temp->treeNode;
    front = front->next;
    if(front == NULL) rear = NULL;
    free(temp);
    return t;
}

int isEmpty() {
    return front == NULL;
}

/* Create new tree node */
struct node* createNode(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* BFS Traversal */
void BFS(struct node *root) {
    if(root == NULL) return;
    enqueue(root);
    while(!isEmpty()) {
        struct node *temp = dequeue();
        printf("%d ", temp->data);
        if(temp->left != NULL) enqueue(temp->left);
        if(temp->right != NULL) enqueue(temp->right);
    }
}

int main() {
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter node values (-1 for NULL node):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    /* Build tree using array level-order */
    struct node *root = NULL;
    struct node *nodes[n];
    for(i = 0; i < n; i++) {
        if(arr[i] == -1) {
            nodes[i] = NULL;
            continue;
        }
        nodes[i] = createNode(arr[i]);
        if(i == 0) root = nodes[i];
        int parent = (i - 1) / 2;
        if(nodes[parent] != NULL) {
            if(i % 2 == 1) nodes[parent]->left = nodes[i];
            else nodes[parent]->right = nodes[i];
        }
    }

    printf("BFS (Level-Order) traversal of the tree: ");
    BFS(root);
    printf("\n");
    system("getmac");
    return 0;
}
