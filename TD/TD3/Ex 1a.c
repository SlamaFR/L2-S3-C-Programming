#include <stdio.h>

void MinMax(int n, int *min, int *max) {
    int i, scan;
    printf("Saisie un entier : ");
    scanf("%d", &scan);
    *min = scan;
    *max = scan;
    for (i = 1; i < n; i++) {
        printf("Saisie un entier : ");
        scanf("%d", &scan);
        if (scan < *min) *min = scan;
        if (scan > *max) *max = scan;
    }
}

int main(void) {
    int n, min, max;
    printf("Saisir le nombre d'entiers à compter : ");
    scanf("%d", &n);
    MinMax(n, &min, &max);
    printf("Min : %d - Max : %d\n", min, max);
}
