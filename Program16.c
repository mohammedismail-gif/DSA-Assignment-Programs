#include <stdio.h>

int main() {
    int degree, i;
    printf("Enter degree of the polynomial: ");
    scanf("%d", &degree);

    int coeff[degree + 1];

    printf("Enter coefficients (from highest degree to constant term):\n");
    for(i = degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &coeff[i]);
    }

    /* Display polynomial */
    printf("Polynomial: ");
    for(i = degree; i >= 0; i--) {
        if(coeff[i] != 0) {
            if(i != degree && coeff[i] > 0) printf("+");
            printf("%dx^%d ", coeff[i], i);
        }
    }
    printf("\n");

    /* Evaluate polynomial for a given x */
    int x;
    printf("Enter value of x to evaluate: ");
    scanf("%d", &x);

    int result = 0;
    for(i = 0; i <= degree; i++)
        result += coeff[i] * pow(x, i);

    printf("Polynomial evaluated at x = %d: %d\n", x, result);
    system("getmac");
    return 0;
}
