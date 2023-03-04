#include <stdio.h>
int main()
{
	int A[100], n, j, i, temp;
	printf(" Enter the array size of the list = ");
	scanf("%d", &n);
	printf("\n Enter %d integers in the list = ", n);

	for (j=0; j<n; j++)
	{
		scanf("%d", &A[j]);
	}

	for (j=0; j<n-1; j++)
	{
		for (i=0; i<n-j-1; i++)
		{
			if (A[i] > A[i+1])
			{
				temp = A[i];
				A[i] = A[i+1];
				A[i+1] = temp;
			}
		}
	}

	 	
	printf(" The Sorted list is = ");
	
	for (j=0; j<n; j++)
		printf("\n %d", A[j]);
	
	return 0;
}
