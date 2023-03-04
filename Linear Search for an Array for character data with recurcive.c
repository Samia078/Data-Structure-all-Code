// Recursive Linear Search for an array with character data

#include<stdio.h>
int recursivelinearsearch(char a[], char key, int size, int i)
{
	if(i<=size)
	{
		if(a[i]==key)
			return i;
		else
			return recursivelinearsearch(a, key, size, i+1);
	}
	else
		return -1;
}

int main()
{
	int i, size,  res;
	char key, a[100];
	printf(" Enter The Array Size = ");
	scanf("%d", &size);
	printf(" Enter %d elements in the list = ", size);
	for(i=0; i<size; i++)
	{
		scanf("%s", &a[i]);
	}
	printf(" Enter The Searching Array = ");
	scanf("%s", &key);
	
	res = recursivelinearsearch(a, key, size-1, 0);
	if(res==-1)
		printf(" Element %s Not founded", key);
	else
		printf(" The Element %s is Founded in Index %d ", key, res);
}
