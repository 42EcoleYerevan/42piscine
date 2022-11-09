#include <unistd.h>
#include <stdio.h>

void ft_putnbr(int nb);

int main() {
    int in;
    scanf("%d", &in);
    ft_putnbr(in);
    return 0;
}

void ft_putnbr(int nb) {
    if (nb == 0)
        return;
    else
        ft_putnbr(nb / 10);

    int out = nb % 10 + 48;
    write(1, &out, 1);
}
