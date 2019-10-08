#include <stdio.h>

int main(void) {
    int i = 0, sum = 0, size = 0;

    printf("Saisir un ou plusieurs entiers positifs.\nSaisir un entier négatif pour arrêter la saisie : ");
    do {
        scanf("%d", &i);
        if (i >= 0) {
            sum += i;
            size++;
        }
    } while (i >= 0);

    if (size > 0)
        printf("Moyenne : %f", sum * 1.0 / size);
    else
        printf("Erreur : Vous n'avez saisi aucun entier positif !");
}
