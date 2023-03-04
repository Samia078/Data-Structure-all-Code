#include <stdio.h>
int main()
{
	int i,n,low,high,mid;
	char a[100][100],key[100];
	printf(" Enter the Array Size = ");
	scanf("%d", &n);
	printf(" Enter Data in the list = ");
	for(i=0; i<=n-1; i++)
		scanf("%s", &a[i]);
	printf(" Enter the search Data = ");
	scanf("%s", &key);
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if (strcmp(key,a[mid])==0)
		{
			printf(" key found at the position %d\n", mid+1);
			exit(0);
		}
		else if(strcmp(key,a[mid])>0)
		{
			high=high;
			low=mid+1;
		}
		else
		{
			low=low;
			high=mid-1;
		}
	}
	printf(" Data not found\n");
 }
