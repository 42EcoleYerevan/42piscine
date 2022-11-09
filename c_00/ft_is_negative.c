#include <unistd.h>

void ft_is_negative(int n);

int main() {
    ft_is_negative(-2);
    return 0;
}

void ft_is_negative(int n) {
    int P = 80;
    int N = 78;
    if (n >= 0) {
        write(1, &P, 1);
    } else {
        write(1, &N, 1);
    }
}
