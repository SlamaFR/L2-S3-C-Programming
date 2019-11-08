#include <stdio.h>

int countChars(FILE *file) {
    rewind(file);
    int count = 0;
    while (fgetc(file) != EOF)
        count++;
    return count;
}

int countLines(FILE *file) {
    rewind(file);
    int count = 1;
    char c;
    while (fscanf(file, "%c", &c) != EOF)
        if (c == '\n') count++;
    return count;
}

int countWords(FILE *file) {
    rewind(file);
    int count = 0, wordLength = 0;
    char c;
    while (fscanf(file, "%c", &c) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ' || c == '\n') {
            if (wordLength > 0) {
                count++;
                wordLength = 0;
            }
        } else {
            wordLength++;
        }
    }
    return wordLength > 0 ? ++count : count;
}

void usage(char *name) {
    printf("Usage: %s [-cmlv][file1][file2][...]\n", name);
}

int main(int argc, char *argv[]) {
    int i, c = 1, startArg = 1, all = 1, chars = 0, words = 0, lines = 0;
    if (argv[1][0] == '-') {
        startArg = 2;
        while (argv[1][c] != '\0') {
            switch (argv[1][c]) {
                case 'c':
                    chars = 1;
                    all = 0;
                    break;
                case 'm':
                    words = 1;
                    all = 0;
                    break;
                case 'l':
                    lines = 1;
                    all = 0;
                    break;
                case 'v':
                    printf("Program created by Irwin Madet.\n\n");
                    break;
                default:
                    usage("my_wc");
                    return -1;
            }
            c++;
        }
    }
    for (i = startArg; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("Le fichier %s n'existe pas !\n", argv[i]);
        } else {
            if (all || chars)
                printf("Nombre de caractères dans %s : %d\n", argv[i], countChars(file));
            if (all || words)
                printf("Nombre de mots dans %s : %d\n", argv[i], countWords(file));
            if (all || lines)
                printf("Nombre de lignes dans %s : %d\n", argv[i], countLines(file));
        }
        fclose(file);
        if (i < argc - 1)
            printf("\n------\n\n");
    }
}
