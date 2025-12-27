#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Insert at end */
void insert(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    new->data = x;
    new->next = NULL;

    if (head == NULL)
        head = new;
    else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}

/* Delete by value */
void delete(int x) {
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->data == x) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        printf("Element not found\n");
    else {
        prev->next = temp->next;
        free(temp);
    }
}

/* Traversal */
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
    int ch, x;
    do {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &x);
                delete(x);
                break;
            case 3:
                display();
                break;
        }
    } while (ch != 4);
    system("getmac");
    return 0;
}
