#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *last = NULL;

/* Insert at beginning */
void insertBeginning(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    if (last == NULL)
    {
        last = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
    }
}

/* Insert at end */
void insertEnd(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    if (last == NULL)
    {
        last = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }
}

/* Insert after a given node */
void insertAfter(int key, int value)
{
    struct node *temp, *newnode;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    do
    {
        if (temp->data == key)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = value;
            newnode->next = temp->next;
            temp->next = newnode;

            if (temp == last)
                last = newnode;

            return;
        }

        temp = temp->next;

    } while (temp != last->next);

    printf("Node not found\n");
}

/* Delete first node */
void deleteFirst()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    if (last == temp)
    {
        last = NULL;
    }
    else
    {
        last->next = temp->next;
    }

    free(temp);
}

/* Delete last node */
void deleteLast()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    if (temp == last)
    {
        free(last);
        last = NULL;
        return;
    }

    while (temp->next != last)
    {
        temp = temp->next;
    }

    temp->next = last->next;
    free(last);
    last = temp;
}

/* Delete a given node */
void deleteNode(int key)
{
    struct node *temp, *prev;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;
    prev = last;

    do
    {
        if (temp->data == key)
        {
            if (temp == last && temp == last->next)
            {
                last = NULL;
            }
            else
            {
                prev->next = temp->next;

                if (temp == last)
                    last = prev;
            }

            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != last->next);

    printf("Node not found\n");
}

/* Display list */
void display()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;

    } while (temp != last->next);

    printf("(back to first node)\n");
}

/* Main function */
int main()
{
    int choice, value, key;

    while (1)
    {
        printf("\n--- SINGLY CIRCULAR LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Given Node\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Given Node\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter node after which to insert: ");
                scanf("%d", &key);

                printf("Enter value: ");
                scanf("%d", &value);

                insertAfter(key, value);
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                printf("Enter value of node to delete: ");
                scanf("%d", &key);

                deleteNode(key);
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}