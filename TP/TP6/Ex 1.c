#include <stdio.h>

int fileExists(char* fileName) {
    int result;
    FILE *file = fopen(fileName, "r");
    result = file != NULL;
    fclose(file);
    return result;
}

int main(int argc, char *argv[]) {
    int i, startsWithDash = 0, files = 0;
    for (i = 0; i < argc; i++) {
        if (argv[i][0] == '-')
            startsWithDash++;
        else if (fileExists(argv[i]))
            files++;
    }
    printf("Nombre d'arguments : %d\n", argc);
    printf("Nombre d'arguments commençant par - : %d\n", startsWithDash);
    printf("Nombre d'arguments portant le nom d'un fichier : %d\n", files);
}
