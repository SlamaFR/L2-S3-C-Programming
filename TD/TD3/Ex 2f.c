void decaleD(int t[], int taille) {
    int tmp = t[taille - 1], i;
    for (i = taille - 1; i > 0; i--)
        t[i] = t[i - 1];
    t[0] = tmp;
}