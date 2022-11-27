#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./dictionary.c"

int atoi_start_stop(char *str, int start, int end);
void print_str(char ***arr, int numlines, char *str);
void print_three(char ***arr, int numlines, char *str, int start, int stop);
int mystrlen(char *str);
int mystrcmp(char *str1, char *str2);
int intlen(int d);
char *myitoa(int d);

void print_string(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int mystrlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int atoi_start_stop(char *str, int start, int stop)
{
	int out;

	out = 0;
	while (start < stop)
		out = out * 10 + str[start++] - 48;
	return (out);
}

int intlen(int d)
{
	int i;

	i = 0;
	while (d)
	{
		d /= 10;
		i++;
	}
	return (i);
}

char *myitoa(int d)
{
	char *out;
	int len;

	len = intlen(d) + 1;
	out = (char *)malloc(len * sizeof(char));
	out[--len] = '\0';
	while (len > 0)
	{
		out[--len] = d % 10 + 48;
		d /= 10;
	}
	return (out);
}

int mystrcmp(char *str1, char *str2)
{
	while (*str1)
	{
		if (*str1 != *str2)
			return (-1);
		str1++;
		str2++;
	}
	if (*str2 == '\0')
		return (1);
	return (0);
}

void print_str(char ***arr, int numlines, char *str)
{
	int out;
	int i;

	i = 0;
	while (i < numlines)
	{
		if (mystrcmp(str, arr[i][0]) == 1)
		{
			print_string(arr[i][1]);
			write(1, " ", 1);
			return ;
		}
		i++;
	}
}

void print_three(char ***arr, int numlines, char *str, int start, int stop)
{
	int d;

	d = atoi_start_stop(str, start, stop);
	if (d / 100 > 0)
	{
		print_str(arr, numlines, myitoa(d / 100));
		print_str(arr, numlines, "100");
	}
	if (d % 100 < 20)
	{
		print_str(arr, numlines, myitoa(d % 100));
	}
	else
	{
		print_str(arr, numlines, myitoa(d % 100 / 10 * 10));
		print_str(arr, numlines, myitoa(d % 10));
	}
}

int main()
{
	char *filename = "./numbers.dict"; //the name of file
	char ***arr; //3d array like dictionary
	int *lenlines; //number of rows
	int numlines;// number of lines

	//how to use
	numlines = num_lines(filename);
	lenlines = len_lines(filename, numlines);
	arr = get_dict(filename, lenlines, numlines); // filled array

	char *a = "327";
	char *b = "97";
	char *c = "3";

	print_three(arr, numlines, a, 0, 3);
	write(1, "\n", 1);
	print_three(arr, numlines, b, 0, 2);
	write(1, "\n", 1);
	print_three(arr, numlines, c, 0, 1);
	write(1, "\n", 1);
	return (0);
}
