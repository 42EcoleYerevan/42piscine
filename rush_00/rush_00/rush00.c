#include <unistd.h>
#include "./ft_putchar.c"

void	rush(int a, int b)
{
	int	x;
	int	y;

	y = 0;
	while (y < b)
	{
		x = 0;
		while (x < a)
		{
			ft_putchar(x, y, a, b);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
