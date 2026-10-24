
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

/* Insert a term in descending order of exponent */
void insertTerm(struct Node **head, int coeff, int exp) {
    struct Node *newNode, *temp, *prev;

    if (coeff == 0) {
        return;
    }

    /* Create the first node */
    if (*head == NULL) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    /* Check whether the exponent already exists */
    temp = *head;

    do {
        if (temp->exp == exp) {
            temp->coeff += coeff;

            /* Remove the term if its coefficient becomes zero */
            if (temp->coeff == 0) {
                if (temp->next == temp) {
                    *head = NULL;
                    free(temp);
                    return;
                }

                prev = temp->next;

                while (prev->next != temp) {
                    prev = prev->next;
                }

                prev->next = temp->next;

                if (*head == temp) {
                    *head = temp->next;
                }

                free(temp);
            }

            return;
        }

        temp = temp->next;
    } while (temp != *head);

    /* Insert before the head if the exponent is largest */
    if (exp > (*head)->exp) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        newNode->coeff = coeff;
        newNode->exp = exp;

        temp = *head;

        while (temp->next != *head) {
            temp = temp->next;
        }

        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
        return;
    }

    /* Find the correct position */
    temp = *head;

    while (temp->next != *head &&
           temp->next->exp > exp) {
        temp = temp->next;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->coeff = coeff;
    newNode->exp = exp;

    newNode->next = temp->next;
    temp->next = newNode;
}

/* Create a polynomial */
struct Node *createPolynomial() {
    struct Node *head = NULL;
    int n, coeff, exp, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Number of terms cannot be negative.\n");
        return NULL;
    }

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);

        if (exp < 0) {
            printf("Exponent must be non-negative. Try again.\n");
            i--;
            continue;
        }

        insertTerm(&head, coeff, exp);
    }

    return head;
}

/* Display a polynomial */
void displayPolynomial(struct Node *head) {
    struct Node *temp;
    int first = 1;
    long long c;

    if (head == NULL) {
        printf("0");
        return;
    }

    temp = head;

    do {
        c = temp->coeff;

        if (first) {
            if (c < 0) {
                printf("-");
                c = -c;
            }
        } else {
            if (c < 0) {
                printf(" - ");
                c = -c;
            } else {
                printf(" + ");
            }
        }

        if (temp->exp == 0) {
            printf("%lld", c);
        } else {
            if (c != 1) {
                printf("%lld", c);
            }

            printf("x");

            if (temp->exp != 1) {
                printf("^%d", temp->exp);
            }
        }

        first = 0;
        temp = temp->next;

    } while (temp != head);
}

/* Add two polynomials */
struct Node *addPolynomial(struct Node *p1,
                           struct Node *p2) {
    struct Node *result = NULL;
    struct Node *temp;

    /* Copy all terms of the first polynomial */
    if (p1 != NULL) {
        temp = p1;

        do {
            insertTerm(&result, temp->coeff, temp->exp);
            temp = temp->next;
        } while (temp != p1);
    }

    /* Add all terms of the second polynomial */
    if (p2 != NULL) {
        temp = p2;

        do {
            insertTerm(&result, temp->coeff, temp->exp);
            temp = temp->next;
        } while (temp != p2);
    }

    return result;
}

/* Free the circular linked list */
void freePolynomial(struct Node **head) {
    struct Node *current, *nextNode;

    if (*head == NULL) {
        return;
    }

    current = (*head)->next;

    while (current != *head) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(*head);
    *head = NULL;
}

/* Main function */
int main() {
    struct Node *p1 = NULL;
    struct Node *p2 = NULL;
    struct Node *sum = NULL;
    int choice;

    do {
        printf("\n\n===== Polynomial Operations =====\n");
        printf("1. Create First Polynomial\n");
        printf("2. Create Second Polynomial\n");
        printf("3. Display Polynomials\n");
        printf("4. Add Polynomials\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                freePolynomial(&p1);
                p1 = createPolynomial();
                printf("First polynomial created: ");
                displayPolynomial(p1);
                printf("\n");
                break;

            case 2:
                freePolynomial(&p2);
                p2 = createPolynomial();
                printf("Second polynomial created: ");
                displayPolynomial(p2);
                printf("\n");
                break;

            case 3:
                printf("First Polynomial: ");
                displayPolynomial(p1);

                printf("\nSecond Polynomial: ");
                displayPolynomial(p2);
                printf("\n");
                break;

            case 4:
                freePolynomial(&sum);
                sum = addPolynomial(p1, p2);

                printf("First Polynomial: ");
                displayPolynomial(p1);

                printf("\nSecond Polynomial: ");
                displayPolynomial(p2);

                printf("\nResultant Polynomial: ");
                displayPolynomial(sum);
                printf("\n");
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    freePolynomial(&p1);
    freePolynomial(&p2);
    freePolynomial(&sum);

    return 0;
}
