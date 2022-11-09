#include <unistd.h>

void ft_print_comb(void);

int main() {
    ft_print_comb();
    return 0;
}

void ft_print_comb(void) {
    int space = 32;
    for (int first = 48; first <= 55; first++) {
        for (int sethirdond = first + 1; sethirdond <= 56; sethirdond++) {
            for (int third = sethirdond + 1; third <= 57; third++) {
                write(1, &first, 1);
                write(1, &sethirdond, 1);
                write(1, &third, 1);
                write(1, &space, 1);
            }
        }
    }
}
