#include <stdio.h>
int main ()
{
	int i, j, a[100], n, temp, pos;
	printf(" Enter the array Size = ");
	scanf("%d", &n);
	printf(" Enter %d element in the array list = ", n);
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for(i=0; i<n-1; i++)
	{
		pos=i;
		
		for(j=i+1; j<n; j++)
		{
			if(a[pos] > a[j])
			pos=j;
		}
		if(pos!=i)
		{
			temp = a[i];
			a[i] = a[pos];
			a[pos] = temp;
		}
	}
	printf(" Result = ");
	for (i=0; i<n; i++)
	{
		printf("\n %d", a[i]);
	}
}
