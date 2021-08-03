//#ifdef fonction_h
#define fonction_h
#define temps_facile 5000
#define temps_normal 15000
#define temps_difficile 25000




char def_limit(int initial, int limite);
char PLAYER();
char difficulte();
int generateur(int n);
void swap(char L[], int i, int j);
char **affichagealeatoire(char *L,int n);
void afficher_grille(int n, char mat[n][n]);
void UN_JOUEUR(char level);
void Multijoueur(char level);
