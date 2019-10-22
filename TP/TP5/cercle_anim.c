#include <MLV/MLV_all.h>

int main(int argc, char *argv[]) {
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
    return 0;
}
