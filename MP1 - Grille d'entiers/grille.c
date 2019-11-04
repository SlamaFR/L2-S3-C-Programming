#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <MLV/MLV_all.h>

#define N 20
#define CELL_SIZE 75
#define BUTTON_WIDTH 200
#define SIDEBAR_MARGIN 10
#define BUTTON_HEIGHT() (CELL_SIZE - 2 * SIDEBAR_MARGIN)
#define BUTTON_X(size) ((size) * CELL_SIZE + SIDEBAR_MARGIN)
#define BUTTON_Y_TOP(i) ((i) * CELL_SIZE + SIDEBAR_MARGIN)
#define BUTTON_Y_BOTTOM(size, i) (((size) - (i) - 1) * CELL_SIZE + SIDEBAR_MARGIN)

typedef struct {
    int xD, yD;
} Direction;

typedef struct {
    int x, y;
} Coordinates;

/**
 * Demander à l'utilisateur de saisir les paramètres de partie.
 * @param size Taille maximale de la grille.
 * @param max Maximum des valeurs de la grille.
 */
void setup(int *size, int *max) {
    do {
        printf("Saisir la taille de la grille (entre 0 et %d) : ", N);
        scanf("%d", size);
    } while (*size < 0 || *size > N);
    printf("Saisir le maximum des valeurs de la grille : ");
    scanf("%d", max);
}

/**
 * Convertir des coordonnées de clic en coordonnées de case.
 * @param x Abscisse du clic.
 * @param y Ordonnée du clic.
 * @param i Ordonnée de la case.
 * @param j Abscisse de la case.
 */
void pixelToCell(int x, int y, int *i, int *j) {
    *j = x / CELL_SIZE;
    *i = y / CELL_SIZE;
}

/**
 * Déterminer si un clic si situe sur un bouton.
 * @param x Abscisse du clic.
 * @param y Ordonnée du clic.
 * @param coordinates Cordonnées du point d'ancrage du bouton.
 * @return Booléen.
 */
int clickInButton(int x, int y, Coordinates coordinates) {
    return coordinates.x <= x && x <= coordinates.x + BUTTON_WIDTH &&
           coordinates.y <= y && y <= coordinates.y + BUTTON_HEIGHT();
}

/**
 * Calculer la somme des termes en partant de (x, y)
 * et en allant dans la direction donnée pour une distance donnée.
 * @param grid Grille.
 * @param x Abscisse de départ.
 * @param y Ordonnée de départ.
 * @param range Distance d'exploration.
 * @param direction Direction.
 * @return Somme des termes.
 */
int explore(int grid[N][N], int x, int y, int range, Direction direction) {
    int i, sum = 0;
    if (direction.xD == 0 && direction.yD == 0) return grid[y][x];
    for (i = 0; i < range + 1; i++)
        sum += grid[y + i * direction.yD][x + i * direction.xD];
    return sum;
}

/**
 * Déterminer la direction en fonction des points de départ et d'arrivée.
 * @param x1 Abscisse de départ.
 * @param y1 Ordonnée de départ.
 * @param x2 Abscisse d'arrviée.
 * @param y2 Ordonnée d'arrivée.
 * @return Direction.
 */
Direction getDirection(int x1, int y1, int x2, int y2) {
    if (x2 - x1 > 0) {
        if (y2 - y1 > 0 && abs(x2 - x1) == abs(y2 - y1)) return (Direction) {1, 1};
        if (y2 - y1 < 0 && abs(x2 - x1) == abs(y2 - y1)) return (Direction) {1, -1};
        if (y2 - y1 == 0) return (Direction) {1, 0};
    } else if (x2 - x1 < 0) {
        if (y2 - y1 > 0 && abs(x2 - x1) == abs(y2 - y1)) return (Direction) {-1, 1};
        if (y2 - y1 < 0 && abs(x2 - x1) == abs(y2 - y1)) return (Direction) {-1, -1};
        if (y2 - y1 == 0) return (Direction) {-1, 0};
    } else {
        if (y2 - y1 > 0) return (Direction) {0, 1};
        if (y2 - y1 < 0) return (Direction) {0, -1};
    }
    return (Direction) {0, 0};
}

/**
 * Déterminer la distance en fonction des points de départ et d'arrivée.
 * @param x1 Abscisse de départ.
 * @param y1 Ordonnée de départ.
 * @param x2 Abscisse d'arrviée.
 * @param y2 Ordonnée d'arrivée.
 * @return Distance d'exploration.
 */
