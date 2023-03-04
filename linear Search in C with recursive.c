#include<stdio.h>
int recursivelinearsearch(int a[],int key, int size, int i)
{
	if(i<size)
	{
		if(a[i]==key)
			return i;
		else
			return recursivelinearsearch(a, key, size, i+1);
	}
	return -1;
}

int main()
{
	int a[100], i, size, key, res;
	printf(" Enter The Array Size = ");
	scanf("%d", &size);
	printf(" Enter %d elements in the list = ", size);
	for(i=0; i<size; i++)
	{
		scanf("%d", &a[i]);
	}
	printf(" Enter The Searching Array = ");
	scanf("%d", &key);
	
	res = recursivelinearsearch(a, key, size-1, 0);
	if (res==-1)
		printf("Element %d Not founded", key);
	else
		printf("The Element %d is Founded in Index %d ", key, res);
}


