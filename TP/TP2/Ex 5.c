#include <stdio.h>

void addTen(int *n) {
    printf("V: Valeur : %d - Adresse %p\n", *n, n);
    *n += 10;
    printf("V: Valeur : %d - Adresse %p\n", *n, n);
}

void swap(int *n, int *p) {
    printf("V: 1 - Valeur : %d - Adresse %p\n", *n, n);
    printf("V: 2 - Valeur : %d - Adresse %p\n", *p, p);
    int buffer = *n;
    *n = *p;
    *p = buffer;
    printf("V: 1 - Valeur : %d - Adresse %p\n", *n, n);
    printf("V: 2 - Valeur : %d - Adresse %p\n", *p, p);
}

int main(void) {
    int n = 0, p = 0;

    printf("Saisir un entier : ");
    scanf("%d", &n);

    printf("M: Valeur : %d - Adresse %p\n", n, &n);
    addTen(&n);
    printf("M: Valeur : %d - Adresse %p\n", n, &n);

    printf("Saisir deux entiers : ");
    scanf("%d %d", &n, &p);

    printf("M: 1 - Valeur : %d - Adresse %p\n", n, &n);
    printf("M: 2 - Valeur : %d - Adresse %p\n", p, &p);
    swap(&n, &p);
    printf("M: 1 - Valeur : %d - Adresse %p\n", n, &n);
    printf("M: 2 - Valeur : %d - Adresse %p\n", p, &p);
    return 0;
}
