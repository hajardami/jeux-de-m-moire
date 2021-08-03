#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<time.h>
#include<windows.h>
#include "fonctions.h"




typedef struct{

char nom[20];
int score;
}joueur;

joueur premier;
joueur deuxieme;
joueur seul;
//on a utilise une structure joueur pour faciliter la sauvegarde des donnees

char def_limit(int ini, int lim)
{
    char c;

    if ((ini >= 0 && ini <= 9) && (lim >= 0 && lim <= 9))
    {
        ini = ini + '0';
        lim = lim + '0';
        do
        {
            c = getch();
        } while (c < ini || c > lim);
    }
    putchar(c);

    return c;
}
//cette fonction oblige l'utilisateur de ne pas entrer des indices out of range



char PLAYER()
{


    char n;
    printf("\n\t************BIENVENU DANS UNE NOUVELLE PARTIE****************e\n\n");
    printf("\t    *-*-*-*-*-* CHOISIR UN MODE DE JEU *-*-*-*-*-*\n");
	printf("\t      =========================================\n");
	printf("\t      | 1 |             UN JOUEUR             |\n");
	printf("\t      =========================================\n");
	printf("\t      | 2 |             MULTIJOUEUR           |\n");
	printf("\t      =========================================\n");

    return n= def_limit(1,2);

}

//le menu de choix de mode de jeux (un joueur ou deux joueur)

char difficulte()
{
    char level;
    printf("*-*-*-*-*-* CHOISIR UN NIVEAU DE DIIFICULTE *-*-*-*-*-*\n");
    printf("      =========================================\n");
	printf("      | 1 |             FACIL                 |\n");
	printf("      =========================================\n");
	printf("      | 2 |             MOYEN                 |\n");
	printf("      =========================================\n");
	printf("      | 3 |             DIFFICIL              |\n");
	printf("      =========================================\n");

	return level=def_limit(1,3);
}
//menu pour choisir le level


int generateur(int n)
{
    srand(time(NULL));
    int nbgen=rand()%n;

    return nbgen;
}

//fonction qui retourne un nombre aleatoire entre 1 et n


void swap(char L[], int i, int j)
{
  char p=L[i];
  L[i]=L[j];
  L[j]=p;
}

// fonction pour inverser deux elements d'un tableau

char **affichagealeatoire(char *L,int n)
{
    char **T= malloc(n*sizeof(char*));
    char TAB[n*n];
    int i;
    for(i=0;i<n*n;i++)
      {
       int var=generateur(n*n-i);
        TAB[i]=L[var];
        swap(L,var,n*n-1-i);
         }
  int k=0;
for(i=0;i<n;i++)
 {   T[i]=malloc(n*sizeof(char));
     for(int j=0;j<n;j++)
  {T[i][j]=TAB[k];
   k++;
  }
  }
return T;
}

//fonction qui remplit un tableau de 2 dimension par des nombres aleatoire selon le level

void afficher_grille(int n, char mat[n][n])
{
    for (int p=0; p<n; p++)
{
    for(int j=0; j<n; j++){
    printf("\t%c%",mat[p][j]);}
    printf("\t\n\n");

}
}

//cette fonction permet l'affichage d'une grille (tabulation retour a la ligne...)


