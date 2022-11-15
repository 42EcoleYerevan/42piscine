#include <stdio.h>
#include <string.h>

char *ft_strstr(char *str, char *to_find)
{
	char *tmp;
	int n;

	while (*str)
	{
		n = 0;
		if (*str == to_find[n])
			tmp = str;

		while (*str == to_find[n])
		{
			n++;
			str++;
		}

		if (to_find[n] == '\0')
			break;
		else
			tmp = NULL;

		str++;
	}
	return tmp;
}

int main()
{
	char *a = "hello world";
	char *b = "wor";
	char *c;
	char *d;
	c = strstr(a, b);
	d = ft_strstr(a, b);
	if (d == NULL)
	{
		puts("not");
	}
	else
	{
		puts(c);
		puts(d);
	}
	return 0;
}
