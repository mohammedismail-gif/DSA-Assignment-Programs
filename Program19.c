#include <stdio.h>
#include <stdlib.h>

/* Structure for tree node */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Queue node structure for tree nodes */
struct queueNode {
    struct node *treeNode;
    struct queueNode *next;
};

/* Queue operations */
struct queueNode *front = NULL, *rear = NULL;

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

/* Function to create a new tree node */
struct node* createNode(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Inorder traversal */
void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int x;
    struct node *root = NULL;
    struct node *temp;

    printf("Enter root value: ");
    scanf("%d", &x);
    root = createNode(x);
    enqueue(root);

    while(!isEmpty()) {
        temp = dequeue();

        printf("Enter left child of %d (-1 for NULL): ", temp->data);
        scanf("%d", &x);
        if(x != -1) {
            temp->left = createNode(x);
            enqueue(temp->left);
        }

        printf("Enter right child of %d (-1 for NULL): ", temp->data);
        scanf("%d", &x);
        if(x != -1) {
            temp->right = createNode(x);
            enqueue(temp->right);
        }
    }

    printf("Inorder traversal of the tree: ");
    inorder(root);
    printf("\n");
    system("getmac");
    return 0;
}
