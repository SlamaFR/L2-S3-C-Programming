#include <MLV/MLV_all.h>

int main(int argc, char* argv[]) {
    int width, height;
    printf("Saisir la taille de la fenêtre : ");
    scanf("%d %d", &width, &height);
    MLV_create_window("Rectangle", "", width, height);
    MLV_draw_filled_rectangle(width / 4, height / 4, width / 2, height / 2, MLV_COLOR_BLUE);
    MLV_update_window();
    MLV_wait_seconds(10);
    return 0;
}
