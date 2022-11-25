#include <stdlib.h>

int *ft_range(int min, int max)
{
	int i;
	int *arr;

	if (min >= max)
		return (arr);
	i = 0;
	arr = (int *)malloc(max - min);
	if (arr == NULL)
		return (arr);
	while (min < max)
		arr[i++] = min++;
	return (arr);
}

/*
#include <stdio.h>
int main()
{
	int *a;
	a = ft_range(5, 10);
	for (int i = 0; i < 5; i++)
		printf("%d ", a[i]);
	return (0);
}
*/
