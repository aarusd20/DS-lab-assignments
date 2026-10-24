
#include <stdio.h>

int main() {
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2, i, j, k, ch;

    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    if (ch == 4) {
        printf("Transpose:\n");
        for (j = 0; j < c1; j++) {
            for (i = 0; i < r1; i++)
                printf("%d ", A[i][j]);
            printf("\n");
        }
    } else {
        printf("Enter rows and columns of second matrix: ");
        scanf("%d%d", &r2, &c2);

        printf("Enter second matrix:\n");
        for (i = 0; i < r2; i++)
            for (j = 0; j < c2; j++)
                scanf("%d", &B[i][j]);

        if (ch == 1 || ch == 2) {
            if (r1 != r2 || c1 != c2) {
                printf("Invalid dimensions");
                return 0;
            }

            for (i = 0; i < r1; i++) {
                for (j = 0; j < c1; j++) {
                    if (ch == 1)
                        C[i][j] = A[i][j] + B[i][j];
                    else
                        C[i][j] = A[i][j] - B[i][j];
                }
            }

            for (i = 0; i < r1; i++) {
                for (j = 0; j < c1; j++)
                    printf("%d ", C[i][j]);
                printf("\n");
            }
        } else if (ch == 3) {
            if (c1 != r2) {
                printf("Multiplication not possible");
                return 0;
            }

            for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++) {
                    C[i][j] = 0;
                    for (k = 0; k < c1; k++)
                        C[i][j] += A[i][k] * B[k][j];
                }
            }

            for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++)
                    printf("%d ", C[i][j]);
                printf("\n");
            }
        } else {
            printf("Invalid choice");
        }
    }

    return 0;
}
