#include<stdio.h>

#define MAX 5

int queue[MAX];
int front=-1,rear=-1;

void enqueue(int x){
    if(rear==MAX-1){
        printf("Queue Overflow\n");
        return;
    }

    if(front==-1)
        front=0;

    queue[++rear]=x;
    printf("Job added\n");
}

void dequeue(){
    if(front==-1 || front>rear){
        printf("Queue Underflow\n");
        return;
    }

    printf("Job %d processed\n",queue[front++]);

    if(front>rear)
        front=rear=-1;
}

void display(){
    int i;

    if(front==-1){
        printf("Queue is empty\n");
        return;
    }

    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);

    printf("\n");
}

int main(){
    int choice,x;

    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice==1){
            printf("Enter Job ID: ");
            scanf("%d",&x);
            enqueue(x);
        }
        else if(choice==2)
            dequeue();
        else if(choice==3)
            display();
        else if(choice==4)
            break;
        else
            printf("Invalid choice\n");
    }

    return 0;
}