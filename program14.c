#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Linked List insertion at end */
void ll_insert(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;

    if (head == NULL)
        head = new;
    else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}

/* Linked List deletion from end */
void ll_delete() {
    if (head == NULL) return;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    clock_t start, end;

    /* Array insertion */
    start = clock();
    for (i = 0; i < n; i++)
        arr[i] = i;
    end = clock();
    printf("Array insertion time: %f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);

    /* Linked list insertion */
    start = clock();
    for (i = 0; i < n; i++)
        ll_insert(i);
    end = clock();
    printf("Linked list insertion time: %f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);

    /* Array deletion (from end) */
    start = clock();
    for (i = n-1; i >= 0; i--)
        arr[i] = 0; // just clearing
    end = clock();
    printf("Array deletion time: %f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);

    /* Linked list deletion */
    start = clock();
    for (i = 0; i < n; i++)
        ll_delete();
    end = clock();
    printf("Linked list deletion time: %f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);

    free(arr);
    system("getmac");
    return 0;
}
