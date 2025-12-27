#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Insert node at the end */
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
    #include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

struct node *last = NULL;

/* Insert at end */
void insert(int val) 
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;   // circular link
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

/* Delete a node */
void delete(int val) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *curr = last->next, *prev = last;

    do {
        if (curr->data == val) {
            if (curr == last && curr->next == last) {
                last = NULL;
            } else {
                prev->next = curr->next;
                if (curr == last)
                    last = prev;
            }
            free(curr);
            printf("Deleted %d\n", val);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last->next);

    printf("Element not found\n");
}

/* Display list */
void display() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main() {
    int ch, val;

    do {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete(val);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}
    system("getmac");
    return 0;
}
