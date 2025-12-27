#include <stdio.h>
int main() {
    int a, b;
    printf("Enter a number: ");
    scanf("%d", &a);
    b = a;
    printf("Pre-decrement (--a): %d\n", --a);
    printf("Post-decrement (b--): %d\n", b--);
    printf("Final values:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    system("getmac");
    return 0;
}
