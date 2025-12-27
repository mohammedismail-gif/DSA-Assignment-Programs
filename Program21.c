#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Insert node at end (helper for testing) */
void insert(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

/* Delete node by value */
void deleteNode(int x) {
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    /* If head needs to be deleted */
    if (head->data == x) {
        head = head->next;
        free(temp);
        return;
    }

    /* Search for node to delete */
    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found\n", x);
        return;
    }

    /* Delete node */
    prev->next = temp->next;
    free(temp);
}

/* Display linked list */
void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, x, i;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &x);
        insert(x);
    }

    display();

    printf("Enter value to delete: ");
    scanf("%d", &x);
    deleteNode(x);

    display();
    system("getmac");
    return 0;
}
