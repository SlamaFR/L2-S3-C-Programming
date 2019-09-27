#include <stdio.h>

int main(void) {
    int i = 0;

    printf("Saisir un entier : ");
    scanf("%d", &i);

    if (i % 2 == 0) printf("%d est pair.", i);
    else printf("%d est impair.", i);
    return 0;
}