#include <stdio.h>

struct node
{
	int num;
	struct node *nextptr;
}*stnode,*ennode;

int CreationList(int n)
{
	int i,num;
	struct node *preptr, *newnode;
	if(n>=1)
	{
		stnode=(struct node*)malloc(sizeof(struct node));
		printf("\n Input index for Node 1 : ");
		scanf("%d",&num);
		stnode->num=num;
		stnode->nextptr=NULL;
		preptr=stnode;
		for(i=2; i<=n; i++)
		{
			newnode = (struct node*)malloc(sizeof(struct node));
			printf(" Input Index for node %d = ",i);
			scanf("%d",&num);
			newnode->num=num;
			newnode->nextptr=NULL;
			preptr->nextptr=newnode;
			preptr=newnode;
		}
		preptr->nextptr=stnode;
	}
}

int FindElement(int FindElem, int j)
{
	int ctr=0;
	ennode=stnode;
	while(ennode->nextptr!=NULL)
	{
		if(ennode->num==FindElem)
		break;
		else
	    	ctr++;
		    ennode=ennode->nextptr;
		if (ctr==j+1)
		break;
	}
	return ctr;
}

int displayClList()
{
	struct node *temp;
	int n=1;
	if(stnode==NULL)
	{
	printf(" No found Index linear search in the Link List .");
	}
	else
	{
		temp=stnode;
		printf("\n\n Index are entered in the list.\n");
		do
		{
			printf(" Index %d = %d\n",n-1,temp->num);
			temp=temp->nextptr;
			n++;
		}
		while(temp != stnode);
	}
}

int main()
{
	int n,count;
	int i,FindElem,FindPlc;
	stnode = NULL;
	ennode = NULL;
	printf("\n Enter the Number of Nodes = ");
	scanf("%d",&n);
	count=n;
	CreationList(n);
	displayClList();
	printf(" Enter the finding element of Linear Search link List = ");
	scanf("%d", &FindElem);
	FindPlc=FindElement(FindElem,count);
	
	if(FindPlc<n)
	printf(" Element found is %d index at node. \n\n", FindPlc);

	else
	printf(" This element not found in linked list.\n\n");
	return 0;
}

