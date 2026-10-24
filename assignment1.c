
#include <stdio.h>

int main() {
    int A[10][10], B[10][10], C[10][10], T[10][10];
    int r1, c1, r2, c2;
    int i, j, k, choice;

    printf("1. Matrix Addition\n");
    printf("2. Matrix Subtraction\n");
    printf("3. Matrix Multiplication\n");
    printf("4. Matrix Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 4) {
        printf("Enter rows and columns of matrix: ");
        scanf("%d %d", &r1, &c1);

        if (r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10) {
            printf("Invalid matrix dimensions.\n");
            return 0;
        }

        printf("Enter matrix elements:\n");
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++) {
                scanf("%d", &A[i][j]);
            }
        }

        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++) {
                T[j][i] = A[i][j];
            }
        }

        printf("Transpose of the matrix:\n");
        for (i = 0; i < c1; i++) {
            for (j = 0; j < r1; j++) {
                printf("%d ", T[i][j]);
            }
            printf("\n");
        }
    } else if (choice >= 1 && choice <= 3) {
        printf("Enter rows and columns of first matrix: ");
        scanf("%d %d", &r1, &c1);

        printf("Enter rows and columns of second matrix: ");
        scanf("%d %d", &r2, &c2);

        if (r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10 ||
            r2 < 1 || r2 > 10 || c2 < 1 || c2 > 10) {
            printf("Invalid matrix dimensions.\n");
            return 0;
        }

        if ((choice == 1 || choice == 2) &&
            (r1 != r2 || c1 != c2)) {
            printf("Addition and subtraction require equal dimensions.\n");
            return 0;
        }

        if (choice == 3 && c1 != r2) {
            printf("Matrix multiplication is not possible.\n");
            return 0;
        }

        printf("Enter elements of first matrix:\n");
        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++) {
                scanf("%d", &A[i][j]);
            }
        }

        printf("Enter elements of second matrix:\n");
        for (i = 0; i < r2; i++) {
            for (j = 0; j < c2; j++) {
                scanf("%d", &B[i][j]);
            }
        }

        if (choice == 1 || choice == 2) {
            for (i = 0; i < r1; i++) {
                for (j = 0; j < c1; j++) {
                    if (choice == 1) {
                        C[i][j] = A[i][j] + B[i][j];
                    } else {
                        C[i][j] = A[i][j] - B[i][j];
                    }
                }
            }

            printf("Resultant matrix:\n");
            for (i = 0; i < r1; i++) {
                for (j = 0; j < c1; j++) {
                    printf("%d ", C[i][j]);
                }
                printf("\n");
            }
        } else {
            for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++) {
                    C[i][j] = 0;
                    for (k = 0; k < c1; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            printf("Product of the matrices:\n");
            for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++) {
                    printf("%d ", C[i][j]);
                }
                printf("\n");
            }
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
