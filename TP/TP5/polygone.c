#include <MLV/MLV_all.h>

int main(int argc, char *argv[]) {
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
    return 0;
}
