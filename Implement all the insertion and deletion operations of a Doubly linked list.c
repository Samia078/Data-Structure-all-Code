#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node*prev, *next;
};
struct node*start = NULL;

int traverse()
{
	if (start == NULL)
	{
		printf("\n Linked List is empty.\n");
		return 0;
	}
	struct node*temp;
	temp = start;
	while (temp != NULL)
	{
		printf(" Data = %d\n", temp->info);
		temp = temp->next;
	}
}

int insertbegin ()
{
	int data;
	struct node*temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\n Enter number to be inserted = ");
	scanf("%d", &data);
	temp->info = data;
	temp->prev = NULL;
	temp->next = start;
	start = temp;
}

int insertend()
{
	int data;
	struct node*temp, *trav;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\n Enter number to be inserted = ");
	scanf("%d", &data);
	temp->info = data;
	temp->next = NULL;
	trav = start;
	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		while (trav->next != NULL)
		trav = trav->next;
		temp->prev = trav;
		trav->next = temp;
	}
}

int insertposition()
{
	int data, pos, i=1;
	struct node*temp, *newnode;
	newnode = malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->prev = NULL;
	printf("\n Enter position = ");
	scanf("%d", &pos);
	if (start == NULL)
	{
		start = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	else if (pos == 1)
	{
		insertbegin();
	}
	else
	{
		printf("\n Enter number to be inserted = ");
		scanf("%d", &data);
		newnode->info = data;
		temp = start;
		while (i < pos - 1)
		{
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
		temp->next->prev = newnode;
	}
}

int deletebegin()
{
	struct node*temp;
	if (start == NULL)
	printf("\n Linked List is empty\n");
	else
	{
		temp = start;
		start = start->next;
		if (start = start->next)
			start->prev = NULL;
			free(temp);
	}
}

int deleteend()
{
	struct node*temp;
	if (start == NULL)
	printf("\n Linked List is empty.\n");
	temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	if (start->next == NULL)
		start = NULL;
	else
	{
		temp->prev->next = NULL;
		free(temp);
	}
}

int deleteposition()
{
	int pos, i = 1;
	struct node*temp, *position;
	temp = start;
	if (start == NULL)
		printf("\n Linked List is empty. \n");
	else
	{
		printf("\n Enter position = ");
		scanf("%d",&pos);
		if (pos == 1)
		{
			deletebegin();
			if (start != NULL)
			{
				start->prev = NULL;
			}
			free(position);
			return 0;
		}
		while (i < pos - 1)
		{
			temp = temp->next;
			i++;
		}
		position = temp->next;
		if (position->next != NULL)
		position->next->prev = temp;
		temp->next = position->next;
		free(position);
	}
}

int main()
{
	int choice;
	while (1)
	{
		printf("\n\t1. Display Linked List\n");
		printf("\t2. Insertion At Beginning\n");
		printf("\t3. Insertion At End\n");
		printf("\t4. Insertion At Any Position\n");
		printf("\t5. Deletion From First Position\n");
		printf("\t6. Deletion From Last Position\n");
		printf("\t7. Deletion From Any Position\n");
		printf("\t8. Exit\n");
		printf("\n Enter Choice = ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				traverse();
			break;
			
			case 2:
				insertbegin();
			break;

			case 3:
				insertend();
			break;
			
			case 4:
				insertposition();
			break;
			
			case 5:
				deletebegin();
			break;

			case 6:
				deleteend();
			break;

			case 7:
				deleteposition();
			break;

			case 8:
				exit(1);
			break;
			
			default:
				printf(" Invalid...  Enter correct choice. \n");
			continue;
		}
	}
	return 0;
}
