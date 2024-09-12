#include <stdio.h>
#include <stdlib.h>
int ft_abs(int n)
{
	return (n < 0) ? -n : n;
}
int     *ft_range(int start, int end)
{
	int *arr = malloc(4 *ft_abs(end - start) + 1);
	int i = 0;
	while (i < ft_abs(end - start) + 1)
	{
		if (start > end)
			arr[i] = start - i;
		else
			arr[i] = start + i;
		i++;
	}
	return arr;
}

int main(void)
{
	int *arr = ft_range(0,-3);
	// printf("%d", arr[0]);
	for (int i = 0; i < 4; i++)
	{
		printf("%d\n",arr[i]);
	}
	
	return 0;
}