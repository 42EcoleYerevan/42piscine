#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	int n;
	char *tmp;

	n = 0;
	tmp = dest;
	while (*tmp)
		tmp++;
	while (src[n] && n < nb)
	{
		*tmp = src[n];
		tmp++;
		n++;
	}
	*tmp = '\0';
	return (dest);
}

int main()
{
	char a[12] = "hello";
	char b[12] = "world ";
	char *c;
	c = ft_strncat(b, a, 3);
	printf("%c\n", *c);
	puts(c);
	return 0;
	return 0;
}
