#include <stdio.h>

void readLess2(int *r) {
    int n = -1;
    do {
        printf("(0 = Pierre, 1 = Feuille, 2 = Ciseaux)\n");
        printf("Jouez votre coup : ");
        scanf("%d", &n);
    } while (0 > n || n > 2);
    *r = n;
}

void referee(int p1, int p2, int *scorePlayer1, int *scorePlayer2) {
    printf("\n=================================\n");
    if (p1 == p2) {
        printf("Match nul !");
    } else if (p1 == (p2 + 1) % 3) {
        printf("Joueur 1 remporte la partie !");
        *scorePlayer1 += 1;
    } else {
        printf("Joueur 2 remporte la partie !");
        *scorePlayer2 += 1;
    }
    printf("\n=================================\n");
}

int main(void) {
    int i, player1 = 0, player2 = 0, score1 = 0, score2 = 0;
    for (i = 0; i < 10; i++) {
        printf("\n########################\n");
        printf(" DEBUT DE LA PARTIE %d !", i + 1);
        printf("\n########################\n");

        printf("\nJOUEUR 1 :\n");
        readLess2(&player1);

        printf("\nJOUEUR 2 :\n");
        readLess2(&player2);

        referee(player1, player2, &score1, &score2);
    }

    printf("\n+-------------+\n");
    printf("|  RESULTATS  |");
    printf("\n+-------------+\n");
    printf("J1 : %d - J2 : %d", score1, score2);
    return 0;
}
