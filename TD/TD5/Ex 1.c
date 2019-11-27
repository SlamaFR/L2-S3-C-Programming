#define MAXNOTE 20
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
