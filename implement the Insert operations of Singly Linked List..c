#include<stdio.h>

struct Node
{
    int data;
    struct Node*next;
}*head= NULL;

int c=0;

int insertbeg(int value)
{
    struct Node*newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head==NULL)
    {
		c++;
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        newNode->next=NULL;
        head=newNode;
        c++;
    }
    printf("\n Node inserted.");
}

int insertend(int value)
{
    struct Node*newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data= value;
    newNode->next=NULL;
    if(head==NULL)
    {
		c++;
        head=newNode;
    }
    else
    { 
		c++;
        struct Node*temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=newNode;
    }
    printf("\n Node inserted.");
}

int display()
{
    if(head==NULL)
        printf("\n List is empty");
    else
    {
        struct Node*temp=head;
        printf("\n List elements are = ");
        while(temp->next !=NULL)
        {
            printf("%d, ", temp->data);
            temp=temp->next;
        }
        printf("%d, NULL.", temp->data);
    }
}

int insertMid(int data, int pos)
{
    int i;
    struct Node*newNode, *temp;
    
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (pos==1)
    {
    	c++;
	}
    else if(newNode == NULL)
    {
    	printf(" invalid location.");
	}
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        temp = head;
        for(i=2; i<=pos-1; i++)
        {
            temp = temp->next;
            if(temp==NULL)
            break;
        }
        if(temp!=NULL)
        {
            c++;
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
}

int main()
{
	int ch, value, data, pos;
	do
	{
		printf("\n\n 1. Insert to the Beginning\n 2. Insert to the End\n 3. Insert in middle\n 4. Display\n 5. SIZE\n 6. Exit");
		printf("\n Enter your choice = ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				printf(" Enter the value = ");
				scanf("%d", &value);
				insertbeg(value);
			break;
			
			case 2:
				printf(" Enter the value = ");
				scanf("%d", &value);
				insertend(value);
			break;
			
			case 3:
				printf(" Enter middle inserted value = ");
				scanf("%d", &data);
				printf(" Enter middle inserted value's position = ");
				scanf("%d", &pos);
				insertMid( data, pos);
			break;
			
			case 4:
				display();
			break;
			
			case 5:
				printf(" The size of the list is %d", c);
			break;
			
			case 6:
				exit(0);
			break;
			
			default:
				printf(" Invalid....");
		}
	}
	while(ch<=6);
	return 0;
}