int getRange(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1 != 0 ? x2 - x1 : y2 - y1);
}

/**
 * Ouvrir un fichier et vérifier que l'ouverture a fonctionné.
 * @param file Fichier ouvert.
 * @param fileName Nom du fichier.
 * @param mode Mode de lecture.
 * @return Code de retour (0 = échec, 1 = succès).
 */
int openFile(FILE **file, char *fileName, char *mode) {
    *file = fopen(fileName, mode);
    return *file == NULL ? 0 : 1;
}

/**
 * Écrire les données actuelles du jeu dans un fichier.
 * @param fileName Nom du fichier.
 * @param gridSize Taille de la grille.
 * @param sum Somme déjà atteinte.
 * @param moves Nombre de coups déjà joués.
 * @param max Maximum des valeurs de la grille.
 * @param grid Grille.
 */
void saveGame(char *fileName, int gridSize, int sum, int moves, int max, int grid[N][N]) {
    FILE *file;
    if (!openFile(&file, fileName, "w+")) {
        printf("[ERREUR] Échec de l'ouverture du fichier !\n");
        return;
    }
    int i, j;
    fprintf(file, "%d\n", gridSize);
    fprintf(file, "%d %d %d\n", sum, moves, max);
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++)
            fprintf(file, "%d ", grid[i][j]);
        fputc('\n', file);
    }
    fclose(file);
}

/**
 * Lire un fichier et récupérer les données.
 * @param fileName Nom du fichier.
 * @param gridSize Taille de la grille.
 * @param sum Somme déjà atteinte.
 * @param moves Nombre de coups déjà joués.
 * @param max Maximum des valeurs de la grille.
 * @param grid Grille.
 * @return Code de retour (0 = échec, 1 = succès).
 */
int loadGame(char *fileName, int *gridSize, int *sum, int *moves, int *max, int grid[N][N]) {
    FILE *file;
    if (!openFile(&file, fileName, "r")) {
        printf("[ERREUR] Échec de l'ouverture du fichier !\n");
        return 0;
    }
    int i, j;
    fscanf(file, "%d", gridSize);
    fscanf(file, "%d %d", sum, moves);
    fscanf(file, "%d", max);
    for (i = 0; i < *gridSize; i++)
        for (j = 0; j < *gridSize; j++)
            fscanf(file, "%d ", &grid[i][j]);
    fclose(file);
    return 1;
}

/**
 * Construire la grille avec des nombres aléatoires compris dans [-max, max].
 * @param grid Grille.
 * @param size Taille de la grille.
 * @param max Maximum des valeurs de la grille.
 */
void buildGrid(int grid[N][N], int size, int max) {
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            grid[i][j] = (int) random() % (2 * max) - max;
}

/**
 * Mettre à jour la grille.
 * @param grid Grille
 * @param max Maximum des valeurs de la grille.
 * @param x Abscisse de départ.
 * @param y Ordonnée de départ.
 * @param range Distance de mise à jour.
 * @param direction Direction.
 */
void updateGrid(int grid[N][N], int max, int x, int y, int range, Direction direction) {
    int i, j;
    for (i = 0; i < range + 1; i++) {
        for (j = y + i * direction.yD; j > 0; j--)
            grid[j][x + i * direction.xD] = grid[j - 1][x + i * direction.xD];
        grid[0][x + i * direction.xD] = (int) random() % (2 * max) - max;
    }
}

/**
 * Affiche les grille dans le terminal.
 * @param grid Grille.
 * @param size Taille de la grille.
 */
