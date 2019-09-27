#include <stdio.h>

int main(void) {
    int a = 0, b = 0, c = 0, d = 0;
    int sum;
    float average;

    printf("Saisir quatre entiers : ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    sum = a + b + c + d;
    average = sum / 4.0;

    printf("%d\n%d\n%d\n%d\n", a, b, c, d);
    printf("somme = %d, moyenne = %f", sum, average);
    return 0;
}