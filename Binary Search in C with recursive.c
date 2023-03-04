#include<stdio.h>
int binsearch(int a[], int x, int low, int high)
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
	int a[100], i, n, x, res;
	printf(" Enter The Array Size = ");
	scanf("%d", &n);
	printf(" Enter %d elements in the list = ", n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf(" Enter The Searching Array = ");
	scanf("%d", &x);
	
	res = binsearch(a, x, 0, n-1);
	if (res==-1)
		printf("Element %d Not founded", x);
	else
		printf("The Element %d is Founded in Index %d ", x, res);
}
