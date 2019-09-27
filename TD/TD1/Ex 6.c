#include <stdio.h>

int main(void) {
    int a = 0, b = 0, c = 0;

    printf("Saisir les coefficients du polynôme de degré 2 : ");
    scanf("%d %d %d", &a, &b, &c);

    if (a == 0)
        if (b == 0)
            if (c == 0)
                printf("Infinité de solutions.");
            else
                printf("Pas de solution.");
        else
            printf("1 solution.");
    else {
        int delta = b ^2 - 4 * a * c;
        if (delta > 0)
            printf("2 solutions.");
        else if (delta < 0)
            printf("Pas de solution (réelle).");
        else
            printf("1 solution.");
    }
    return 0;
}