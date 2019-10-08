#include <stdio.h>

void scanPositif(int *val) {
    do {
        printf("Saisir un entier positif : ");
        scanf("%d", val);
    } while (*val < 0);
}
