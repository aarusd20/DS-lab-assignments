
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int regNo;
    char name[100];
    struct Student *next;
};

struct Student *head = NULL;

/* Add a student at the end */
void addStudent() {
    struct Student *newNode, *temp;

    newNode = (struct Student *)malloc(sizeof(struct Student));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter Registration Number: ");
    scanf("%d", &newNode->regNo);

    printf("Enter Student Name: ");
    scanf(" %99[^\n]", newNode->name);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Student added successfully.\n");
}

/* Remove a student using Registration Number */
void removeStudent() {
    struct Student *temp = head, *prev = NULL;
    int regNo;

    if (head == NULL) {
        printf("No students registered.\n");
        return;
    }

    printf("Enter Registration Number to remove: ");
    scanf("%d", &regNo);

    while (temp != NULL && temp->regNo != regNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Student record deleted successfully.\n");
}

/* Display all students */
void displayList() {
    struct Student *temp = head;

    if (head == NULL) {
        printf("No students registered.\n");
        return;
    }

    printf("\n--- Registered Students ---\n");

    while (temp != NULL) {
        printf("Registration Number: %d\n", temp->regNo);
        printf("Name: %s\n\n", temp->name);
        temp = temp->next;
    }
}

/* Count total participants */
void countStudents() {
    struct Student *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total participants: %d\n", count);
}

/* Sort students by Registration Number */
void sortList() {
    struct Student *i, *j;
    int tempRegNo;
    char tempName[100];

    if (head == NULL || head->next == NULL) {
        printf("List sorted successfully.\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->regNo > j->regNo) {
                tempRegNo = i->regNo;
                i->regNo = j->regNo;
                j->regNo = tempRegNo;

                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }

    printf("Students sorted by Registration Number.\n");
}

/* Reverse the linked list */
void reverseList() {
    struct Student *prev = NULL;
    struct Student *current = head;
    struct Student *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
    printf("List reversed successfully.\n");
}

/* Main function */
int main() {
    int choice;

    do {
        printf("\n===== Workshop Enrollment System =====\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display Students\n");
        printf("4. Count Participants\n");
        printf("5. Sort Students\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                removeStudent();
                break;

            case 3:
                displayList();
                break;

            case 4:
                countStudents();
                break;

            case 5:
                sortList();
                break;

            case 6:
                reverseList();
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 7);

    /* Free remaining nodes */
    while (head != NULL) {
        struct Student *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
