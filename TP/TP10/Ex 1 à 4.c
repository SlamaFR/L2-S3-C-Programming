#include <MLV/MLV_all.h>
#include <stdlib.h>

#define TAILLE_X 512
#define TAILLE_Y 512

typedef struct {
    int x, y;
} Point;

typedef struct cellulePoint {
    Point point;
    struct cellulePoint *suivante;
} CellulePoint, *ListePoint;

CellulePoint *allouerCellule(Point point) {
    CellulePoint *cellule = malloc(sizeof(Point));
    if (cellule != NULL) {
        cellule->point = point;
        cellule->suivante = NULL;
    }
    return cellule;
}

void dessineLigne(Point p1, Point p2, MLV_Color couleur) {
    MLV_draw_line(p1.x, p1.y, p2.x, p2.y, couleur);
    MLV_update_window();
}

void dessinePolygone(ListePoint liste, MLV_Color couleur) {
    CellulePoint *actuelle = liste;
    CellulePoint *precedente = NULL;
    Point premier = actuelle->point;
    while (actuelle != NULL) {
        if (precedente != NULL)
            dessineLigne(precedente->point, actuelle->point, couleur);
        precedente = actuelle;
        actuelle = actuelle->suivante;
    }
    dessineLigne(precedente->point, premier, couleur);
}

int insererEnTete(ListePoint *liste, Point point) {
    CellulePoint *ptr = allouerCellule(point);
    if (ptr == NULL)
        return 0;
    ptr->suivante = *liste;
    *liste = ptr;
    return 1;
}

void concatenerListes(ListePoint *origine, ListePoint *ajout) {
    CellulePoint *actuelle = *origine;
    while (actuelle->suivante != NULL)
        actuelle = actuelle->suivante;
    actuelle->suivante = *ajout;
    *ajout = NULL;
}

void deplacerEnTete(ListePoint *liste, Point point) {
    CellulePoint *actuelle = *liste;
    CellulePoint *precedente = NULL;
    while (actuelle != NULL) {
        if (actuelle->point.x == point.x && actuelle->point.y == point.y) {
            if (precedente != NULL) {
                precedente->suivante = actuelle->suivante;
                actuelle->suivante = *liste;
                *liste = actuelle;
            }
            return;
        }
        precedente = actuelle;
        actuelle = actuelle->suivante;
    }
}

int calculerDistance(Point p1, Point p2) {
    return (p2.x - p1.y) * (p2.x - p1.y) + (p2.y - p1.y) * (p2.y - p1.y);
}

Point plusPres(ListePoint *liste, Point point) {
    Point resultat = (*liste)->point;
    CellulePoint *actuelle = *liste;
    while (actuelle != NULL) {
        if (calculerDistance(point, actuelle->point) > calculerDistance(point, resultat))
            resultat = actuelle->point;
        actuelle = actuelle->suivante;
    }
    return resultat;
}

void deplacerPlusPresEnTete(ListePoint *liste, Point point) {
    deplacerEnTete(liste, plusPres(liste, point));
}

void trierPoints(ListePoint *liste) {
    Point point = (Point) {0, 0};
    CellulePoint *actuelle = *liste;
    while (actuelle->suivante != NULL) {
        deplacerPlusPresEnTete(&(actuelle->suivante), point);
        point = actuelle->point;
        actuelle = actuelle->suivante;
    }
}

int saisirPolygone(ListePoint *liste) {
    MLV_Event event = MLV_NONE;
    int x, y;
    CellulePoint *precedent = NULL;
    CellulePoint *premier = NULL;
    while (event != MLV_KEY) {
        event = MLV_wait_keyboard_or_mouse(NULL, NULL, NULL, &x, &y);
        if (event == MLV_MOUSE_BUTTON) {
            Point nouveau = (Point) {x, y};
            if (precedent != NULL)
                dessineLigne(precedent->point, nouveau, MLV_COLOR_WHITE);
            if (!insererEnTete(liste, nouveau))
                return 0;

            precedent = (*liste);
            if (premier == NULL)
                premier = precedent;
        }
    }
    if (precedent != NULL)
        dessineLigne(precedent->point, premier->point, MLV_COLOR_WHITE);
    return 1;
}

