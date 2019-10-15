void miroirTranche(int tab[], int min, int max) {
    int i, tmp;
    for (i = min; i < (min + max) / 2; i++) {
        tmp = tab[i];
        tab[i] = tab[max + min - i - 1];
        tab[max + min - i - 1] = tmp;
    }
}
