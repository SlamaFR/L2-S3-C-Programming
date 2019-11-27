#include <stdio.h>

typedef struct {
    int n, p;
} Rationnel;

int gcd(int n, int p) {
    while (n != p) {
        if (n > p)
            n -= p;
        else
            p -= n;
    }
    return n;
}

int lireRationnel(Rationnel *r) {
    int n, p, pgcd;
    printf("Saisir le numérateur et le dénominateur : ");
    scanf("%d %d", &n, &p);
    if (p == 0)
        return 0;
    pgcd = gcd(n, p);
    r->n = n / pgcd;
    r->p = p / pgcd;
    return 1;
}

Rationnel sommeRationnel(Rationnel r1, Rationnel r2) {
    int n = r1.n * r2.p + r2.n * r1.p, p = r1.p * r2.p, pgcd = gcd(n, p);
    return (Rationnel) {n, p};
}
