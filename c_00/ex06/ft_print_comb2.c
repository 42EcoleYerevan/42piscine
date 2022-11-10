#include <unistd.h>

void ft_print_comb2(void);

int main() {
    ft_print_comb2();
    return 0;
}

void ft_print_comb2(void) {
    int space = 32;
    int comma = 44;
    for (int f1 = 48; f1 <= 57; f1++) {
        for (int f2 = 48; f2 <= 56; f2++) {
            for (int s1 = f1; s1 <= 57; s1++) {
                for (int s2 = f2 + 1; s2 <= 57; s2++) {
                    write(1, &f1, 1);
                    write(1, &f2, 1);
                    write(1, &space, 1);
                    write(1, &s1, 1);
                    write(1, &s2, 1);
                    write(1, &comma, 1);
                    write(1, &space, 1);
                }
            }
        }
    }
}
