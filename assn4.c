
#include <stdio.h>
#include <stdlib.h>

struct Student {
    int regNo;
    char name[50];
    struct Student *next;
};

struct Student *head = NULL;

void add() {
    struct Student *n = malloc(sizeof(struct Student));
    if (n == NULL) return;

    printf("Enter regNo and name: ");
    scanf("%d %49s", &n->regNo, n->name);
    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        struct Student *t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
}

void removeStudent() {
    struct Student *t = head, *p = NULL;
    int x;

    printf("Enter regNo to delete: ");
    scanf("%d", &x);

    while (t != NULL && t->regNo != x) {
        p = t;
        t = t->next;
    }

    if (t == NULL) {
        printf("Not found\n");
        return;
    }

    if (p == NULL) head = t->next;
    else p->next = t->next;

    free(t);
    printf("Deleted\n");
}

void display() {
    struct Student *t = head;

    while (t != NULL) {
        printf("%d %s\n", t->regNo, t->name);
        t = t->next;
    }
}

void count() {
    int c = 0;
    struct Student *t = head;

    while (t != NULL) {
        c++;
        t = t->next;
    }
    printf("Total students = %d\n", c);
}

void sort() {
    struct Student *i, *j;
    int r;
    char name[50];

    for (i = head; i != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
            if (i->regNo > j->regNo) {
                r = i->regNo;
                i->regNo = j->regNo;
                j->regNo = r;

                __builtin_strcpy(name, i->name);
                __builtin_strcpy(i->name, j->name);
                __builtin_strcpy(j->name, name);
            }
    printf("Sorted\n");
}

void reverse() {
    struct Student *p = NULL, *c = head, *n;

    while (c != NULL) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
    printf("Reversed\n");
}

int main() {
    int ch;

    do {
        printf("\n1.Add 2.Remove 3.Display 4.Count");
        printf("\n5.Sort 6.Reverse 7.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: add(); break;
            case 2: removeStudent(); break;
            case 3: display(); break;
            case 4: count(); break;
            case 5: sort(); break;
            case 6: reverse(); break;
        }
    } while (ch != 7);

    return 0;
}
