#include <stdio.h>

#define N 35

void fill(unsigned int t[]) {
    int i;
    for (i = N - 1; i > 1; i--)
        t[i] += t[i - 1];
}

void display(unsigned int t[]) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
}

int main(void) {
    unsigned int t[N] = {0};
    int i;
    t[0] = 1;
    for (i = 0; i < N; i++) {
        fill(t);
        display(t);
    }
    return 0;
}
