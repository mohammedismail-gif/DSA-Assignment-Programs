#include <stdio.h>
int main() {
    int a, b;
    printf("Enter a number: ");
    scanf("%d", &a);
    b = a;
    printf("Pre-increment (++a): %d\n", ++a);
    printf("Post-increment (b++): %d\n", b++);
    printf("Final values:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    system("getmac");
    return 0;
}
