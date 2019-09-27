#include <stdio.h>

int main(void) {
    int i = 0;

    printf("Saisir un entier : ");
    scanf("%d", &i);

    if (i >= 0) printf("%d", i);
    return 0;
}