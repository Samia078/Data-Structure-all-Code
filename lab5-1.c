#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    system("color 02");

    char array[100], sElement;

    int size,i;

    printf("Enter array Size: ");
    scanf("%d", &size);

    printf("Enter Character Element: ");
    for(i=0; i<size; i++)
    {
        scanf("%s", &array[i]);
    }

    printf("Enter Search Element: ");
    scanf("%s", &sElement);

    //linear Search Algorithm for character array;
    for(i=0; i<size; i++)
    {
        if(sElement==array[i])
        {
            printf("%c is found %d index", sElement, i);
            break;
        }
    }

    if(i == size)
    {
        printf("%c is not found", sElement);
    }

    fflush(stdin);
    getchar();

    main();
}
