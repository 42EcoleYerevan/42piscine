#include <stdio.h>
int calc_top_boxes(int **arr, int size, int col);
int calc_left_boxes(int **arr, int size, int row);
int calc_right_boxes(int **arr, int size, int row);
int calc_bot_boxes(int **arr, int size, int col);
int check(int **arr, int size);

int is_unique(int **arr, size)
{
	int row;
	int col;

	row = 1;
	col = 1;
	while (row <= size)
	{
		while (col <= size)
		{

		}
	}
}

int check(int **arr, int size)
{
	int row;
	int col;

	row = 1;
	col = 1;
	while (row <= size)
	{
		while (col <= size)
		{
			if (arr[0][col] != calc_top_boxes(arr, size, col))
			{
				printf("top %d %d\n", row, col);
				return (0);
			}
			if (arr[size + 1][col] != calc_bot_boxes(arr, size, col))
			{
				printf("bot %d %d\n", row, col);
				return (0);
			}
			if (arr[row][0] != calc_left_boxes(arr, size, row))
			{
				printf("left %d %d\n", row, col);
				return (0);
			}
			if (arr[row][size + 1] != calc_right_boxes(arr, size, row))
			{
				printf("right %d %d\n", row, col);
				return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

int calc_top_boxes(int **arr, int size, int col)
{
	int n;
	int i;
	int v;

	n = 1;
	i = 2;
	v = arr[1][col];
	while (i <= size)
	{
		if (arr[i][col] > v)
		{
			n++;
			v = arr[i][col];
		}
		i++;
	}
	return (n);
}

int calc_bot_boxes(int **arr, int size, int col)
{
	int n;
	int i;
	int v;

	n = 1;
	i = size - 1;
	v = arr[size][col];
	while (i >= 1)
	{
		if (arr[i][col] > v)
		{
			v = arr[i][col];
			n++;
		}
		i--;
	}
	return (n);
}

int calc_left_boxes(int **arr, int size, int row)
{
	int n;
	int i;
	int v;

	n = 1;
	i = 2;
	v = arr[row][1];
	while (i <= size)
	{
		if (arr[row][i] > v)
		{
			v = arr[row][i];
			n++;
		}
		i++;
	}
	return (n);
}

int calc_right_boxes(int **arr, int size, int row)
{
	int n;
	int i;
	int v;

	n = 1;
	i = size - 1;
	v = arr[row][size];
	while (i >= 1)
	{
		if (arr[row][i] > v)
		{
			n++;
			v = arr[row][i];
		}
		i--;
	}
	return (n);
}
