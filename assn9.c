#include<stdio.h>

#define MAX 5

int queue[MAX];
int front=-1,rear=-1;

void enqueue(int x){
    if((rear+1)%MAX==front){
        printf("Queue Overflow\n");
        return;
    }

    if(front==-1)
        front=0;

    rear=(rear+1)%MAX;
    queue[rear]=x;
}

void dequeue(){
    if(front==-1){
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n",queue[front]);

    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%MAX;
}

void display(){
    int i;

    if(front==-1){
        printf("Queue is empty\n");
        return;
    }

    i=front;

    while(1){
        printf("%d ",queue[i]);

        if(i==rear)
            break;

        i=(i+1)%MAX;
    }

    printf("\n");
}

int main(){
    int choice,x;

    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&choice);

        if(choice==1){
            printf("Enter value: ");
            scanf("%d",&x);
            enqueue(x);
        }
        else if(choice==2)
            dequeue();
        else if(choice==3)
            display();
        else if(choice==4)
            break;
    }

    return 0;
}