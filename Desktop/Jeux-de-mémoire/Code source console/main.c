#include "fonctions.h"

typedef struct{

char nom[20];
int score;
}joueur;

joueur premier;
joueur deuxieme;
joueur seul;

int main()
{
      char level=difficulte();
      system("cls");
      char n=PLAYER(); //premier, deuxieme, seul);
      system("cls");
        if(n=='2')
        {printf("ENTREZ L'IDENTIFIANT DU JOUEUR 1:\t");
        scanf("%s",premier.nom);
         printf("ENTREZ L'IDENTIFIANT DU JOUEUR 2:\t ");
        scanf("%s",deuxieme.nom);
        system("cls");
        Multijoueur(level);
        }



        if(n=='1')
        {printf("ENTREZ VOTRE IDENTIFIANT:\t");
        scanf("%s",seul.nom);
        system("cls");
        UN_JOUEUR(level);
        }



      return 0;
}

