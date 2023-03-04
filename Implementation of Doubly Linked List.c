#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *previous, *next;
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
    printf("\n successfully Inserted !!!");
}

void insertAtEnd(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    if(head == NULL)
    {
        newNode -> previous = NULL;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while(temp -> next != NULL)
        temp = temp -> next;
        temp -> next = newNode;
        newNode -> previous = temp;
    }
    printf("\n Insertion success!!!");
}

void deleteBeginning()
{
    if(head == NULL)
    printf(" Empty List!!! Deleting not possible!!!");
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
        printf("\n Deletion success!!!");
    }
}

void display()
{
    if(head == NULL)
    printf("\n Empty List!!!");
    else
    {
        struct Node *temp = head;
        printf("\n List elements are = \n");
        printf(" NULL <--- ");
        while(temp -> next != NULL)
        {
            printf("%d <===> ",temp -> data);
            temp = temp->next;
        }
        printf("%d ---> NULL", temp -> data);
    }
}

int main()
{
    int ch1, ch2, value;
    while(1)
    {
        Start:
        printf("\n  MENU \n");
        printf(" 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n Enter your choice = ");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1:
                printf(" Enter the value for insert = ");
                scanf("%d",&value);
                while(1)
                {
                    printf("\n Select from the following Inserting options\n");
                    printf(" 1. At Beginning\n 2. At End\n 3. Cancel\n Enter your choice = ");
                    scanf("%d",&ch2);
                    switch(ch2)
                    {
                        case 1:
                            insertAtBeginning(value);
                        break;
                        
                        case 2:
                            insertAtEnd(value);
                        break;
                        
                        case 3:
                            goto EndSwitch;
                        
                        default:
                            printf("\n Invalied. Please select the correct option...\n");
                    }
                    goto Start;
                }
            break;
            
            case 2:
                while(1)
                {
                    printf("\n Select from the following Deleting options\n");
                    printf(" 1. At Beginning\n 2. Cancel\n Enter your choice = ");
                    scanf("%d",&ch2);
                    switch(ch2)
                    {
                        case 1:
                            deleteBeginning();
                        break;
                        
                        case 2:
                            goto EndSwitch;
                        
                        default:
                            printf("\n Invalied. Please select the correct option..\n");
                    }
                    goto Start;
                }
            break;
            EndSwitch:
                break;
            
            case 3:
                display();
            break;
            
            case 4:
                exit(0);
            break;
            
            default:
                printf("\n Invalied....");
        }
    }
    return 0;
}
