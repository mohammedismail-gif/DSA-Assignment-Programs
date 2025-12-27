 #include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, min, temp;
    int *arr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    /* Dynamic memory allocation */
    arr = (int *)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* Selection Sort */
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        /* Swap */
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    system("getmac");
    return 0;
}
