#include <stdio.h>
#include <math.h>

int main(void) {
    int i = 0, racine = 0;

    printf("Saisir un entier positif : ");
    scanf("%d", &i);

    if (i < 0) {
        printf("Erreur : L'entier saisi est négatif !\n");
        return 1;
    }

    for (int j = 0; j < i; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int j = 0; j < i; j += 2) {
        printf("%d ", j);
    }
    while (racine * racine <= i) racine++;
    printf("\nRacine : %d", racine - 1);
    return 0;
}
