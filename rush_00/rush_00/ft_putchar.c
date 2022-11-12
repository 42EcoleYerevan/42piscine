#include <unistd.h>

void	ft_putchar(int x, int y, int a, int b)
{
	if (y == 0 || y == b - 1)
	{
		if (x == 0 || x == a - 1)
			write(1, "o", 1);
		else
			write(1, "-", 1);
	}
	else
	{
		if (x == 0 || x == a - 1)
			write(1, "|", 1);
		else
			write(1, " ", 1);
	}
}
