#include<stdio.h>
#include<stdlib.h>

struct node
{
    char val;
    struct node*left;
    struct node*right;
};

struct node*getnode()
{
    return(struct node*)malloc(sizeof(struct node));
};

struct node* top;
int c=0;

struct node* add(struct node*FIRST, int n)
{	
	struct node *T;
	if(c == n)
	{
		printf("\n Stack is Overflow\n");
		return FIRST;
	}
	
    else if(FIRST == NULL)
    {
        FIRST = getnode();
        T = top = FIRST;
        T -> left = NULL;
    }
    
    else
    {
        T = getnode();
        top -> right = T;
        T -> left = top;
        top = T;
    }
    
	printf("\n Enter a value = ");
    c++;
    scanf("\n%c", &T->val);
    T-> right =NULL;
    
    return FIRST;
};

struct node* del(struct node*FIRST)
{
    struct node*T;
    if((FIRST == NULL) && (c<1))
    {
        printf("\n Underflow\n");
        return FIRST;
    }
    T = top;
    printf(" The delete value is = %c\n", T->val);
    if(c!=1)
    {
        top = T -> left;
        T -> left = NULL;
        top -> right = NULL;
    }
    else if(c==1)
    {
        FIRST = NULL;
    }
    c--;
    return FIRST;
};

int display(struct node*T)
{
    if(T==NULL)
    {
        printf("\n Stack IS Empty\n");
        return;
    }
    printf(" NULL --> ");
    while (T!=NULL)
    {
        printf("%c --> ", T->val);
        T = T -> right;
    }
    printf("NULL \n");
}

int search(struct node* T)
{
    char srchelm;
	printf(" Search element = ");
	scanf("\n%c", &srchelm);
	
	while (T != NULL)
	{
		if (T->val == srchelm)
		{
			printf(" Found \n");
			return;	
		}
		T = T->right;
    }
    
	if(T == NULL)
	{
		printf(" Not Founded\n");
		return;
	}
};

int main()
{
    struct node*F;
    int ch, n;
    printf("\n\t\t Menu Operation Of a Linked List stack of Element.\n");
	printf(" \n Enter the size = ");
	scanf("%d", &n);
    F = NULL;
    top = F;
    
    while(1)
    {
        printf("\n  Menu \n");
        printf("\t 1. Insert\n");
        printf("\t 2. Delete\n");
        printf("\t 3. Display\n");
        printf("\t 4. Search\n");
        printf("\t 5. Exit.\n");
        printf(" Enter Your Choice = ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                F=add(F, n);
            break;

            case 2:
                F=del(F);
            break;

            case 3:
                display(F);
            break;

            case 4:
                search(F);
            break;

            case 5:
                exit(1);
            break;

            default:
                printf(" Invalid... Please Enter Right Choice");
            continue;
        }
    }
    return 0;
}
