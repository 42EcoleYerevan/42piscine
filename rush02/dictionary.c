#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int len_file(const char *filename);
int num_lines(char *filename);
int len_ints(char *str);
int len_chars(char *str);
int *len_lines(char *filename, int numlines);
char *get_int_from_str(char *str);
char *get_char_from_str(char *str);
char ***get_3d_arr(int numlines);
char ***get_dict(char *filename, int *lenlines, int numlines);

int len_file(const char *filename)
{
	int i;
	int file;
	char ch[1];

	i = 0;
   	file = open(filename, O_RDONLY);
	if (file < 0)
		return (-1);
	while (read(file, ch, 1))
		i++;
	return (i);
}

int num_lines(char *filename)
{
	char ch[1];
	int i;
	int file;

	i = 0;
	file = open(filename, O_RDONLY);
	if (file < 0)
		return (-1);
	while (read(file, ch, 1))
	{
		if (*ch == '\n')
			i++;
	}
	close(file);
	return (i);
}

int *len_lines(char *filename, int numlines)
{
	char ch[1];
	int *arr;
	int file;
	int len;
	int i;

	i = 0;
	len = 0;
	arr = (int *)malloc(numlines * sizeof(int));
	file = open(filename, O_RDONLY);
	if (file < 0)
		return (NULL);
	while (read(file, ch, 1))
	{
		len++;
		if (*ch == '\n')
		{
			arr[i] = len;
			i++;
			len = 0;
		}
	}
	close(file);
	return (arr);
}

int len_ints(char *str)
{
	int i;

	i = 0;
	while (*str > 57 || *str < 48)
		str++;
	while (*str < 58 && *str > 47)
	{
		i++;
		str++;
	}
	return (i);
}

int len_chars(char *str)
{
	int i;

	i = 0;
	while (*str < 65 || (*str > 90 && *str < 97) || *str > 122)
		str++;
	while ((*str > 64 && *str < 91) || (*str > 96 && *str < 123))
	{
		i++;
		str++;
	}
	return (i);
}

char *get_int_from_str(char *str)
{
	char *d;
	int len;
	int i;

	i = 0;
	len = len_ints(str) + 1;
	d = (char *)malloc(len * sizeof(char));
	while (*str > 57 || *str < 48)
		str++;
	while (*str < 58 && *str > 47)
	{
		d[i++] = *str;
		str++;
	}
	d[i] = '\0';
	return (d);
}

char *get_char_from_str(char *str)
{
	int i;
	int len;
	char *s;

	i = 0;
	len = len_chars(str);
	s = (char *)malloc(len * sizeof(char));
	while (*str < 65 || (*str > 90 && *str < 97) || *str > 122)
		str++;
	while ((*str > 64 && *str < 91) || (*str > 96 && *str < 123))
	{
		s[i++] = *str;
		str++;
	}
	s[i] = '\0';
	return (s);
}

char ***get_3d_arr(int numlines)
{
	char ***arr;
	int i;

	arr = (char ***)malloc(numlines * sizeof(char **));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < numlines)
	{
		arr[i] = (char **)malloc(2 * sizeof(char *));
		if (arr[i] == NULL)
			return (NULL);
		i++;
	}
	return (arr);
}

char ***get_dict(char *filename, int *lenlines, int numlines)
{
	char ***arr;
	char str[200];
	int file;
	int i;

	i = 0;
	arr = get_3d_arr(numlines);
	file = open(filename, O_RDONLY);
	while (i < numlines)
	{
		read(file, str, lenlines[i]);
		arr[i][0] = get_int_from_str(str);
		arr[i][1] = get_char_from_str(str);
		i++;
	}
	return (arr);
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

	int i;
	i = 0;
	while (i < numlines)
	{
		printf("%s %s | chars %d\n", arr[i][0], arr[i][1], lenlines[i]);
		i++;
	}
	return 0;
}
