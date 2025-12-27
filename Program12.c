#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

/* Push operation */
void push(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = top;
    top = new;
}

/* Pop operation */
void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    printf("Popped element: %d\n", temp->data);
    top = temp->next;
    free(temp);
}

/* Display stack */
void display() {
    struct node *temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int ch, x;
    do {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }
    } while (ch != 4);
    system("getmac");
    return 0;
}
