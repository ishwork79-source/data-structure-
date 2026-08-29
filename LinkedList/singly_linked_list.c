#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertBeginning()
{
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("%d inserted at the beginning.\n", value);
}

// Insert at end
void insertEnd()
{
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("%d inserted at the end.\n", value);
}

// Insert after a given node
void insertAfter()
{
    int value, afterValue;

    printf("Enter value to insert: ");
    scanf("%d", &value);

    printf("Enter the value after which to insert: ");
    scanf("%d", &afterValue);

    struct Node *temp = head;

    while (temp != NULL && temp->data != afterValue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", afterValue);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("%d inserted after %d.\n", value, afterValue);
}

// Delete first node
void deleteBeginning()
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node *temp = head;

    head = head->next;

    printf("%d deleted from the beginning.\n", temp->data);

    free(temp);
}

// Delete last node
void deleteEnd()
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("%d deleted from the end.\n", head->data);

        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    printf("%d deleted from the end.\n", temp->next->data);

    free(temp->next);
    temp->next = NULL;
}

// Delete node after a given node
void deleteAfter()
{
    int afterValue;

    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Enter the value after which to delete: ");
    scanf("%d", &afterValue);

    struct Node *temp = head;

    while (temp != NULL && temp->data != afterValue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", afterValue);
        return;
    }

    if (temp->next == NULL)
    {
        printf("There is no node after %d.\n", afterValue);
        return;
    }

    struct Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    printf("%d deleted after %d.\n", deleteNode->data, afterValue);

    free(deleteNode);
}

// Display all nodes
void display()
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n===== SINGLY LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Given Node\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Node After Given Node\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertAfter();
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                deleteAfter();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}