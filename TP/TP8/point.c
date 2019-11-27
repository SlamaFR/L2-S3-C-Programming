#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>

#define TAILLE_X 512
#define TAILLE_Y 512
#define NB_MAX_POINT 256

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int distCarree;
} PointDistance;

typedef struct {
    PointDistance tab[NB_MAX_POINT];
    int nbPoints;
} TabPoint;

void genererTabPoint(TabPoint *t, int nbPoints) {
    int i;
    t->nbPoints = nbPoints;
    for (i = 0; i < nbPoints; i++)
        t->tab[i].point = (Point) {(int) random() % TAILLE_X, (int) random() % TAILLE_Y};
}

MLV_Color fabriqueCouleur(int i) {
    return MLV_rgba(255 - i, i, 0, 255);
}

void dessineTabPoint(TabPoint t) {
    int i;
    for (i = 0; i < t.nbPoints; i++) {
        Point p = t.tab[i].point;
        MLV_draw_filled_circle(p.x, p.y, 5, fabriqueCouleur(i));
    }
}

void calculeDistances(TabPoint *t, Point origine) {
    int i;
    for (i = 0; i < t->nbPoints; i++) {
        Point p = t->tab[i].point;
        int distance = (origine.x - p.x) * (origine.x - p.x) + (origine.y - p.y) * (origine.y - p.y);
        t->tab[i].distCarree = distance;
    }
}

int comparePoint(const void *a, const void *b) {
    PointDistance p = *((PointDistance *) a);
    PointDistance q = *((PointDistance *) b);
    return p.distCarree - q.distCarree;
}

int main(int argc, char *argv[]) {
    srandom(time(NULL));
    MLV_create_window("Points", "", TAILLE_X, TAILLE_Y);

    TabPoint t;
    int x, y;
    genererTabPoint(&t, NB_MAX_POINT);
    dessineTabPoint(t);
    MLV_update_window();
    MLV_wait_mouse(&x, &y);

    MLV_clear_window(MLV_COLOR_BLACK);
    calculeDistances(&t, (Point) {x, y});
    qsort(t.tab, t.nbPoints, sizeof(PointDistance), comparePoint);
    dessineTabPoint(t);
    MLV_update_window();

    MLV_wait_seconds(30);
    return 0;
}
