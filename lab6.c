#include<stdio.h>
#include<stdlib.h>

struct Node
{   int data;
    struct Node *next;
}*head= NULL;
 int c=0;

void insertbeg(int value)
{
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;


    if(head==NULL)
    {   c++;
        newNode->next=NULL;
        head=newNode;
    }

    else
    {
        newNode->next=NULL;

        head=newNode;
        c++;
    }
    printf("\n one node inserted");

}

void insertend(int value)
{
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data= value;
    newNode->next=NULL;
        if(head==NULL)
            { c++;
                head=newNode;
            }
        else
        {  c++;
            struct Node *temp=head;

            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newNode;
        }
        printf("\nOne node inserted");
}

void display()
{
    if(head==NULL)
        printf("\n\List is empty\n");

    else
    {
        struct Node *temp=head;
        printf("\n List elements are: ");
        while(temp->next !=NULL)
        {
            printf("%d >> ", temp->data);
            temp=temp->next;
        }
        printf("%d >> NULL", temp->data);
    }
}

void insertNodeAtMiddle(int data, int position)
{
   int i;
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (position==1)
    {
        c++;
    }

   else if(newNode == NULL)
    {
        printf("invalid location.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        temp = head;


        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp==NULL)
                break;
        }

        if(temp!=NULL)
        { c++;

            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
}

int main()
{
    printf("\n\t*******MENU*******\n");
    int value, option, data, position;
    do{
    printf("\n\t1:Insert at First Position");
    printf("\n\t2:Insert at End");
    printf("\n\t3:Insert at mid");
    printf("\n\t4:Display");
    printf("\n\t5:SIZE");
    printf("\n\t6:Exit");
    printf("\n\n\tEnter the option ");
    scanf("%d", &option);
    switch(option)
    {
        case 1: printf("Enter the value: ");
                scanf("%d", &value);
                insertbeg(value);
                break;
        case 2: printf("Enter the value: ");
                scanf("%d", &value);
                insertend(value);
                break;
        case 3: printf(" Enter mid value: ");
                scanf("%d", &data);
                printf(" Enter mid inserted value of s position: ");
                scanf("%d", &position);
                insertNodeAtMiddle( data, position);
                break;


        case 4: display();
                break;
        case 5: printf("The size of the list is %d", c);
                break;
        case 6: exit(0);
                break;
                default: printf("Invalid option");
    }

    }while(option<=6);
return 0;
    }
