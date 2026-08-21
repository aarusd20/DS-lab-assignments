#include <stdio.h> 
void input(int a[10][10], int r, int c) 
{ 
} 
int i, j; 
for(i = 0; i < r; i++) 
for(j = 0; j < c; j++) 
scanf("%d", &a[i][j]); 
void display(int a[10][10], int r, int c) 
{ 
} 
int i, j; 
for(i = 0; i < r; i++) 
{ 
} 
for(j = 0; j < c; j++) 
printf("%d ", a[i][j]); 
printf("\n"); 
void add(int a[10][10], int b[10][10], int r, int c) 
{ 
} 
int i, j, sum[10][10]; 
for(i = 0; i < r; i++) 
for(j = 0; j < c; j++) 
sum[i][j] = a[i][j] + b[i][j]; 
printf("\nAddition:\n"); 
display(sum, r, c); 
void subtract(int a[10][10], int b[10][10], int r, int c) 
{ 
int i, j, sub[10][10]; 
for(i = 0; i < r; i++) 
for(j = 0; j < c; j++) 
sub[i][j] = a[i][j] - b[i][j]; 
printf("\nSubtraction:\n"); 
display(sub, r, c); 
} 
void multiply(int a[10][10], int b[10][10], int r1, int c1, int c2) 
{ 
} 
int i, j, k, mul[10][10]; 
for(i = 0; i < r1; i++) 
{ 
} 
for(j = 0; j < c2; j++) 
{ 
} 
mul[i][j] = 0; 
for(k = 0; k < c1; k++) 
mul[i][j] += a[i][k] * b[k][j]; 
printf("\nMultiplication:\n"); 
display(mul, r1, c2); 
void transpose(int a[10][10], int r, int c) 
{ 
int i, j, t[10][10]; 
for(i = 0; i < r; i++) 
for(j = 0; j < c; j++) 
t[j][i] = a[i][j]; 
printf("\nTranspose:\n"); 
display(t, c, r); 
} 
int main() 
{ 
int a[10][10], b[10][10]; 
int r1, c1, r2, c2, ch; 
printf("Enter rows and columns of Matrix A (max 10x10): "); 
scanf("%d%d", &r1, &c1); 
printf("Enter elements of Matrix A:\n"); 
input(a, r1, c1); 
printf("Enter rows and columns of Matrix B (max 10x10): "); 
scanf("%d%d", &r2, &c2); 
printf("Enter elements of Matrix B:\n"); 
input(b, r2, c2); 
do 
{ 
printf("\n--- MATRIX OPERATIONS MENU ---\n"); 
printf("1. Addition\n"); 
printf("2. Subtraction\n"); 
printf("3. Multiplication\n"); 
printf("4. Transpose of Matrix A\n"); 
printf("5. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &ch); 
switch(ch) 
{ 
            case 1: 
                if (r1 == r2 && c1 == c2) 
                { 
                    add(a, b, r1, c1); 
                } 
                else 
                { 
                    printf("\nError: Addition not possible! Matrix dimensions must match (Matrix A: %dx%d 
vs Matrix B: %dx%d).\n", r1, c1, r2, c2); 
                } 
                break; 
            case 2: 
                if (r1 == r2 && c1 == c2) 
                { 
                    subtract(a, b, r1, c1); 
                } 
                else 
                { 
                    printf("\nError: Subtraction not possible! Matrix dimensions must match (Matrix A: 
%dx%d vs Matrix B: %dx%d).\n", r1, c1, r2, c2); 
                } 
                break; 
            case 3: 
                if (c1 == r2) 
                { 
                    multiply(a, b, r1, c1, c2); 
                } 
                else 
                { 
                    printf("\nError: Multiplication not possible! Columns of A (%d) must equal rows of B 
(%d).\n", c1, r2); 
                } 
                break; 
            case 4: 
                transpose(a, r1, c1); 
                break; 
            case 5: 
                printf("\nExiting program...\n"); 
                break; 
 
            default: 
                printf("\nInvalid choice. Please enter a number between 1 and 5.\n"); 
        } 
    } while(ch != 5); 
 
    return 0; 
} 