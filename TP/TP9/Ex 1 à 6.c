#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define CMD_SIZE 10

typedef struct {
    float *coef;
    int degre;
} Polynome;

typedef struct {
    char nom;
    Polynome p;
} Interface;

void affichePolynome(Polynome p) {
    int i;
    for (i = p.degre; i >= 0; i--)
        if (!p.coef[i])
            continue;
        else if (i == 0)
            printf("%g", p.coef[i]);
        else if (i == 1)
            printf("%gx", p.coef[i]);
        else
            printf("%gx^%d + ", p.coef[i], i);
    printf("\n");
}

int lirePolynome(Polynome *p) {
    int deg;
    do {
        printf("Saisir le degré maximal : ");
        scanf("%d", &p->degre);
    } while (p->degre < 0);

    p->coef = (float *) calloc(p->degre + 1, sizeof(float));

    if (p->coef == NULL)
        return 0;

    printf("Saisir le coefficient du degré %d : ", p->degre);
    scanf("%f", p->coef + p->degre);

    printf("Saisir les degré suivis des coefficients :\n");
    do {
        scanf("%d", &deg);
        if (deg < 0)
            break;
        else if (deg <= p->degre)
            scanf("%f", p->coef + deg);
    } while (deg >= 0);
    return 1;
}

int somme(Polynome p, Polynome q, Polynome *res) {
    int i, maxD = p.degre > q.degre ? p.degre : q.degre;

    res->degre = maxD;
    res->coef = (float *) calloc(res->degre + 1, sizeof(float));

    if (res->coef == NULL)
        return 0;

    for (i = 0; i <= maxD; i++)
        if (i <= p.degre && i <= q.degre)
            res->coef[i] = p.coef[i] + q.coef[i];
        else if (i <= p.degre)
            res->coef[i] = p.coef[i];
        else if (i <= q.degre)
            res->coef[i] = q.coef[i];
    return 1;
}

int produit(Polynome p, Polynome q, Polynome *res) {
    int i, j;

    res->degre = p.degre + q.degre;
    res->coef = (float *) calloc(res->degre + 1, sizeof(float));

    if (res->coef == NULL)
        return 0;

    for (i = 0; i <= p.degre; i++)
        for (j = 0; j <= q.degre; j++)
            res->coef[i + j] += p.coef[i] * q.coef[j];
    return 1;
}

int ajouterPolynome(Polynome polynomes[], char names[], int *nbPolynomes, Polynome p, char name) {
    if (*nbPolynomes == N)
        return 0;

    polynomes[*nbPolynomes] = p;
    names[*nbPolynomes] = name;

    (*nbPolynomes)++;
    return 1;
}

int lireCommande(char *s) {
    int i = 0;
    char c = 0;
    while (i < CMD_SIZE - 1 && c != '\n') {
        scanf("%c", &c);
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

int main(void) {
    Polynome p1, p2, res;

    lirePolynome(&p1);
    lirePolynome(&p2);

    affichePolynome(p1);
    affichePolynome(p2);

    somme(p1, p2, &res);
    printf("Somme: ");
    affichePolynome(res);

    produit(p1, p2, &res);
    printf("Produit: ");
    affichePolynome(res);

    free(p1.coef);
    free(p2.coef);
    free(res.coef);
}
