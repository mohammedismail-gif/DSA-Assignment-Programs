#include <stdio.h>
#include <stdlib.h>

struct node {
    int row, col, val;
    struct node *next;
};

struct node* createNode(int r, int c, int v) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->row = r;
    n->col = c;
    n->val = v;
    n->next = NULL;
    return n;
}

int main() {
    int rows, cols, i, j, x;
    struct node *head = NULL, *temp = NULL, *newNode;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &x);
            if (x != 0) {
                newNode = createNode(i, j, x);
                if (head == NULL) {
                    head = temp = newNode;
                } else {
                    temp->next = newNode;
                    temp = newNode;
                }
            }
        }
    }

    printf("\nSparse Matrix Representation (Linked List):\n");
    printf("Row  Col  Value\n");

    temp = head;
    while (temp != NULL) {
        printf("%d    %d    %d\n", temp->row, temp->col, temp->val);
        temp = temp->next;
    }
    system("getmac");
    return 0;
}
