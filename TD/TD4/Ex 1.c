#include <stdio.h>

#define N 10

void saisie(int *x, int *y) {
    do {
        printf("Saisir les coordonnées : ");
        scanf("%d %d", x, y);
    } while (*x < 0 || *x >= N || *y < 0 || *y >= N);
}

void remplir(char t[][N], int x, int y) {
    int i, j;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == y && j == x)
                t[i][j] = '*';
            else if (i - y == j - x || x + y == i + j)
                t[i][j] = '+';
            else
                t[i][j] = ' ';
        }
    }
}

void afficher(char t[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", t[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int x, y;
    char t[N][N];
    saisie(&x, &y);
    remplir(t, x, y);
    afficher(t);
}