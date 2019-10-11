#include <stdio.h>
#include <math.h>

int resoudre(float a, float b, float c, float *x1, float *x2) {
    if (a == 0)
        if (b == 0)
            if (c == 0) {
                return -1;
            } else {
                return 0;
            }
        else {
            *x1 = -b / c;
            return 1;
        }
    else {
        int delta = b * b - 4 * a * c;
        if (delta > 0) {
            *x1 = (-b - sqrt(delta)) / 2 * a;
            *x2 = (-b + sqrt(delta)) / 2 * a;
            return 2;
        } else if (delta < 0) {
            return 0;
        } else {
            *x1 = -b / 2 * a;
            return 1;
        }
    }
}

int main(void) {
    int i;
    float a = 0, b = 0, c = 0, x1, x2;
    for (i = 0; i < 10; i++) {
        printf("Saisir les 3 coefficients : ");
        scanf("%f %f %f", &a, &b, &c);
        switch (resoudre(a, b, c, &x1, &x2)) {
            case -1:
                printf("Infinité de solutions !\n");
                break;
            case 1:
                printf("1 solution : x=%f\n", x1);
                break;
            case 2:
                printf("2 solutions : x1=%f, x2=%f\n", x1, x2);
                break;
            default:
                printf("Aucune solution !\n");
        }
    }
}

/*
 * On se place dans le répertoire courant et on fait :
 * ./executables/Ex2 < polynome.txt
 */