void UN_JOUEUR(char level)
{
    int scr=0 ;
    int l1, l2, c1, c2 ;
    int n;
    if(level=='1')
    {char L[4]={'A','B','A','B'};

       char **A;
       A=affichagealeatoire(L,2);
       for(int i=(temps_facile / 1000); i > 0; i--)
        {
            system("cls");
            for (int p=0; p<2; p++)
           {
             for(int j=0; j<2 ; j++){
             printf("\t%c", *(*(A+p)+j));}
             printf("\t\n");

            }
             printf("\n");
    printf("Il vous reste: %d secondes", i);
     Sleep(1000);
           }


    system("cls");
    n=2;
    char T[n][n];
    for (int i=0; i<n ; i++){
        for (int j=0;j<n;j++)
        {
            T[i][j]= '0';
        }
    }
    afficher_grille(n,T);
    int s=0;
    while(s!=2){

    printf("\nEntrez le numero de la ligne (ENTRE 0 ET 1) :\t");
    l1=def_limit(0,1)- '0';
    printf("\nEntrez le numero de la colonne (ENTRE 0 ET 1):\t");
    c1=def_limit(0,1) - '0';
     printf("\nEntrez le numero de la ligne (ENTRE 0 ET 1):\t");
    l2=def_limit(0,1) - '0';
    printf("\nEntrez le numero de la colonne (ENTRE 0 ET 1):\t ");
    c2=def_limit(0,1) -'0';
    if(*(*(A+l2)+c2)==*(*(A+l1)+c1)){
            if(T[l1][c1]=='0'){
    scr++;
    seul.score = scr;

s++;


    system("cls");
    T[l1][c1]= *(*(A+l1)+c1);
    T[l2][c2]= *(*(A+l2)+c2);
    afficher_grille(n,T);}
    else printf("\n\tENTRER UNE AUTRE CARTE\n");


    }}
    FILE *scoreboardFile = fopen("scoreboard.txt", "a");
    fprintf(scoreboardFile, "[UN JOUEUR_NIVEAU FACIL] Name: %s \tSCORE: %d\n\n\n", seul.nom, seul.score);
    fclose(scoreboardFile);

    }




  if (level=='2')
    {
     n=4;
     char L[16]={'a','b','c','d','e','f','g','h','a','b','c','d','e','f','g','h'};
     char **C;
     C=affichagealeatoire(L,4);

for(int i=(temps_normal / 1000); i > 0; i--){
system("cls");
for (int p=0; p<4; p++)
{
    for(int j=0; j<4; j++){
    printf("\t%c", *(*(C+p)+j));}
    printf("\t\n\n");

}
printf("\n");
printf("il vous reste: %d secondes", i);
Sleep(1000);
}
system("cls");

char T[n][n];
for (int i=0; i<n ; i++){
        for (int j=0;j<n;j++)
        {
            T[i][j]= '0';
        }
    }
    afficher_grille(n,T);
int s=0;
while(s!=8){

    printf("\nEntrez le numero de la ligne (ENTRE 0 ET 3):\t");
    l1=def_limit(0,3)- '0';
    printf("\nEntrez le numero de la colonne (ENTRE 0 ET 3):\t");
    l2=def_limit(0,3) - '0';
     printf("\nEntrez le numero de la ligne (ENTRE 0 ET 3):\t");
    c1=def_limit(0,3) - '0';
    printf("\nEntrez le numero de la colonne (ENTRE 0 ET 3):\t ");
    c2=def_limit(0,3) -'0';
    if(*(*(C+l2)+c2)==*(*(C+l1)+c1)){
            if(T[l1][c1]=='0'){
        s++;
    scr++;
    seul.score = scr;


    system("cls");
    T[l1][c1]=*(*(C+l2)+c2);
    T[l2][c2]= *(*(C+l2)+c2);
    afficher_grille(n,T);}
    else printf("\n\tENTRER UNE AUTRE CARTE\n");


    }}
     FILE *scoreboardFile = fopen("scoreboard.txt", "a");
    fprintf(scoreboardFile, "[UN JOUEUR_NIVEAU NORMAL] Name: %s \tSCORE: %d\n\n\n", seul.nom, seul.score);
    fclose(scoreboardFile);

    }
if (level=='3')
    {
     n=6;
     char L[36]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r'};
     char **D;
     D=affichagealeatoire(L,6);
for(int i=(temps_difficile / 1000); i > 0; i--){
system("cls");
for (int p=0; p<6; p++)
{
    for(int j=0; j<6; j++){
    printf("\t%c", *(*(D+p)+j));}
    printf("\t\n\n");

}
printf("\n");
printf("il vous reste: %d secondes", i);
Sleep(1000);
}
system("cls");
char T[n][n];
for (int i=0; i<n ; i++){
        for (int j=0;j<n;j++)
        {
            T[i][j]= '0';
        }
    }
    afficher_grille(n,T);
int s=0;
while(s!=18){


    printf("\nEntrez le numero de la ligne (ENTRE 0 ET 5):\t");
    l1=def_limit(0,5)- '0';
    printf("\nEntrez le numero de la colonne (ENTRE 0 ET 5):\t");
    c1=def_limit(0,5) - '0';
     printf("\nEntrez le numero de la ligne (ENTRE 0 ET 5):\t");
    l2=def_limit(0,5) - '0';
    printf("\nEntrez le numero de la colonne (ENTRE 0 ET 5):\t ");
    c2=def_limit(0,5) -'0';
    if(*(*(D+l2)+c2)==*(*(D+l1)+c1)){
    if(T[l1][c1]=='0'){
    scr++;
    seul.score = scr;
    s++;

    system("cls");
    T[l1][c1]= *(*(D+l2)+c2);
    T[l2][c2]= *(*(D+l2)+c2);
    afficher_grille(n,T);

}else printf("\n\tENTRER UNE AUTRE CARTE\n");}}
    FILE *scoreboardFile = fopen("scoreboard.txt", "a");
    fprintf(scoreboardFile, "[UN JOUEUR_NIVEAU DIFFICIL]:    Name: %s \tSCORE: %d\n\n\n", seul.nom, seul.score);
    fclose(scoreboardFile);
}
}
//c'est la fonction principale de jeux dans le cas d'un seul joueur .Elle permet  aussi a la fin de la partie de saauvgarder  les donn�es






