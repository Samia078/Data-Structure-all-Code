#include<stdio.h>

int n, a[50], i, j, front=-1, rear=-1;
int enqueue(int x, int n)
{
    if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		a[rear]=x;
	}
    else if(((rear+1)%n)==front)
    {
        printf("\n Queue is Overflow.\n");
    }
    else
    {
        rear=(rear+1)%n;
        a[rear]=x;
    }
}

int dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("\n Queue is Underflow.\n");
    }
    else if(front==rear)
    {
            printf("\n The dequeue value is %d ", a[front]);
            front=-1;
            rear=-1;
    }
    else
    {
        printf("\n The dequeue value is %d ", a[front]);
        front=(front+1)%n;
    }
}

void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
    	printf("\n Queue is empty.\n");
    }
    else
    {
        printf(" Element in a queue are = ");
        while(i!=rear)
        {
            printf("%d ",a[i]);
            i=(i+1)%n;
    	}
    	printf("%d",a[rear]);
    }
}

int main()
{
    int ch, x;
    printf("\n Enter the size of Queue = ");
	scanf("%d",&n);
    do
    {
        printf("\n Menu");
        printf("\n 1. ENQUEUE \n 2. DEQUEUE \n 3. DISPLAY QUEUE \n 4. Exit");
        printf("\n Enter your choice =");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("\n Enter the value = ");
                scanf("%d",&x);
                enqueue(x, n);
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
                printf("\n Invalid...");
            break;
        }
    }
    while (ch<=4);
    return 0;
 }
