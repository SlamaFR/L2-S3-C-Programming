#include <stdio.h>

#define N 35

void fill(int t[][N]) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j <= i; j++) {
            if (i == j || j == 0)
                t[i][j] = 1;
            else if (j < i)
                t[i][j] = t[i - 1][j] + t[i - 1][j - 1];
        }
}

void display(int t[][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}
