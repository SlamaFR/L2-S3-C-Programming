#include <stdio.h>

int main(void) {
    char c;
    for (c = 'A'; c <= 'Z'; c++) {
        printf("caractere %c code %d\n", c, c);
    }
    for (c = '0'; c <= '9'; c++) {
        printf("caractere %c code %d\n", c, c);
    }
    return 0;
}
