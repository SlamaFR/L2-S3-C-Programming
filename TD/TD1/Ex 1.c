#include <stdio.h>

int main(void) {
    int i, j;        /* Déclaration des entiers */
    float x, y, z;   /* Déclaration des flottants */

    i = 3;
    j = 5;           /* Affectation des variables */
    x = 3.0f;

    /* Affichage dans la console */
    printf("i=%d j=%d somme=%d\n", i, j, i + j);

    i = j / 2;       /* i prend la valeur 2 */
    y = x / 2;       /* y prend la valeur 1.5 */
    z = j / 2;       /* z prend la valeur 2.0 */

    /* Affichage dans la console */
    printf("i=%d\ny=%f z=%f\n", i, y, z);
    return 0;
}