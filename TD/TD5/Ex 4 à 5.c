#include <stdio.h>
#include <string.h>

#define MAXNOTE 20
#define MAXFICHES 20
#define MAXC 50

typedef struct {
    int jour;
    char mois[11];
    int annee;
} Date;

typedef struct {
    char nom[MAXC], prenom[MAXC];
    Date naissance;
    char formation[2];
    int redoublant, groupeTD, notes[MAXNOTE], nbNotes;
} Fiche;

typedef struct {
    Fiche fiches[MAXFICHES];
    int nbFiches;
} Classe;

void lireDate(Date *d) {
    printf("Saisir le jour : ");
    scanf("%d", &d->jour);
    printf("Saisir le mois : ");
    scanf("%s", d->mois);
    printf("Saisir l'année' : ");
    scanf("%d", &d->annee);
}

void afficheDate(Date d) {
    printf("%d %s %d\n", d.jour, d.mois, d.annee);
}

void lireFiche(Fiche *f) {
    printf("Saisir le nom et le prénom : ");
    scanf("%s %s", f->nom, f->prenom);
    lireDate(&f->naissance);
    printf("Saisir la formation : ");
    scanf(" %c%c", f->formation, f->formation + 1);
    printf("Redoublant ? ");
    scanf("%d", &f->redoublant);
    printf("Saisir le n° de TD : ");
    scanf("%d", &f->groupeTD);
}

void afficheFiche(Fiche f) {
    printf("%s %s\n", f.nom, f.prenom);
    printf("Né(e) le ");
    afficheDate(f.naissance);
    printf("En formation %s, TD n°%d\n", f.formation, f.groupeTD);
    if (f.redoublant)
        printf("(Redoublant)\n");
}

int ajouteNote(Fiche *f) {
    if (f->nbNotes == MAXNOTE)
        return 0;
    printf("Saisir la note : ");
    scanf("%d", f->notes + f->nbNotes);
    f->nbNotes++;
    return 1;
}

float moyenne(Fiche f) {
    int i;
    if (!f.nbNotes)
        return -1;
    int result = 0;
    for (i = 0; i < f.nbNotes; i++)
        result += f.notes[i];
    return (float) result / (float) f.nbNotes;
}

int ajouterFiche(Classe *c, Fiche f) {
    int i = c->nbFiches;
    if (i == MAXFICHES)
        return 0;
    while (i >= 0 && strcmp(f.nom, c->fiches[i].nom) > 0) {
        c->fiches[i] = c->fiches[i - 1];
        i--;
    }
    c->fiches[i] = f;
    c->nbFiches++;
    return 1;
}
