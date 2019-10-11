#include <stdio.h>

void afficheTab(int tab[], int taille) {
    int i;
    for (i = 0; i < taille; i++)
        printf("%d\n", tab[i]);
}

void changeTab(int tab[], int indice) {
    printf("V: %p %p\n", tab, &tab[indice]);
    tab[indice] += 2;
    printf("V: %p %p\n", tab, &tab[indice]);
}

int main(void) {
    int tableau[] = {1, 2, 3, 4, 5};
    afficheTab(tableau, 5);

    int indice = 2;
    printf("M: %p %p\n", tableau, &tableau[indice]);
    changeTab(tableau, indice);
    printf("M: %p %p\n", tableau, &tableau[indice]);
}
