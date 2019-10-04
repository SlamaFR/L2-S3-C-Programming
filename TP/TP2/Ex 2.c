#include <stdio.h>

int main(void) {
    int guess = 0, plays = 0, target = 0;

    printf("Saisir un entier compris entre 0 et 1000 inclus : ");
    scanf("%d", &target);

    do {
        plays++;
        printf("Coup n°%d/10 - Faites un proposition : ", plays);
        scanf("%d", &guess);

        if (guess < target)
            printf("C'est plus !\n");
        else if (guess > target)
            printf("C'est moins !\n");
        else {
            printf("Bravo, vous avez gagné en %d coup%s !\n", plays, plays > 1 ? "s" : "");
            return 0;
        }
    } while (plays < 10);
    printf("Perdu !\n");
    return 0;
}
