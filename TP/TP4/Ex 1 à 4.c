#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initAlea(int t[], int taille, int max) {
    int i;
    for (i = 0; i < taille; i++)
        t[i] = random() % max;
}

int position(int tab[], int taille, int n) {
    int i;
    for (i = 0; i < taille; i++)
        if (tab[i] == n) return i;
    return -1;
}

void histogramme(int note[], int histo[], int tailleNote) {
    int i;
    for (i = 0; i < tailleNote; i++)
        histo[i] = 0;
    for (i = 0; i < tailleNote; i++)
        histo[note[i]]++;
}

int main(void) {
    int i;
    srandom(time(NULL));
    for (i = 0; i < 20; i++)
        printf("%ld\n", random());

    int notes[20], histo[21];
    for (i = 0; i < 21; i++) histo[i] = 0;

    initAlea(notes, 20, 20);
    histogramme(notes, histo, 20);

    printf("===========\n");
    printf("   NOTES\n");
    printf("===========\n");
    for (i = 0; i < 21; i++) {
        printf("%d/20 = %d\n", i, histo[i]);
    }
}

/*
 * En lançant le programme plusieurs fois sans définir de seed,
 * on remarque que l'on obtient toujours les mêmes nombres.
 *
 * J'utilise %ld dans le printf() car la fonction random() retourne
 * en réalité un long et non un int.
 *
 * Je génère 20 notes aléatoires comprises entre 0 et 20,
 * je remplis l'histogramme. Enfin j'affiche le résultat.
 */
