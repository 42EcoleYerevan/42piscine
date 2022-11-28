#include <stdlib.h>

int mystrlen(char *str)
{
	int out;

	out = 0;
	while (str[out])
		out++;
	return (out);
}

int all_len(int size, char **strs, char *sep)
{
	int len;
	int i;

	i = 0;
	while (i < size)
		len += mystrlen(strs[i++]);
	len += mystrlen(sep) * size - 1;
	return (len);
}

char *strappend(char *str1, char *str2)
{
	int i;
	int j;

	i = 0;
	while (str1[i])
		i++;
	j = 0;
	while (str2[j])
		str1[i++] = str2[j++];
	return (str1);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	char *out;
	int len;
	int i;

	len = all_len(size, strs, sep) + 1;
	out = (char *)malloc(len * sizeof(char));
	i = 0;
	while (i < size)
	{
		strappend(out, strs[i]);
		if (i < size - 1)
			strappend(out, sep);
		i++;
	}
	return (out);
}

/*
#include <stdio.h>
int main()
{
	char *strs[] = {"hello", "world", "my", "brother", "bor"};
	char *sep = " privet ";
	char *out = ft_strjoin(5, strs, sep);
	while (*out)
	{
		printf("%c", *out);
		out++;
	}
	return (0);
}
*/
