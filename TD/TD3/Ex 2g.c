#include <stdio.h>

void miroirTranche(int tab[], int min, int max) {
    int i, tmp;
    for (i = min; i < (min + max) / 2; i++) {
        tmp = tab[i];
        tab[i] = tab[max + min - i - 1];
        tab[max + min - i - 1] = tmp;
    }
}

void decaleD(int t[], int taille) {
    int tmp = t[taille - 1], i;
    for (i = taille - 1; i > 0; i--)
        t[i] = t[i - 1];
    t[0] = tmp;
}

void decalekD(int t[], int taille, unsigned int k) {
    int i;
    for (i = 0; i < k; i++)
        decaleD(t, taille);
}

void decalekD2(int t[], int taille, unsigned int k) {
    miroirTranche(t, 0, taille - k);
    miroirTranche(t, taille - k, taille);
    miroirTranche(t, 0, taille);
}