void displayGrid(int grid[N][N], int size) {
    int i, j;
    printf("\n");
    for (i = 0; i < size + 2; i++) {
        if (i > 1)
            printf("%d\t", i - 2);
        if (i == 1) {
            printf("\n");
            continue;
        }
        for (j = 0; j < size + 1; j++) {
            if (i == 0) {
                if (j > 0) printf(" %d", j - 1);
                printf("\t");
            } else if (i > 1 && j > 0)
                printf(grid[i - 2][j - 1] >= 0 ? " %d\t" : "%d\t", grid[i - 2][j - 1]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Dessiner la grille dans la fenêtre.
 * @param grid Grille.
 * @param size Taille de la grille.
 */
void drawGrid(int grid[N][N], int size) {
    int i, j;
    char s[8];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            sprintf(s, "%d", grid[i][j]);
            MLV_draw_text_box(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE, s, 0, MLV_COLOR_BLACK,
                              MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER,
                              MLV_VERTICAL_CENTER);
        }
    }
}

/**
 * Surligner une ligne de cases.
 * @param grid Grille.
 * @param x Abscisse de départ.
 * @param y Ordonnée de départ.
 * @param range Distance de surlignage.
 * @param direction Direction.
 */
void highlightCells(int grid[N][N], int x, int y, int range, Direction direction) {
    int i;
    char s[8];
    MLV_Color color;
    for (i = 0; i < range + 1; i++) {
        sprintf(s, "%d", grid[y + i * direction.yD][x + i * direction.xD]);
        color = 0 < i && i < range ? MLV_COLOR_IVORY2 : MLV_COLOR_IVORY3;
        MLV_draw_text_box((x + i * direction.xD) * CELL_SIZE, (y + i * direction.yD) * CELL_SIZE, CELL_SIZE, CELL_SIZE,
                          s, 0, MLV_COLOR_BLACK, MLV_COLOR_BLACK, color, MLV_TEXT_CENTER,
                          MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    }
}

/**
 * Dessiner la barre latérale dans la fenêtre.
 * @param size Taille de la grille.
 * @param sum Somme actuelle.
 * @param moves Nombre de coups déjà joués.
 * @param coordinates Tableau des coordonnées des boutons.
 */
void drawSidebar(int size, int sum, int moves, Coordinates coordinates[]) {

    char s[24];
    sprintf(s, "Somme : %d", sum);
    MLV_draw_text_box(BUTTON_X(size), BUTTON_Y_TOP(0), BUTTON_WIDTH, BUTTON_HEIGHT(), s, 0, MLV_COLOR_WHITE,
                      MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    sprintf(s, "Coups : %d", moves);
    MLV_draw_text_box(BUTTON_X(size), BUTTON_Y_TOP(1), BUTTON_WIDTH, BUTTON_HEIGHT(), s, 0, MLV_COLOR_WHITE,
                      MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
    MLV_draw_text_box(BUTTON_X(size), BUTTON_Y_BOTTOM(size, 1), BUTTON_WIDTH, BUTTON_HEIGHT(), "Sauvegarder", 0,
                      MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER,
                      MLV_VERTICAL_CENTER);
    coordinates[0] = (Coordinates) {size * CELL_SIZE + SIDEBAR_MARGIN, (size - 2) * CELL_SIZE + SIDEBAR_MARGIN};
    MLV_draw_text_box(BUTTON_X(size), BUTTON_Y_BOTTOM(size, 0), BUTTON_WIDTH, BUTTON_HEIGHT(), "Quitter", 0,
                      MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER,
                      MLV_VERTICAL_CENTER);
    coordinates[1] = (Coordinates) {size * CELL_SIZE + SIDEBAR_MARGIN, (size - 1) * CELL_SIZE + SIDEBAR_MARGIN};
}

/**
 * Analyser et interpréter les arguments du programme.
 * @param argc Nombre d'argument.
 * @param argv Tableau des arguments.
 * @param a Mode d'affichage (ascii ou graphique).
 * @param c Gestion de la sauvegarde (création ou lecture).
 * @param fileName Nom du fichier.
 * @return Code de retour (0 = échec, 1 = succès).
 */
int handleArguments(int argc, char **argv, int *a, int *c, char **fileName) {
    int mode = 0, file = 0;
    if (argc < 3) {
        return 0;
    } else {
        int i = 0;
        if (argv[1][0] != '-')
            return 0;
        while (argv[1][i] != '\0') {
            switch (argv[1][i]) {
                case 'a':
                    *a = 1;
                    mode = 1;
                    break;
                case 'g':
                    *a = 0;
                    mode = 1;
                    break;
                case 'c':
                    *c = 1;
                    file = 1;
                    break;
                case 'l':
                    *c = 0;
                    file = 1;
                    break;
            }
            i++;
        }
        *fileName = argv[2];
    }
    return (mode && file);
}

/**
 * Boucle du jeu en mode textuel.
 * @param grid Grille.
 * @param fileName Fichier de sauvegarde.
 * @param gridSize Taille de la grille.
 * @param valuesMax Maximum des valeurs de la grille.
 * @param sum Somme actuelle.
 * @param moves Nombre de coups déjà joués.
 */
void asciiLoop(int grid[N][N], char *fileName, int gridSize, int valuesMax, int sum, int moves) {
    int x1, y1, x2, y2, range;
    char choice = 0;
    Direction dir;

    do {
        printf("Somme : %d  -  Coups : %d\n", sum, moves);
        displayGrid(grid, gridSize);
        do {
            printf("Choisir une action (c = Continuer, s = Sauvegarder, q = Quitter) : ");
            scanf(" %c", &choice);
        } while (choice != 'c' && choice != 's' && choice != 'q');
        switch (choice) {
            case 'c':
                printf("Coordonnées de départ : ");
                scanf("%d %d", &y1, &x1);
                printf("Coordonnées d'arrivée : ");
                scanf("%d %d", &y2, &x2);
                dir = getDirection(x1, y1, x2, y2);
                if ((dir.xD == 0 && dir.yD == 0) && (x1 != x2 && y1 != y2))
                    continue;
                moves += 1;
                range = getRange(x1, y1, x2, y2);
                sum += explore(grid, x1, y1, range, dir);
                updateGrid(grid, valuesMax, x1, y1, range, dir);
                break;
            case 's':
                saveGame(fileName, gridSize, sum, moves, valuesMax, grid);
                break;
            case 'q':
                return;
            default:
                continue;
        }
    } while (sum != 100);
}

/**
 * Boucle du jeu en mode graphique.
 * @param grid Grille.
 * @param fileName Fichier de sauvegarde.
 * @param gridSize Taille de la grille.
 * @param valuesMax Maximum des valeurs de la grille.
 * @param sum Somme actuelle.
 * @param moves Nombre de coups déjà joués.
 */
void graphicalLoop(int grid[N][N], char *fileName, int gridSize, int valuesMax, int sum, int moves) {
    int x, y, x1 = -1, y1 = -1, x2 = -1, y2 = -1, range;
    Direction dir;
    Coordinates coordinates[2];
    MLV_create_window_with_default_font("Grille d'entier", "",
                                        gridSize * CELL_SIZE + BUTTON_WIDTH + 2 * SIDEBAR_MARGIN,
                                        gridSize * CELL_SIZE, "bebas.ttf", 30);

    do {
        MLV_clear_window(MLV_COLOR_BLACK);
        drawGrid(grid, gridSize);
        drawSidebar(gridSize, sum, moves, coordinates);
        if (x1 >= 0 && y1 >= 0)
            highlightCells(grid, x1, y1, 0, (Direction) {0, 0});

        MLV_update_window();
        MLV_wait_mouse(&x, &y);

        if (x > gridSize * CELL_SIZE) {
            if (clickInButton(x, y, coordinates[0]))
                saveGame(fileName, gridSize, sum, moves, valuesMax, grid);
            else if (clickInButton(x, y, coordinates[1]))
                return;
        } else if (!(0 <= x1 && x1 < gridSize && 0 <= y1 && y1 < gridSize)) {
            pixelToCell(x, y, &y1, &x1);
        } else {
            pixelToCell(x, y, &y2, &x2);
            dir = getDirection(x1, y1, x2, y2);
            if ((dir.xD == 0 && dir.yD == 0) && (x1 != x2 && y1 != y2)) {
                x1 = y1 = x2 = y2 = -1;
                continue;
            }
            moves += 1;
            range = getRange(x1, y1, x2, y2);
            sum += explore(grid, x1, y1, range, dir);
            highlightCells(grid, x1, y1, range, dir);
            MLV_update_window();
            MLV_wait_seconds(1);
            updateGrid(grid, valuesMax, x1, y1, range, dir);
        }

        if (x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0)
            x1 = y1 = x2 = y2 = -1;

    } while (sum != 100);
}

/**
 * Fonction principale.
 */
int main(int argc, char *argv[]) {
    int grid[N][N], gridSize, valuesMax, sum = 0, moves = 0;
    int ascii = 0, newGrid = 0;
    char *fileName;
    srandom(time(NULL));

    if (!handleArguments(argc, argv, &ascii, &newGrid, &fileName))
        return -1;

    if (newGrid) {
        setup(&gridSize, &valuesMax);
        buildGrid(grid, gridSize, valuesMax);
    } else if (!loadGame(fileName, &gridSize, &sum, &moves, &valuesMax, grid))
        return -1;

    if (ascii)
        asciiLoop(grid, fileName, gridSize, valuesMax, sum, moves);
    else
        graphicalLoop(grid, fileName, gridSize, valuesMax, sum, moves);

    printf("Bravo ! Vous avez gagné en %d coups !", moves);
    return 0;
}
