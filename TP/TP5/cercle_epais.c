#include <MLV/MLV_all.h>

int main(int argc, char *argv[]) {
    int i, width, height, x, y, radius, thickness;
    char color[30];
    MLV_Color mlv_color;
    printf("Saisir la taille de la fenêtre : ");
    scanf("%d %d", &width, &height);
    printf("Saisir le centre du cercle : ");
    scanf("%d %d", &x, &y);
    printf("Saisir le rayon du cercle : ");
    scanf("%d", &radius);
    printf("Saisir la couleur du cercle : ");
    scanf("%s", color);
    printf("Saisir l'épaisseur du cercle : ");
    scanf("%d", &thickness);
    mlv_color = MLV_convert_string_to_color(color);

    MLV_create_window("Cercle épais", "", width, height);
    for (i = 0; i < thickness; i++)
        MLV_draw_circle(x, y, radius + i, mlv_color);
    MLV_update_window();
    MLV_wait_seconds(10);
    MLV_free_window();

    MLV_create_window("Cercle épais v2", "", width, height);
    MLV_draw_filled_circle(x, y, radius + thickness, mlv_color);
    MLV_draw_filled_circle(x, y, radius, MLV_COLOR_BLACK);
    MLV_update_window();
    MLV_wait_seconds(10);
    return 0;
}

/*
 * La première version est "transparente" au milieu mais moins esthétique
 * et nécessite de faire plus d'opération.
 *
 * La seconde version est plus rapide et plus esthétique mais il est impossible
 * de voir à travers le cercle (à cause du disque noir).
 */
