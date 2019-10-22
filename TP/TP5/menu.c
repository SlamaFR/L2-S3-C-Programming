#include <stdio.h>
#include <MLV/MLV_all.h>
#include <string.h>

void fenetre(void) {
    MLV_create_window("Fenêtre", "", 400, 300);
    MLV_update_window();
    MLV_wait_seconds(3);
}

void rectangle(void) {
    int width, height;
    printf("Saisir la taille de la fenêtre : ");
    scanf("%d %d", &width, &height);
    MLV_create_window("Rectangle", "", width, height);
    MLV_draw_filled_rectangle(width / 4, height / 4, width / 2, height / 2, MLV_COLOR_BLUE);
    MLV_update_window();
    MLV_wait_seconds(10);
}

void ellipse(void) {
    int width, height;
    printf("Saisir la taille de la fenêtre : ");
    scanf("%d %d", &width, &height);
    MLV_create_window("Ellipse", "", width, height);
    MLV_draw_filled_ellipse(width / 2, height / 2, width / 2, height / 2, MLV_COLOR_BLUE);
    MLV_update_window();
    MLV_wait_seconds(10);
}

void cercle(void) {
    int width, height;
    printf("Saisir la taille de la fenêtre : ");
    scanf("%d %d", &width, &height);
    MLV_create_window("Cercle", "", width, height);
    if (width > height)
        MLV_draw_filled_circle(width / 2, height / 2, height / 2, MLV_COLOR_BLUE);
    else
        MLV_draw_filled_circle(width / 2, height / 2, width / 2, MLV_COLOR_BLUE);
    MLV_update_window();
    MLV_wait_seconds(10);
}

void cercle_epais(void) {
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

    MLV_create_window("Cercle épais", "", width, height);
    mlv_color = MLV_convert_string_to_color(color);

    for (i = 0; i < thickness; i++)
        MLV_draw_circle(x, y, radius + i, mlv_color);

    MLV_update_window();
    MLV_wait_seconds(10);
}

void cercle_anim(void) {
    int i, width, height, radius, max;
    printf("Saisir la taille de la fenêtre : ");
    scanf("%d %d", &width, &height);
    printf("Saisir le rayon du cercle : ");
    scanf("%d", &radius);

    if (width > height)
        max = height / 2;
    else
        max = width / 2;

    MLV_create_window("Cercle animation", "", width, height);

    for (i = 0; i < max - radius; i++) {
        MLV_draw_circle(width / 2, height / 2, radius + i, MLV_COLOR_ORANGE);
        MLV_wait_milliseconds(50);
        MLV_update_window();
        MLV_draw_circle(width / 2, height / 2, radius + i, MLV_COLOR_BLACK);
    }
    MLV_draw_circle(width / 2, height / 2, max, MLV_COLOR_ORANGE);
    MLV_update_window();
    MLV_wait_seconds(10);
}

void polygone(void) {
    int i, width, height, n, max;
    printf("Saisir la taille de la fenêtre : ");
    scanf("%d %d", &width, &height);
    printf("Saisir le nombre de face du polygone du polygone : ");
    scanf("%d", &n);

    MLV_create_window("Polygone", "", width, height);

    int x_coordinates[n], y_coordinates[n];

    for (i = 0; i < n; i++)
        MLV_wait_mouse(x_coordinates + i, y_coordinates + i);
    MLV_draw_polygon(x_coordinates, y_coordinates, n, MLV_COLOR_FOREST_GREEN);

    MLV_update_window();
    MLV_wait_seconds(10);
}

int main(int argc, char *argv[]) {
    char menu[13];
    printf("Choisir la fonction : ");
    scanf("%s", menu);

    if (strcmp(menu, "fenetre") == 0)
        fenetre();
    else if (strcmp(menu, "rectangle") == 0)
        rectangle();
    else if (strcmp(menu, "ellipse") == 0)
        ellipse();
    else if (strcmp(menu, "cercle") == 0)
        cercle();
    else if (strcmp(menu, "cercle_epais") == 0)
        cercle_epais();
    else if (strcmp(menu, "cercle_anim") == 0)
        cercle_anim();
    else if (strcmp(menu, "polygone") == 0)
        polygone();
    else
        printf("Erreur de saisie !\n");

    return 0;
}