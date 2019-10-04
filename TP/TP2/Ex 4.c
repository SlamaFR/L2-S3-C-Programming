#include <stdio.h>

char display(void) {
    char color = 0;

    printf("(R = rouge, V = vert, B = bleu, J = jaune et 0 = annuler)\n");
    printf("Choisissez une couleur : ");
    scanf(" %c", &color);

    switch (color) {
        case 'R':
            printf("Vous avez choisi Rouge !\n");
            break;
        case 'V':
            printf("Vous avez choisi Vert !\n");
            break;
        case 'B':
            printf("Vous avez choisi Bleu !\n");
            break;
        case 'J':
            printf("Vous avez choisi Jaune !\n");
            break;
        case '0':
            printf("Vous avez annulé !\n");
            break;
        default:
            printf("Erreur de saisie !\n");
    }
    return color;
}

int main(void) {
    char callback;
    do {
        callback = display();
    } while (callback != '0');
    return 0;
}
