#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

// Enqueue operation
void enqueue()
{
    int value;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        printf("%d inserted into the queue.\n", value);
    }
}

// Dequeue operation
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("%d deleted from the queue.\n", queue[front]);
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

// Display operation
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements are:\n");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== SIMPLE QUEUE =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
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
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}