
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

void insertTerm(struct Node **head, int coeff, int exp) {
    struct Node *newNode, *temp, *prev;

    if (coeff == 0)
        return;

    if (*head == NULL) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL)
            exit(EXIT_FAILURE);

        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    temp = *head;

    do {
        if (temp->exp == exp) {
            temp->coeff += coeff;

            if (temp->coeff == 0) {
                if (temp->next == temp) {
                    *head = NULL;
                    free(temp);
                    return;
                }

                prev = temp->next;

                while (prev->next != temp)
                    prev = prev->next;

                prev->next = temp->next;

                if (*head == temp)
                    *head = temp->next;

                free(temp);
            }

            return;
        }

        temp = temp->next;
    } while (temp != *head);

    if (exp > (*head)->exp) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL)
            exit(EXIT_FAILURE);

        newNode->coeff = coeff;
        newNode->exp = exp;

        temp = *head;

        while (temp->next != *head)
            temp = temp->next;

        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != *head && temp->next->exp > exp)
        temp = temp->next;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
        exit(EXIT_FAILURE);

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = temp->next;
    temp->next = newNode;
}

struct Node *createPolynomial() {
    struct Node *head = NULL;
    int n, coeff, exp, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid number of terms.\n");
        return NULL;
    }

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);

        if (exp < 0) {
            printf("Exponent must be non-negative.\n");
            i--;
            continue;
        }

        insertTerm(&head, coeff, exp);
    }

    return head;
}

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
            if (c != 1)
                printf("%lld", c);

            printf("x");

            if (temp->exp != 1)
                printf("^%d", temp->exp);
        }

        first = 0;
        temp = temp->next;

    } while (temp != head);
}

struct Node *addPolynomial(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;
    struct Node *temp;

    if (p1 != NULL) {
        temp = p1;

        do {
            insertTerm(&result, temp->coeff, temp->exp);
            temp = temp->next;
        } while (temp != p1);
    }

    if (p2 != NULL) {
        temp = p2;

        do {
            insertTerm(&result, temp->coeff, temp->exp);
            temp = temp->next;
        } while (temp != p2);
    }

    return result;
}

void freePolynomial(struct Node **head) {
    struct Node *current, *nextNode;

    if (*head == NULL)
        return;

    current = (*head)->next;

    while (current != *head) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(*head);
    *head = NULL;
}

int main() {
    struct Node *p1 = NULL;
    struct Node *p2 = NULL;
    struct Node *sum = NULL;
    int choice;

    do {
        printf("\n===== Polynomial Operations =====\n");
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
                printf("First Polynomial: ");
                displayPolynomial(p1);
                printf("\n");
                break;

            case 2:
                freePolynomial(&p2);
                p2 = createPolynomial();
                printf("Second Polynomial: ");
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
