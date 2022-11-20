#include <stdlib.h>

int intlen(char *str);
int *str_to_arr(char *str);
int **init_arr(int size);
int **set_ruls(char *str, int **arr, int size);

int intlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str < 58 && *str > 47)
			i++;
		str++;
	}
	return (i);
}

int **init_arr(int size)
{
	int i;
	int j;
	int **arr;
	
	i = 0;
	size = size + 2;
	arr = (int **)malloc(size * 8);
	while (i < size)
		arr[i++] = (int *)malloc(size * 4);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}

int **set_ruls(char *str, int **arr, int size)
{
	int i;
	int r;
	int *ruls;

	ruls = str_to_arr(str);
	r = 0;
	i = 1;
	while (i <= size)
		arr[0][i++] = ruls[r++];
	i = 1;
	while (i <= size)
		arr[size + 1][i++] = ruls[r++];
	i = 1;
	while (i <= size)
		arr[i++][0] = ruls[r++];
	i = 1;
	while (i <= size)
		arr[i++][size + 1] = ruls[r++];
	return (arr);
}

int *str_to_arr(char *str)
{
	int i;
	int *n;
	int len;

	len = intlen(str);
	n = (int *)malloc(len * 4);
	i = 0;
	while (*str)
	{
		if (*str < 58 && *str > 47)
			n[i++] = *str - 48;
		str++;
	}
	return (n);
}
