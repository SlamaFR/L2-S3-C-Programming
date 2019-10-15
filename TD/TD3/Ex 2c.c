#include <stdio.h>

void affiche(int tab[], int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
        if (i % 10 == 9) printf("\n");
    }
}
