#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int *arr;
	if (start > end)
	{
		arr = malloc(4);
		arr[0] = 0;
		return arr;
	}
	int n = end - start + 1;

	arr = malloc(4 * n);
	int i = 0;
	while (i < n)
	{
		arr[i] = end - i;
		i++;
	}
	return arr;
}

int main(void)
{
	int *arr = ft_range(-3,-1);
	// printf("%d", arr[0]);
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n",arr[i]);
	}
	
	return 0;
}