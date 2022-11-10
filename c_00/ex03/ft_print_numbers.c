#include <unistd.h>

void ft_print_numbers(void);

int main(){
    ft_print_numbers();
    return 0;
}

void ft_print_numbers(void) {
    for (int i = 48; i <= 57; i++) {
        write(1, &i, 1);
    }
}
