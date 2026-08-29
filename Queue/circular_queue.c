#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Enqueue operation
void enqueue()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("Circular Queue Overflow!\n");
    }
    else
    {
        printf("Enter the value to enqueue: ");
        scanf("%d", &value);

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        queue[rear] = value;

        printf("%d inserted into the circular queue.\n", value);
    }
}

// Dequeue operation
void dequeue()
{
    if (front == -1)
    {
        printf("Circular Queue Underflow!\n");
    }
    else
    {
        printf("%d deleted from the circular queue.\n", queue[front]);

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

// Display operation
void display()
{
    int i;

    if (front == -1)
    {
        printf("Circular Queue is empty.\n");
    }
    else
    {
        printf("Circular Queue elements are:\n");

        i = front;

        while (1)
        {
            printf("%d ", queue[i]);

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % MAX;
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== CIRCULAR QUEUE =====\n");
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