ListePoint extraireListeBasGauche(ListePoint *liste, Point point) {
    CellulePoint *actuelle = *liste;
    ListePoint nouvelleListe = NULL;
    while (actuelle != NULL) {
        if (actuelle->point.x < point.x && actuelle->point.y > point.y) {
            if (!insererEnTete(&nouvelleListe, actuelle->point))
                return NULL;
        }
        actuelle = actuelle->suivante;
    }
    return nouvelleListe;
}

ListePoint extraireListeBasDroite(ListePoint *liste, Point point) {
    CellulePoint *actuelle = *liste;
    ListePoint nouvelleListe = NULL;
    while (actuelle != NULL) {
        if (actuelle->point.x > point.x && actuelle->point.y > point.y) {
            if (!insererEnTete(&nouvelleListe, actuelle->point))
                return NULL;
        }
        actuelle = actuelle->suivante;
    }
    return nouvelleListe;
}

ListePoint extraireListeHautGauche(ListePoint *liste, Point point) {
    CellulePoint *actuelle = *liste;
    ListePoint nouvelleListe = NULL;
    while (actuelle != NULL) {
        if (actuelle->point.x < point.x && actuelle->point.y < point.y) {
            if (!insererEnTete(&nouvelleListe, actuelle->point))
                return NULL;
        }
        actuelle = actuelle->suivante;
    }
    return nouvelleListe;
}

ListePoint extraireListeHautDroite(ListePoint *liste, Point point) {
    CellulePoint *actuelle = *liste;
    ListePoint nouvelleListe = NULL;
    while (actuelle != NULL) {
        if (actuelle->point.x > point.x && actuelle->point.y < point.y) {
            if (!insererEnTete(&nouvelleListe, actuelle->point))
                return NULL;
        }
        actuelle = actuelle->suivante;
    }
    return nouvelleListe;
}

void libererListe(ListePoint *liste) {
    CellulePoint *aSupprimer = (*liste);
    while (aSupprimer != NULL) {
        (*liste) = (*liste)->suivante;
        free(aSupprimer);
        aSupprimer = (*liste);
    }
}

int main(int argc, char *argv[]) {
    ListePoint liste = NULL, basGauche, basDroite, hautGauche, hautDroite;
    Point point;

    MLV_create_window("Liste de points", "", TAILLE_X, TAILLE_Y);

    saisirPolygone(&liste);

    MLV_wait_mouse(&point.x, &point.y);
    basGauche = extraireListeBasGauche(&liste, point);
    basDroite = extraireListeBasDroite(&liste, point);
    hautGauche = extraireListeHautGauche(&liste, point);
    hautDroite = extraireListeHautDroite(&liste, point);


    trierPoints(&basGauche);
    trierPoints(&basDroite);
    trierPoints(&hautGauche);
    trierPoints(&hautDroite);

    MLV_clear_window(MLV_COLOR_BLACK);
    dessinePolygone(basGauche, MLV_COLOR_BLUE);
    dessinePolygone(basDroite, MLV_COLOR_GREEN);
    dessinePolygone(hautGauche, MLV_COLOR_RED);
    dessinePolygone(hautDroite, MLV_COLOR_YELLOW);

    MLV_wait_mouse(NULL, NULL);
    MLV_clear_window(MLV_COLOR_BLACK);

    concatenerListes(&hautGauche, &hautDroite);
    concatenerListes(&basGauche, &basDroite);

    trierPoints(&basGauche);
    trierPoints(&hautGauche);

    dessinePolygone(basGauche, MLV_COLOR_BLUE);
    dessinePolygone(hautGauche, MLV_COLOR_RED);

    MLV_wait_mouse(NULL, NULL);
    libererListe(&liste);
    libererListe(&basGauche);
    libererListe(&basDroite);
    libererListe(&hautGauche);
    libererListe(&hautDroite);
    MLV_free_window();
    return 0;
}