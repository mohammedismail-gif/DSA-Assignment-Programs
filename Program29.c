#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

/* Insert node at end */
struct node* insertEnd(struct node* head, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Insert node in the middle (after given position) */
struct node* insertMiddle(struct node* head, int val, int pos) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    int i;

    newNode->data = val;

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

/* Delete middle node */
struct node* deleteMiddle(struct node* head) {
    struct node *slow, *fast, *prev;

    if (head == NULL || head->next == NULL) {
        printf("Cannot delete middle node\n");
        return head;
    }

    slow = head;
    fast = head;
    prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    free(slow);
    return head;
}

/* Display linked list */
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Main function */
int main() {
    struct node* head = NULL;
    int n, val, pos, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    printf("Original List: ");
    display(head);

    printf("Enter value to insert in middle: ");
    scanf("%d", &val);

    printf("Enter position (after which to insert): ");
    scanf("%d", &pos);

    head = insertMiddle(head, val, pos);
    printf("After Insertion: ");
    display(head);

    head = deleteMiddle(head);
    printf("After Deletion of Middle: ");
    display(head);
    system("getmac");
    return 0;
}
