#include<stdio.h>

int binsearch(char a[], char x, int low, int high)
{
	if (high>=low)
	{
		int mid=low+((high-low)/2);
		
		if (a[mid]==x)
			return mid;
			
		if (a[mid]>x)
			return binsearch(a, x, low, mid-1);
			
		else
			return binsearch(a, x, mid+1, high);
	}
	return -1;
}

int main()
{
	int x, i, n, res;
	char a[100];
	printf(" Enter The Array Size = ");
	scanf("%d", &n);
	printf("\n Enter %d elements in the list = ", n);
	for(i=0; i<n; i++)
	{
		scanf("%s", &a[i]);
	}
	printf("\n Enter The Searching Array = ");
	scanf("%s", &x);
	
	res = binsearch(a, x, 0, n-1);
	if (res==-1)
		printf("\n Element %c Not founded", x);
	else
		printf("\n The Element %c is Founded in Index %d ", x, res);
}

