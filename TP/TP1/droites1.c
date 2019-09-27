#include <stdio.h>
#include <math.h>

int main(void) {
    float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    float xGap = 0, yGap = 0;
    float a = 0, b = 0;

    printf("Saisir les coordonnées du 1er point : ");
    scanf("%f %f", &x1, &y1);
    printf("Saisir les coordonnées du 2nd point : ");
    scanf("%f %f", &x2, &y2);

    xGap = x2 - x1;
    yGap = y2 - y1;
    a = yGap / xGap;
    b = y1 - a * x1;

    if (b >= 0) {
        printf("y = %fx + %f\n", a, b);
    } else {
        printf("y = %fx - %f\n", a, fabsf(b));
        /* J'utilise fabsf() pour rendre le résultat plus joli. */
    }
    return 0;
}