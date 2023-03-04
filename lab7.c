#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Nod *previous, *next;
}*head = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> previous = NULL;
    newNode -> next = NULL;
    if(head == NULL)
    {
        newNode -> next = NULL;
        head = newNode;
    }
    else
    {
        newNode -> next = head;
        head = newNode;
    }
    printf("\nInsertion Success!!!");
}

void insertAtEnd(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    if(head == NULL)
    {
        newNode-> previous = NULL;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while(temp -> next !=NULL)
            temp = temp ->next;
        temp -> next = newNode;
        newNode -> previous = temp;
    }
    printf("\nInsertion Sucess!!!");
}

void deleteBeginning()
{
    if(head == NULL)
        printf("*List is Empty !!! Deletion not possible!!!");

    else
    {
        struct Node *temp = head;
        if(temp -> previous == temp -> next)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            head = temp -> next;
            head -> previous = NULL;
            free(temp);
        }
        printf("\nDeletion Success!!!");
    }
}

void display()
{
    if(head == NULL)
        printf("\nList is Empty!!!");
    else
    {
        struct Node *temp = head;
        printf("\nList elements are: \n");
        printf("NULL <--- ");
        while(temp -> next != NULL)
        {
            printf("%d <===>", temp -> data);
            temp = temp->next;
        }
        printf("%d ---> NULL", temp -> data);
    }
}

int main()
{
    int choice1, choice2, value;
    while(1)
    {

        Start:
            printf("\n********** MENU ***********");
            printf("\n  1. Insert \n  2. Delete\n  3. Display\n  4. Exit\n Enter your choice: ");
            scanf("%d", &choice1);
            switch(choice1)
            {
                case 1: printf("Enter the value to be inserted: ");
                    scanf("%d", &value);
                    while(1)
                    {
                        printf("\nSelect from the following Inserting options\n");
                        printf("1. At Beginning\n2. At End\n3. Cancel\nEnter Your Choice: ");
                        scanf("%d", &choice2);

                        switch(choice2)
                        {
                            case 1: insertAtBeginning(value);
                                break;
                            case 2: insertAtEnd(value);
                                break;
                            case 3:
                                goto EndSwitch;
                            default:
                                printf("\nPlease select correct Insertion option!!!\n");
                        }
                        goto Start;
                    }
                    break;
                case 2:
                    while(1)
                    {
                        printf("\nSelect from the following Deletion options\n");
                        printf("1. At Beginning\n2. Cancel\nEnter your choice: ");
                        scanf("%d", &choice2);

                        switch(choice2)
                        {
                            case 1: deleteBeginning();
                                break;
                            case 2:
                                goto EndSwitch;
                            default:
                                printf("\nPlease select correct Deletion option!!!\n");
                        }
                        goto Start;
                        }
                        break;
                        EndSwitch:
                            break;
                        case 3: display();
                            break;
                        case 4: exit(0);
                            break;
                        default:
                            printf("\nPlease select correct option!!!");
            }
    }
    return 0;
}

