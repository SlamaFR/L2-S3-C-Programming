#include <stdio.h>

#define N 35

void fill(unsigned int mem[], unsigned int pascal[]) {
    int i;
    pascal[0] = mem[0];
    for (i = 0; i < N; i++)
        pascal[i] = mem[i] + mem[i + 1];
}

void display(unsigned int t[]) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
}

int main(void) {
    unsigned int tab[2][N] = {0};
    int i, memoire = 0;
    tab[memoire][0] = 1;
    for (i = 0; i < N; i++) {
        fill(tab[memoire], tab[1 - memoire]);
        display(tab[1 - memoire]);
        memoire = 1 - memoire;
    }
    return 0;
}
