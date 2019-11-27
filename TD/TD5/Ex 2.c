#include <stdio.h>

#define DGMAX 3

typedef struct {
    int degre;
    float coefficients[DGMAX];
} Polynome;

void lirePolynome(Polynome *p) {
    int degre;
    for (degre = 0; degre < DGMAX; degre++) {
        printf("Saisir le coefficient pour le degré %d : ", degre);
        scanf("%f", &p->coefficients[degre]);
        if (p->coefficients[degre] != 0)
            p->degre = degre;
    }
}
