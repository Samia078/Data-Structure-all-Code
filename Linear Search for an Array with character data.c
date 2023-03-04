#include<stdio.h>
int main()
{
    int n, i;
    char a[50], x;

    printf(" Enter the array size = ");
    scanf("%d",&n);

    printf(" Enter %d Element in the list = ", n);
    for(i=0; i<n; i++)
        scanf("%s",&a[i]);

    printf(" Enter the searching element = ");
    scanf("%s",&x);

    for(i=0; i<n; i++)
    {
        if(a[i]==x)
        {
            printf("\n Element %s Found at Index %d", x, i);
            break;
        }
    }
    if(i==x)
    {
        printf("\n Element %s not Found in this array",x);
    }

    return 0;
}
