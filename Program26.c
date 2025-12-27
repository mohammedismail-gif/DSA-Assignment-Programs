#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *m, *c, i;

    /* Memory allocation using malloc */
    m = (int *)malloc(n * sizeof(int));

    /* Memory allocation using calloc */
    c = (int *)calloc(n, sizeof(int));

    printf("Values after malloc():\n");
    for(i = 0; i < n; i++)
        printf("%d ", m[i]);

    printf("\n\nValues after calloc():\n");
    for(i = 0; i < n; i++)
        printf("%d ", c[i]);

    free(m);
    free(c);
    system("getmac");
    return 0;
}
