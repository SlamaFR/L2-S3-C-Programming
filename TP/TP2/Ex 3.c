#include <stdio.h>

int main(void) {
    char c1 = 0, c2 = 0;
    printf("Saisir deux caractères : ");
    scanf(" %c", &c1);
    scanf(" %c", &c2);
    printf("*%c*\n*%c*\n", c1, c2);
    return 0;
}
