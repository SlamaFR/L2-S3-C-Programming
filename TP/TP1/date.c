#include <stdio.h>

/**
 * Retourne s selon la pluralité de n.
 * @return "s" ou "".
 */
char *p(n) {
    return n > 1 ? "s" : "";
}

int main(void) {
    int days = 0, weeks = 0, months = 0, years = 0, centuries = 0;

    printf("Saisir le nombre de jours : ");
    scanf("%d", &days);
    printf("\n%d jours correspondent à : \n", days);

    centuries = days / 36500;
    days -= centuries * 36500;
    years = days / 365;
    days -= years * 365;
    months = days / 30;
    days -= months * 30;
    weeks = days / 7;
    days -= weeks * 7;

    printf("%d siècle%s %d année%s %d mois %d semaine%s et %d jour%s", centuries, p(centuries), years, p(years), months,
           weeks, p(weeks), days, p(days));
    return 0;
}