
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *previous,*next;
}*head=NULL;
void insertBeg(int value)
{
    struct Node *newnode;
    newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    printf("\nOne node is inserted!!\n");
}
void insertEnd(int value)
{
    struct Node*newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
    {
        newnode->previous=NULL;
        head=newnode;
    }
    else
    {
        struct Node*temp=head;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->previous=temp;
    }
    printf("\nOne node is inserted!!\n");
}
void insertSpcloc(int value)
{

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    int i, location;
    if(newnode == NULL)
    {
        printf("\nUnable to allocate memory.");
    }
    else
    {
        printf("\nEnter the location\n");
        scanf("%d",&location);
        temp=head;
        for(i=0; i<=location; i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\nCan't insert\n");
                return;
            }
        }
        newnode->data = value;
        newnode->next = temp->next;
        newnode -> previous = temp;
        temp->next = newnode;
        temp->next->previous=newnode;
        printf("\n One node is inserted!!!\n");
    }
}
void dltBeg()
{
    if(head == NULL)
    {
        printf("\nList is empty!! Deletion is not possible!!");
    }
    else
    {
        struct Node*temp=head;
        if(temp->previous==temp->next)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            head=temp->next;
            head->previous=NULL;
            free(temp);
        }
        printf("\n Deletion Success!!!");
    }
}
void dltEnd()
{
    if(head-> next == NULL)
    {
        printf("\nList is empty!! Deletion is not possible!!");
        free(head);
        head = NULL;
    }
    struct Node *newnode = head,*previous_node;
    while(newnode -> next != NULL)
    {
        previous_node = newnode;
        newnode = newnode -> next;
    }
    free(newnode);
    printf("\n Deletion Success!!!");
    previous_node -> next = NULL;
}
void dltSpcloc()
{
    int pos, i = 1;
    struct Node *temp, *position;
    temp = head;
    if (head == NULL)
        printf("\nList is empty.Deletion is not possible!!");
    else
    {
        printf("\nEnter position : ");
        scanf("%d",&pos);
        if (pos == 1)
        {
            dltBeg();
            if (head != NULL)
            {
                head->previous = NULL;
            }
            free(position);
            return;
        }
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        position = temp->next;
        if (position->next != NULL)
            position->next->previous = temp;
        temp->next = position->next;
        free(position);
        printf("\n Deletion Success!!!");
    }
}
int getCount(struct Node* head)
{
    int count = 0;
    struct Node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
void display()
{
    if(head== NULL)
    {
        printf("\n List is Empty\n");
    }
    else
    {
        struct Node *temp=head;
        printf("\n\n List element are : \n");
        printf("\nNULL<-----");
        while (temp->next != NULL)
        {
            printf("%d<=====>",temp->data);
            temp=temp->next;
        }
        printf("%d----->NULL",temp->data);
        printf("\nTotal Nodes in the link list is : %d", getCount(head));
    }
}
int main()
{
    int choice,value,choice1,location;
    while(1)
    {
mainMenu:

        printf("\n**************Menu**************\n1.Insert\n2.Delete\n3.Display.\n4.Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter the value to be insert:  ");
            scanf("%d",&value);
            while(1)
            {
                printf("where you want to insert: \n1.At Beginning\n2.At End\n3.At Specific position\n*Enter your choice: ");
                scanf("%d",&choice1);
                switch(choice1)
                {
                case 1:
                    insertBeg(value);
                    break;
                case 2:
                    insertEnd(value);
                    break;
                case 3:
                    insertSpcloc(value);
                    break;
                default :
                    printf("\nWrong input");
                }
            }
        }
    }
}
