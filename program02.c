#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(sizeof(int));

    printf("%p\n", (void *)p);

    free(p);
    system("getmac");
    return 0;
}
