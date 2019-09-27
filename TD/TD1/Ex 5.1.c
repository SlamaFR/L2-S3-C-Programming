#include <stdio.h>

int main(void) {
    int a = 0, b = 0, buffer = 0;

    printf("Saisir deux entiers : ");
    scanf("%d %d", &a, &b);

    buffer = b;
    b = a;
    a = buffer;

    printf("a=%d b=%d", a, b);
    return 0;
}