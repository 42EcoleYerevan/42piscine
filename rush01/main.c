#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int *str_to_arr(char *str);
int **init_arr(int size);
int **set_ruls(char *str, int **arr, int size);
int intlen(char *str);

int calc_top_boxes(int **arr, int size, int col);
int calc_left_boxes(int **arr, int size, int row);
int calc_right_boxes(int **arr, int size, int row);
int calc_bot_boxes(int **arr, int size, int col);
/* int check(int **arr, int size, int row, int col); */
int check(int **arr, int size);

int main(int argc, char **argv)
{
	int **arr;
	int size;

	if (argc == 2)
	{
		size = intlen(argv[1]) / 4;
		arr = init_arr(size);
		arr = set_ruls(argv[1], arr, size);
		arr[1][1] = 1;
		arr[1][2] = 2;
		arr[1][3] = 3;
		arr[1][4] = 4;
		arr[2][1] = 2;
		arr[2][2] = 3;
		arr[2][3] = 4;
		arr[2][4] = 1;
		arr[3][1] = 3;
		arr[3][2] = 4;
		arr[3][3] = 1;
		arr[3][4] = 2;
		arr[4][1] = 4;
		arr[4][2] = 1;
		arr[4][3] = 3;
		arr[4][4] = 2;
		printf("%d\n", check(arr, size));
		for (int i = 0; i < size + 2; i++)
		{
			for (int j = 0; j < size + 2; j++)
			{
				if (i == 0 || i == size + 1)
				{
					if (j == 0 || j == size + 1)
						printf("  ");
					else
						printf("%d ", arr[i][j]);
				}
				else
					printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
	return (0);
}
