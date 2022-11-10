#include <unistd.h>

void ft_print_comb2(void);
void combine(char f1, char f2, char s1, char s2);
void print_numbers(char f1, char f2, char s1, char s2);

void ft_print_comb2(void)
{
	char f1;
	char f2;
	char s1;
	char s2;

	f1 = '0';
	f2 = '0';
	s1 = '0';
	s2 = '0';
	combine(f1, f2, s1, s2);
}

void print_numbers(char f1, char f2, char s1, char s2) 
{
	write(1, &f1, 1);
	write(1, &f2, 1);
	write(1, " ", 1);
	write(1, &s1, 1);
	write(1, &s2, 1);
	write(1, ", ", 2);
}

void combine(char f1, char f2, char s1, char s2)
{
	while (f1 <= '9')
	{
		f2 = '0';
		while (f2 <= '8')
		{
			s1 = f1;
			while (s1 <= '9')
			{
				s2 = f2 + 1;
				while (s2 <= '9')
				{
					print_numbers(f1, f2, s1, s2);
					s2++;
				}
				s1++;
			}
			f2++;
		}
		f1++;
	}
}
