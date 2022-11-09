#include <unistd.h>

void ft_print_alphabet(void);

int main() {
    ft_print_alphabet();
    return 0;
}

void ft_print_alphabet(void) {
    for (int i = 97; i <= 122; i++) {
        write(1, &i, 1);
    }
}

