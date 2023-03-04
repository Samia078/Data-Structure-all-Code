#include<stdio.h>
int  n, a[100], i, j, front=-1, rear=-1;

int enqueue(int val, int n)
{
	if(rear==n-1)
		printf( " Queue is full.\n");
	
	else
	{
//	    if (rear+1==front)
//			printf( "Queue is full.\n");
//		else
//		{
			front=0;
			rear++;
			a[rear]=val;
			printf(" Inserted element is %d\n",a[rear]);
//		}
	}
}

int dequeue()
{
	if(front==-1)
		printf(" No element to delete.\n");
	else
	{
		printf(" Deleted element is %d\n", a[front]);
		front=front+1;
		if(front>rear)
			front=rear=-1;
	}
}

int display()
{
	if(rear==-1)
		printf(" Queue is empty!\n");
	else
	{
		printf(" Elements in the queue: ");
		for(i=front; i<=rear; i++)
		{
			printf("%d ",a[i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int ch, val, n;
	printf(" Enter the array size = ");
	scanf("%d", &n);
	do
	{
		printf("\n Menu");
		printf("\n 1. ENQUEUE \n 2. DEQUEUE \n 3. DISPLAY QUEUE \n 4. Exit ");
		printf("\n Enter your choice =");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				printf(" Enter the value to be inserted=");
				scanf("%d",&val);
				enqueue(val, n);
				break;
			
			case 2:
				dequeue();
				break;
			
			case 3:
				display();
				break;
			
			case 4:
				exit(0);
				break;
			
			default:
				printf(" Invalid...");
				break;
		}
	}
	while(ch<=3);
	return 0;
}
