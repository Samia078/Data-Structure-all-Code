#include<stdio.h>
#include<stdlib.h>

struct node
{

    char data;
    struct node *next;
    struct node *pre;

}* head=NULL;

int top=0;



void push(char value, int size)
{
    if(top>=size)
    {
        printf("Overflow");
        return;
    }
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->pre=NULL;

    if(head==NULL)
    {
        head=newnode;
        top++;
        return;
    }

    struct node *temp=head;
    while(temp->next!=NULL)
          temp=temp->next;

    temp->next=newnode;
    newnode->pre=temp;
    top++;
}
void search(char value)
{
    if(head==NULL)
    {
        printf("Stack is Empty.");
        return;
    }
    struct node *temp=head;
    int f=-1;
    while(temp!=NULL)
    {
        if(temp->data==value)
        {
            printf("found.");
            f=0;
            break;
        }
        temp=temp->next;
    }
    if(f==-1)
    {
        printf("not found.");
    }
}
void pop()
{
    if(head==NULL)
    {
        printf("Underflow.");
        return;
    }
    if(head->next==NULL)
    {
        head=NULL;
        top--;
        return;
    }
    struct node *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    top--;
}
void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("No element to display.");
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }


    while(temp!=NULL)
    {
        printf(" %c--",temp->data);


        temp=temp->pre;
    }

}


int main()
{
    int choise, size;
    char value;
    printf("\n\tEnter Size= ");
    scanf("%d", &size);
    do
    {
    Menu:
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Search");
        printf("\n4.Display");
        printf("\n5.Size");
        printf("\n6.Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choise);
        switch(choise)
        {
        case 1:

            printf("\nEnter inserted value: ");
            scanf("\n%c", &value);
            push(value,size);
            break;

        case 2:

            pop();
            break;

        case 3:

            printf("Enter search element: ");
            scanf("\n%c", &value);
            search(value);
            break;

        case 4:

            display();
            break;

        case 5:

            printf(" stack size is %d", top );
            break;

        case 6:

            return 0;
            break;

        default:

            printf(" Enter valid choice.");
            goto Menu;

        }
    } while(choise<=6);
}
