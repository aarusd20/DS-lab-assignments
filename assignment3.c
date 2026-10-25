
#include <stdio.h>
#define MAX 50

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student db[MAX];
int n = 0;

void create() {
    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter roll, name and marks: ");
        scanf("%d %s %f", &db[i].roll, db[i].name, &db[i].marks);
    }
}

void display() {
    if (n == 0) {
        printf("Database empty\n");
        return;
    }

    for (int i = 0; i < n; i++)
        printf("%d %s %.2f\n", db[i].roll, db[i].name, db[i].marks);
}

void linearSearch() {
    int key;
    printf("Enter roll to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (db[i].roll == key) {
            printf("Found: %s %.2f\n", db[i].name, db[i].marks);
            return;
        }
    }
    printf("Not found\n");
}

void binarySearch() {
    int key, low = 0, high = n - 1;
    printf("Enter roll to search: ");
    scanf("%d", &key);

    while (low <= high) {
        int mid = (low + high) / 2;

        if (db[mid].roll == key) {
            printf("Found: %s %.2f\n", db[mid].name, db[mid].marks);
            return;
        }
        if (db[mid].roll < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Not found\n");
}

void insertionSort() {
    for (int i = 1; i < n; i++) {
        struct Student key = db[i];
        int j = i - 1;

        while (j >= 0 && db[j].roll > key.roll) {
            db[j + 1] = db[j];
            j--;
        }
        db[j + 1] = key;
    }
}

void selectionSort() {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++)
            if (db[j].roll < db[min].roll)
                min = j;

        struct Student temp = db[i];
        db[i] = db[min];
        db[min] = temp;
    }
}

void shellSort() {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            struct Student temp = db[i];
            int j;

            for (j = i; j >= gap && db[j-gap].roll > temp.roll; j -= gap)
                db[j] = db[j-gap];

            db[j] = temp;
        }
    }
}

int main() {
    int ch;

    do {
        printf("\n1.Create 2.Display 3.Linear Search");
        printf("\n4.Binary Search 5.Insertion Sort");
        printf("\n6.Selection Sort 7.Shell Sort 8.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: linearSearch(); break;
            case 4: binarySearch(); break;
            case 5: insertionSort(); display(); break;
            case 6: selectionSort(); display(); break;
            case 7: shellSort(); display(); break;
            case 8: printf("Exiting\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 8);

    return 0;
}
