#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    int job;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter Job ID: ");
    scanf("%d", &job);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = job;

    printf("Print job added successfully.\n");
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Job %d processed.\n", queue[front]);
    front++;
}

void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("No Pending Print Jobs.\n");
        return;
    }

    printf("Pending Jobs:\n");

    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Printer Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}