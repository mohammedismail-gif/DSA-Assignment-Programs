#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main() {
    struct node *n1, *n2;
    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));
    printf("Enter first node data: ");
    scanf("%d", &n1->data);
    printf("Enter second node data: ");
    scanf("%d", &n2->data);
    n1->next = n2;
    n2->next = NULL;
    printf("Linked list data:\n");
    printf("%d -> %d -> NULL", n1->data, n1->next->data);
    free(n1);
    free(n2);
    system("getmac");
    return 0;
}
