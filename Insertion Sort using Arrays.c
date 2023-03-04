#include<stdio.h>
int main()
{
	int a[100], n, i, j, swap;
	printf(" Enter the size of array = ");
	scanf("%d", &n);
	printf(" Enter %d Element in the list = ", n);
	
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	for(i=1; i<n; i++)
	{
		swap = a[i];
		j=i-1;
		while((swap<a[j])&&(j>=0))
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=swap;
	}
	printf(" The Sorted list is = ");
	
	for (i=0; i<n; i++)
		printf("\n %d", a[i]);
	
	return 0;
}

