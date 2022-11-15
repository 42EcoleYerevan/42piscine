#include <stdio.h>

char *ft_strcat(char *dest, char *src)
{
	char *tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while (*src)
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	*tmp = '\0';
	return (dest);
}

int main()
{
	char a[12] = "hello";
	char b[12] = "world ";
	char *c;
	c = ft_strcat(b, a);
	printf("%c\n", *c);
	puts(c);
	return 0;
}
