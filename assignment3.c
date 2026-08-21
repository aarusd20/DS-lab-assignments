#include <stdio.h>
#include <string.h>

#define MAX 50
struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student db[MAX];
int n = 0;

void inputStudents() {
    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("  Roll No : ");
        scanf("%d", &db[i].roll);
        printf("  Name    : ");
        scanf("%s", db[i].name);
        printf("  Marks   : ");
        scanf("%f", &db[i].marks);
    }
}

void displayStudents() {
    if (n == 0) {
        printf("\nDatabase is empty. Please create it first (Option 1).\n");
        return;
    }
    printf("\n%-10s%-20s%-10s\n", "Roll", "Name", "Marks");
    printf("---------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d%-20s%-10.2f\n", db[i].roll, db[i].name, db[i].marks);
    }
}

void linearSearch() {
    if (n == 0) { printf("\nDatabase is empty.\n"); return; }

    int key;
    printf("Enter Roll No to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (db[i].roll == key) {
            printf("Found at position %d -> Name: %s, Marks: %.2f\n",
                   i + 1, db[i].name, db[i].marks);
            return;
        }
    }
    printf("Roll No %d not found.\n", key);
}

void binarySearch() {
    if (n == 0) { printf("\nDatabase is empty.\n"); return; }

    struct Student temp[MAX];
    memcpy(temp, db, n * sizeof(struct Student));

    for (int i = 1; i < n; i++) {
        struct Student key = temp[i];
        int j = i - 1;
        while (j >= 0 && temp[j].roll > key.roll) {
            temp[j + 1] = temp[j];
            j--;
        }
        temp[j + 1] = key;
    }

    int keyRoll;
    printf("Enter Roll No to search: ");
    scanf("%d", &keyRoll);

    int low = 0, high = n - 1, found = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (temp[mid].roll == keyRoll) { found = mid; break; }
        else if (temp[mid].roll < keyRoll) low = mid + 1;
        else high = mid - 1;
    }

    if (found != -1)
        printf("Found -> Name: %s, Marks: %.2f\n", temp[found].name, temp[found].marks);
    else
        printf("Roll No %d not found.\n", keyRoll);
}

void insertionSort() {
    if (n == 0) { printf("\nDatabase is empty.\n"); return; }

    for (int i = 1; i < n; i++) {
        struct Student key = db[i];
        int j = i - 1;
        while (j >= 0 && db[j].roll > key.roll) {
            db[j + 1] = db[j];
            j--;
        }
        db[j + 1] = key;
    }
    printf("\nDatabase sorted using Insertion Sort.\n");
}

void selectionSort() {
    if (n == 0) { printf("\nDatabase is empty.\n"); return; }

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (db[j].roll < db[minIdx].roll)
                minIdx = j;
        }
        if (minIdx != i) {
            struct Student temp = db[i];
            db[i] = db[minIdx];
            db[minIdx] = temp;
        }
    }
    printf("\nDatabase sorted using Selection Sort.\n");
}

void shellSort() {
    if (n == 0) { printf("\nDatabase is empty.\n"); return; }

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            struct Student temp = db[i];
            int j;
            for (j = i; j >= gap && db[j - gap].roll > temp.roll; j -= gap) {
                db[j] = db[j - gap];
            }
            db[j] = temp;
        }
    }
    printf("\nDatabase sorted using Shell Sort.\n");
}

void menu() {
    printf("\n===== Student Database Menu =====\n");
    printf("1. Create Database\n");
    printf("2. Display Database\n");
    printf("3. Linear Search\n");
    printf("4. Binary Search\n");
    printf("5. Insertion Sort\n");
    printf("6. Selection Sort\n");
    printf("7. Shell Sort\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: inputStudents();   break;
            case 2: displayStudents(); break;
            case 3: linearSearch();    break;
            case 4: binarySearch();    break;
            case 5: insertionSort(); displayStudents(); break;
            case 6: selectionSort(); displayStudents(); break;
            case 7: shellSort();     displayStudents(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);

    return 0;
}

