#include <stdio.h>

int div(int n, int p, int *quotient, int *rest) {
    if (p == 0) {
        printf("Erreur : Le dénominateur est nul !\n");
        return 0;
    } else {
        *quotient = n / p;
        *rest = n % p;
        return 1;
    }
}

int main(void) {
    int i, n = 0, p = 0, quotient = 0, rest = 0;
    for (i = 0; i < 5; i++) {
        printf("Saisir le numérateur et le dénominateur : ");
        scanf("%d %d", &n, &p);
        if (div(n, p, &quotient, &rest)) {
            if (quotient != 0) {
                if (rest != 0) printf("Quotient : %d - Reste : %d\n", quotient, rest);
                else printf("Quotient : %d\n", quotient);
            } else
                printf("Reste : %d\n", rest);
        }
    }
    return 0;
}