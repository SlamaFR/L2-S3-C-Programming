int somme(int tab[], int taille) {
    int i, somme = 0;
    for (i = 0; i < taille; i++)
        somme += tab[i];
    return somme;
}

float moyenne(int tab[], int taille) {
    int i;
    float moyenne = 0;
    if (taille == 0) return moyenne;
    for (i = 0; i < taille; i++)
        moyenne += tab[i];
    return moyenne / taille;
}
