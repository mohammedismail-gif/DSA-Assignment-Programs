#include <stdio.h>
#include <string.h>

int main() {
    char t[100], p[50];
    int i, j;

    scanf("%s", t);
    scanf("%s", p);

    for (i = 0; i <= strlen(t) - strlen(p); i++) {
        for (j = 0; j < strlen(p); j++)
            if (t[i + j] != p[j])
                break;

        if (j == strlen(p))
            printf("Pattern found at position %d\n", i);
    }
    system("getmac");
    return 0;
}
