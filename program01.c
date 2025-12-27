#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 5;
    int *arr = (int *)malloc(n * sizeof(int));

    // Initialize memory to 0
    memset(arr, 0, n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    system("getmac");
    return 0;
}
