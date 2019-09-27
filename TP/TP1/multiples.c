#include <stdio.h>

char *divisible(int n) {
    if (n % 2 == 0 && n % 3 == 0) {
        return "divisible par 2 et par 3.";
    } else if (n % 2 == 0) {
        return "divisible par 2.";
    } else if (n % 3 == 0) {
        return "divisible par 3.";
    }
    return "";
}

int main(void) {
    /* Données */
    int n, p; /* 2 Nombres entiers fournis par l’utilisateur */

    printf("Ce programme calcule la sommes de deux entiers \net indique s'ils sont divisibles par 2 ou par 3.\n");
    printf("Saisissez le premier nombre : ");
    scanf("%d", &n); /* Saisie du premier nombre */
    printf("Saisissez le deuxième nombre : ");
    scanf("%d", &p); /* Saisie du deuxième nombre */

    printf("%3d  %s\n", n, divisible(n));
    printf("%3d  %s\n", p, divisible(p));

    /* Résultat */
    long sum = n + p; /* Somme des nombres n et p */
    printf("Somme: %ld\n", sum);
    return 0;
}