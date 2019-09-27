#include <stdio.h>

int main(void) {
    float a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    float x = 0, y = 0;

    printf("Saisir les coefficients de la première droite : ");
    scanf("%f %f", &a1, &b1);
    printf("Saisir les coefficients de la seconde droite : ");
    scanf("%f %f", &a2, &b2);

    x = (b2 - b1) / (a1 - a2);
    y = a1 * x + b1;

    printf("x=%f y=%f", x, y);
    return 0;
}