#include <stdio.h>

int main(void) {
    int i = 0;

    printf("Saisir un entier : ");
    scanf("%d", &i);

    switch (i) {
        case 1:
            printf("premier choix\n");
            break;
        case 2:
            printf("second choix\n");
            break;
        case 3:
            printf("troisième choix\n");
            break;
        default:
            printf("choix incorrect\n");
    }
    return 0;
}
