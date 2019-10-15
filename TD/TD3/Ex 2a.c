#include <stdio.h>

void lireTab(int tab[], int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        printf("Saisir un entier : ");
        scanf("%d", &tab[i]);               // ou scanf("%d", tab + i);
    }
}
