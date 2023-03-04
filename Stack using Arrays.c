#include<stdio.h>
int stack[50], top=-1;
int push(int val, int n)
{
	if(top>=n-1)
	printf(" Stack is full.\n");
	else
	{
		top++;
		stack[top]=val;
		printf(" Inserted element is = %d\n", stack[top]);
	}
}

void pop()
{
	if(top<=-1)
		printf(" No element to delete. \n");
	else
	{
		printf(" The popped element is = %d\n",stack[top]);
		top--;
	}
}

void show()
{
	int i;
	if(top>=0)
	{
		printf(" Stack Elements are = \n");
		for(i=0; i<=top; i++)
		printf("%d ",stack[i]);
	}
	else
		printf(" Stack is Empty\n");
}

int main()
{
	int n,ch,val;
	printf(" Enter the Array size =");
	scanf("%d", &n);
	do
	{
		printf("\n Menu");
		printf("\n 1. PUSH ");
		printf("\n 2. POP ");
		printf("\n 3. SHOW STACK ");
		printf("\n 4. Exit ");
		printf("\n Enter your choice 1 to 4=");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				printf(" Enter the value to be pushed=");
				scanf("%d",&val);
				push(val, n);
			break;
			
			case 2:
				pop();
			break;
			
			case 3:
				show();
			break;
			
			case 4:
				exit(0);
			break;

			default:
				printf(" Invalid choice!");
			break;
		}
	}
	while (ch<=4);
	return 0;
}
