int ft_strlen(char *str)
{
	int n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

#include <stdio.h>
#include <string.h>
int main()
{
	char *a = "";
	int o = ft_strlen(a);
	int out = strlen(a);
	printf("%d %d\n", o, out);
	return 0;
}