void Multijoueur(char level)
{
    int joueur1=1,joueur2=1;
    int sp=0, sd=0;
    int  l1, l2, c1, c2 ;
    int n;

    if(level=='1')
    {

        n=2;
        char L[4]={'A','B','A','B'};
       char **A;
       A=affichagealeatoire(L,2);
       for(int i=(temps_facile / 1000); i > 0; i--)
        {
            system("cls");
            for (int p=0; p<n; p++)
           {
             for(int j=0; j<n ; j++){
             printf("\t%c", *(*(A+p)+j));}
             printf("\t\n");

            }

            printf("\n");
            printf("Il vous reste: %d secondes", i);
           Sleep(1000);
           }

    system("cls");
    char T[n][n];
    for (int i=0; i<n ; i++){
        for (int j=0;j<n;j++)
        {
            T[i][j]= '0';
        }
    }
    afficher_grille(n,T);

    int s=0;

    while(s!=2){
            joueur1=0;
            while(joueur1==0){ if(s==2) break;


    printf("\n\t*****C'EST LE TOUR DE %s :*****\n", premier.nom);

    printf("\nEntrez le numero de la ligne:\t");
    l1=def_limit(0,1)- '0';
    printf("\nEntrez le numero de la colonne:\t");
    c1=def_limit(0,1) - '0';
     printf("\nEntrez le numero de la ligne:\t");
    l2=def_limit(0,1) - '0';
    printf("\nEntrez le numero de la colonne:\t ");
    c2=def_limit(0,1) -'0';

    if (*(*(A+l2)+c2) == *(*(A+l1)+c1)){
            if(T[l1][c1]=='0'){
            s++;
        sp++;
        premier.score=sp;

    system("cls");
    T[l1][c1]= *(*(A+l2)+c2);
    T[l2][c2]= *(*(A+l2)+c2);
    afficher_grille(n,T);}
    else {printf("\n\tENTRER UNE AUTRE CARTE\n"); joueur1=0;}

     joueur1==1;
    }

     else break;}


  if(s==2) break;

    joueur2=0;
    while(joueur2==0){
            if(s==2) break;
     printf("\n\t*****C'EST LE TOUR DE %s :*****\n",deuxieme.nom);

    printf("\nEntrez le numero de la ligne:\t");
    l1=def_limit(0,1)- '0';
    printf("\nEntrez le numero de la colonne:\t");
    c1=def_limit(0,1) - '0';
     printf("\nEntrez le numero de la ligne:\t");
    l2=def_limit(0,1) - '0';
    printf("\nEntrez le numero de la colonne:\t ");
    c2=def_limit(0,1) -'0';

    if (*(*(A+l2)+c2) == *(*(A+l1)+c1)){
            if(T[l1][c1]=='0'){
            s++;
        sd++;
        deuxieme.score=sp;

    system("cls");
    T[l1][c1]= *(*(A+l2)+c2);
    T[l2][c2]= *(*(A+l2)+c2);
    afficher_grille(n,T);}
    else {printf("\n\tENTRER UNE AUTRE CARTE\n"); joueur2=0;}

     joueur2==1;
    }

     else break;}

    }




    if(premier.score>deuxieme.score)
        printf(""""""""" le gagnant(e)est%s""""""""",premier.nom);
    else {if (premier.score<deuxieme.score)
        printf(""""""""" le gagnant(e)est%s""""""""",deuxieme.nom);
        else printf("""""""""""""vous avez le meme score""""""""""""");}

    FILE *scoreboardFile = fopen("scoreboard.txt", "a");
    fprintf(scoreboardFile, "[MULTIJOUEUR_NIVEAU FACILE]:    Name: %s \tSCORE: %d\n\n\n", premier.nom, premier.score);
    fprintf(scoreboardFile, "[MULTIJOUEUR_NIVEAU FACILE]:    Name: %s \tSCORE: %d\n\n\n", deuxieme.nom, deuxieme.score);
    fclose(scoreboardFile);
    }



  if (level=='2')
    {

     int n=4;
     char L[16]={'a','b','c','d','e','f','g','h','a','b','c','d','e','f','g','h'};
     char **C;
     C=affichagealeatoire(L,n);

for(int i=(temps_normal / 1000); i > 0; i--){
system("cls");
for (int p=0; p<n; p++)
{
    for(int j=0; j<n; j++){
    printf("\t%c", *(*(C+p)+j));}
    printf("\t\n\n");

}
printf("\n");
printf("il vous reste: %d secondes", i);
Sleep(1000);
}
system("cls");

char T[n][n];
for (int i=0; i<n ; i++){
        for (int j=0;j<n;j++)
        {
            T[i][j]= '0';
        }
    }
    afficher_grille(n,T);

int s=0;


    while(s!=8){
            joueur1=0;
            while(joueur1==0){ if(s==8) break;


    printf("\n\t*****C'EST LE TOUR DE %s :*****\n", premier.nom);

    printf("\nEntrez le numero de la ligne:\t");
    l1=def_limit(0,3)- '0';
    printf("\nEntrez le numero de la colonne:\t");
    c1=def_limit(0,3) - '0';
     printf("\nEntrez le numero de la ligne:\t");
    l2=def_limit(0,3) - '0';
    printf("\nEntrez le numero de la colonne:\t ");
    c2=def_limit(0,3) -'0';

        if (*(*(C+l2)+c2) == *(*(C+l1)+c1)){
            if(T[l1][c1]=='0'){
            s++;
        sp++;
        premier.score=sp;

    system("cls");
    T[l1][c1]= *(*(C+l2)+c2);
    T[l2][c2]= *(*(C+l2)+c2);
    afficher_grille(n,T);}
    else {printf("\n\tENTRER UNE AUTRE CARTE\n"); joueur1=0;}

     joueur1==1;
    }

     else break;}

  if(s==8) break;
    joueur2 =0;

    while(joueur2==0){ if(s==8) break;

     printf("\n\t*****C'EST LE TOUR DE %s :*****\n",deuxieme.nom);

    printf("\nEntrez le numero de la ligne:\t");
    l1=def_limit(0,3)- '0';
    printf("\nEntrez le numero de la colonne:\t");
    c1=def_limit(0,3) - '0';
     printf("\nEntrez le numero de la ligne:\t");
    l2=def_limit(0,3) - '0';
    printf("\nEntrez le numero de la colonne:\t ");
    c2=def_limit(0,3) -'0';

        if (*(*(C+l2)+c2) == *(*(C+l1)+c1)){
            if(T[l1][c1]=='0'){
            s++;
        sd++;
        deuxieme.score=sp;

    system("cls");
    T[l1][c1]= *(*(C+l2)+c2);
    T[l2][c2]= *(*(C+l2)+c2);
    afficher_grille(n,T);}
    else {printf("\n\tENTRER UNE AUTRE CARTE\n"); joueur2=0;}

     joueur2==1;
    }

     else break;}

    }




    if(premier.score>deuxieme.score)
        printf(""""""""" le gagnant(e)est%s""""""""",premier.nom);
    else {if (premier.score<deuxieme.score)
        printf(""""""""" le gagnant(e)est%s""""""""",deuxieme.nom);
        else printf("""""""""""""vous avez le meme score""""""""""""");}
      FILE *scoreboardFile = fopen("scoreboard.txt", "a");
    fprintf(scoreboardFile, "[MULTIJOUEUR_NIVEAU NORMAL]:    Name: %s \tSCORE: %d\n\n\n", premier.nom, premier.score);
    fprintf(scoreboardFile, "[MULTIJOUEUR_NIVEAU NORMAL]:    Name: %s \tSCORE: %d\n\n\n", deuxieme.nom, deuxieme.score);
    fclose(scoreboardFile);
    }

if (level=='3')
    {
        int s1=0,s2=0;
     int n=6;
     char L[36]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r'};
     char **D;
     D=affichagealeatoire(L,n);
for(int i=(temps_difficile / 1000); i > 0; i--){
system("cls");
for (int p=0; p<n; p++)
{
    for(int j=0; j<n; j++){
    printf("\t%c", *(*(D+p)+j));}
    printf("\t\n\n");

}
printf("\n");
printf("il vous reste: %d secondes", i);
Sleep(1000);
}
system("cls");
char T[n][n];
for (int i=0; i<n ; i++){
        for (int j=0;j<n;j++)
        {
            T[i][j]= '0';
        }
    }
    afficher_grille(n,T);
int s=0;

    while(s!=18){

            joueur1=0;
            while(joueur1==0){
                if(s==18) break;


    printf("\n\t*****C'EST LE TOUR DE %s :*****\n", premier.nom);

    printf("\nEntrez le numero de la ligne:\t");
    l1=def_limit(0,5)- '0';
    printf("\nEntrez le numero de la colonne:\t");
    c1=def_limit(0,5) - '0';
     printf("\nEntrez le numero de la ligne:\t");
    l2=def_limit(0,5) - '0';
    printf("\nEntrez le numero de la colonne:\t ");
    c2=def_limit(0,5) -'0';

    if (*(*(D+l2)+c2) == *(*(D+l1)+c1)){
            if(T[l1][c1]=='0'){
            s++;
        sp++;
        premier.score=sp;

    system("cls");
    T[l1][c1]= *(*(D+l2)+c2);
    T[l2][c2]= *(*(D+l2)+c2);
    afficher_grille(n,T);}
    else {printf("\n\tENTRER UNE AUTRE CARTE\n"); joueur1=0;}

     joueur1==1;
    }

     else break;}


     if(s==18) break;
    joueur2=0;

    while(joueur2==0){
if(s==18) break;
     printf("\n\t*****C'EST LE TOUR DE %s :*****\n",deuxieme.nom);

    printf("\nEntrez le numero de la ligne:\t");
    l1=def_limit(0,5)- '0';
    printf("\nEntrez le numero de la colonne:\t");
    c1=def_limit(0,5) - '0';
     printf("\nEntrez le numero de la ligne:\t");
    l2=def_limit(0,5) - '0';
    printf("\nEntrez le numero de la colonne:\t ");
    c2=def_limit(0,5) -'0';

    if (*(*(D+l2)+c2) == *(*(D+l1)+c1)){
            if(T[l1][c1]=='0'){
            s++;
        sd++;
        deuxieme.score=sp;

    system("cls");
    T[l1][c1]= *(*(D+l2)+c2);
    T[l2][c2]= *(*(D+l2)+c2);
    afficher_grille(n,T);}
    else {printf("\n\tENTRER UNE AUTRE CARTE\n"); joueur2=0;}

     joueur2==1;
    }

     else break;}

    }




    if(premier.score>deuxieme.score)
        printf(""""""""" le gagnant(e)est%s""""""""",premier.nom);
    else {if (premier.score<deuxieme.score)
        printf(""""""""" le gagnant(e)est%s""""""""",deuxieme.nom);
        else printf("""""""""""""vous avez le meme score""""""""""""");}
      FILE *scoreboardFile = fopen("scoreboard.txt", "a");
    fprintf(scoreboardFile, "[MULTIJOUEUR_NIVEAU DIFFICIL]:    Name: %s \tSCORE: %d\n\n\n", premier.nom, premier.score);
    fprintf(scoreboardFile, "[MULTIJOUEUR_NIVEAU DIFFICIL]:    Name: %s \tSCORE: %d\n\n\n", deuxieme.nom, deuxieme.score);
    fclose(scoreboardFile);
}
}


//c'est la fontion qui alterne le jeux entre deux joueur au cas qu'un joueur a choisi les cartes conforme il a la possibilit� de rejouer
