int ft_atoi(char *str)
{
	int out;
	int s;

	out = 0;
	s = 1;
	while (*str == 32)
		str++;
	while (*str == 43 || *str == 45)
	{
		if (*str == 45)
			s *= -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		out = out * 10 + *str - 48;
		str++;
	}
	return (out * s);
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *a = " --++--+1234321ab567";
	int o = ft_atoi(a);
	printf("%d\n", o);
	return (0);
}
