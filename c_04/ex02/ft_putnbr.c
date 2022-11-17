#include <unistd.h>

void ft_putnbr(int nb)
{
	int out;

	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb < 1)
		return ;
	ft_putnbr(nb / 10);
	out = nb % 10 + 48;
	write(1, &out, 1);
}

int main()
{
	ft_putnbr(-2147483647);
	return 0;
}
