#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 5
char stack[size];
int top=0;

int push(char x)
{
    if(top>=size-1)
    {
        printf("\t\tStack is full.\n");
    }

    else
    {
        stack[top]=x;
        top++;
        printf("\t\tInserted eleme1nt.\n");
    }
}

int pop()
{
    int del_element;

    if(top<=0)
    {
        printf("\t\tNo element to delete.\n");
    }

    else
    {
        top--;
        del_element=stack[top];
    }
}

int show()
{
    int i;

    if(top>=1)
    {
        printf("Stack elements: ");

        for(i=0; i<=top; i++)
        {
            printf("%c ",stack[i]);
        }
    }

    else
    {
        printf("\t\tStack is empty.");
    }
}

int main()
{
    int ch;
    char x;

    do
    {
        printf("\n    Menu");
        printf("\n  =======");
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Show");
        printf("\n 4. Exit");
        printf("\n Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                printf("Enter the value to push: ");
                scanf("\n%c",&x);
                push(x);
                break;
            }

            case 2:
            {
                pop();
                break;
            }

            case 3:
            {
                show();
                break;
            }

            case 4:
            {
                exit(0);
                break;
            }

            default:
            {
                printf("Invalid value.\n");
                break;
            }
        }
    }

    while(ch<=4);

    return 0;
}
