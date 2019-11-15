#include <MLV/MLV_all.h>
#include <stdio.h>

#define WIDTH 500
#define HEIGHT 500

typedef struct {
    int x, y;
} Point;

typedef struct {
    float a, b;
} Droite;

void saisiePoint(Point *p) {
    MLV_wait_mouse(&p->x, &p->y);
}

int construireDroite(Point a, Point b, Droite *d) {
    if (a.x - b.x == 0)
        return 0;
    int dx = b.x - a.x, dy = a.y - b.y;
    d->a = (float) -dy / (float) dx;
    d->b = (float) a.y - d->a * (float) a.x;
    return 1;
}

void dessineDroite(Droite d) {
    MLV_draw_line(0, d.a * 0 + d.b, WIDTH, d.a * WIDTH + d.b, MLV_COLOR_YELLOW);
}

int main(int argc, char *argv[]) {
    Point p1, p2;
    Droite d;

    MLV_create_window("Droite", "", WIDTH, HEIGHT);
    MLV_draw_line(0, HEIGHT / 2, WIDTH, HEIGHT / 2, MLV_COLOR_WHITE);
    MLV_draw_line(WIDTH / 2, 0, WIDTH / 2, HEIGHT, MLV_COLOR_WHITE);
    MLV_update_window();

    saisiePoint(&p1);
    saisiePoint(&p2);

    if (!construireDroite(p1, p2, &d)) {
        printf("[Erreur] Impossible de tracer une droite verticale ! \n");
        return 1;
    }

    dessineDroite(d);

    MLV_update_window();
    MLV_wait_seconds(10);
    return 0;
}
