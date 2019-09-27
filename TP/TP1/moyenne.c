#include <stdio.h>

int main(void) {
    /* Données */
    int n, p; /* 2 Nombres entiers fournis par l’utilisateur */

    /* Résultat */
    float average; /* Moyenne des nombres n et p */

    printf("Ce programme calcule la moyenne de deux entiers\n");
    printf("Saisissez le premier nombre : ");
    scanf("%d", &n); /* Saisie du premier nombre */
    printf("Saisissez le deuxième nombre : ");
    scanf("%d", &p); /* Saisie du deuxième nombre */
    if (n > 0 && p > 0) {
        /* Calcul de la moyenne */
        average = (n + p) / 2.0;

        printf("La moyenne des deux nombres est : %5.2f\n", average);
    } else {
        printf("Les deux nombres doivent être positifs ou nuls !\n");
    }
    return 0;
}