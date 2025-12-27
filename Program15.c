#include <stdio.h>

int main() {
    int m, n, i, j, k = 0;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int mat[m][n];
    printf("Enter elements of the matrix:\n");
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    /* Count non-zero elements */
    int count = 0;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            if(mat[i][j] != 0)
                count++;

    /* Sparse matrix representation */
    int sparse[count][3];
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            if(mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }

    printf("\nSparse Matrix Representation (row col value):\n");
    for(i = 0; i < count; i++)
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    system("getmac");
    return 0;
}
