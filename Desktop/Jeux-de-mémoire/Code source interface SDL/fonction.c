
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_image.h>
#include<SDL_ttf.h>
#include<time.h>
#include<windows.h>
#include "fonction.h"

char* facile(int y){
    switch(y){
    case 1: return "facile/coq.bmp";break;
    case 2: return "facile/grenouille.bmp";break;

    } //cette fonction permet de representer les noms des  images du niveau facile par des nombres pour faciliter la manipulation
}
char* normale(int y){
    switch(y){
    case 1: return "normal/lapin.bmp";break;
    case 2: return "normal/couchon.bmp";break;
    case 3: return "normal/abeille.bmp";break;
    case 4: return "normal/chien.bmp";break;
    case 5: return "normal/oiseaux.bmp";break;
    case 6: return "normal/tortue.bmp";break;

    }//cette fonction permet de representer les noms des  images du niveau normal par des nombres pour faciliter la manipulation


}
char* diffcile(int y){
    switch(y){
    case 1: return "difficile/cameleon.bmp";break;
    case 2: return "difficile/canard.bmp";break;
    case 3: return "difficile/cheval.bmp";break;
    case 4: return "difficile/tortue2.bmp";break;
    case 5: return "difficile/oiseaux2.bmp";break;
    case 6: return "difficile/ane.bmp";break;
    case 7: return "difficile/abeille2.bmp";break;
    case 8: return "difficile/coq2.bmp";break;
    }
}
//cette fonction permet de representer les noms des  images du niveau normal par des nombres pour faciliter la manipulation
// on a utiliser des images differentes pour chaque niveau pour adapter les tailles d'image selon le nombre de carte


void Afficherimage(char*photo,SDL_Surface*image,int i,int j,int l,int c){
    SDL_Surface *im;
    SDL_Rect rec;

    int h=360/l,w=360/c;

    rec.x=j*w;
    rec.y=i*h;
    rec.w=w;
    rec.h=w;

    im=SDL_LoadBMP(photo);
    SDL_BlitSurface(im,NULL,image,&rec);
} //cette fonction permet d'afficher une image adapteé selon les indices et le nombres de lignes et de colonnes

void attender(SDL_Window*ecran,SDL_Surface *image , int **M ,int l,int c){
    int i,j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            char* nom;
            switch(l){
            case 2:
                nom=facile(M[i][j]) ;break;
            case 3:
                nom=normale(M[i][j]) ;break;
            case 4:
                nom=diffcile(M[i][j]) ;break;
            }
            Afficherimage(nom,image,i, j,l,c);
            SDL_UpdateWindowSurface( ecran );
        }
    }
}

void afficher(SDL_Window*ecran,SDL_Surface *image,int **inverser , int **M ,int l,int c){
int valeur,i,j;

for(i=0;i<l;i++){
     for(j=0; j<c; j++){

        if (inverser[i][j]==0){
            char* nom;
            switch(l){
            case 2:
                nom="inverser/chif0.bmp" ;break;
            case 3:
                nom="inverser/chif0A.bmp" ;break;
            case 4:
                nom="inverser/chif0B.bmp" ;break;
            }
            Afficherimage(nom,image,i, j,l,c);
            SDL_UpdateWindowSurface( ecran );

        }
        else{
            char* nom;
            switch(l){
            case 2:
                nom=facile(M[i][j]) ;break;
            case 3:
                nom=normale(M[i][j]) ;break;
            case 4:
                nom=diffcile(M[i][j]) ;break;
            }

            Afficherimage(nom,image,i, j,l,c);
            SDL_UpdateWindowSurface( ecran );


        }
     }
 }

}
//c'est une fonction principale elle nous permet d'afficher les cartes


void matriceinitiale1(int **mat, int **inverser,int l,int c){

int i,j;
    for(i=0;i<l;i++){
        for(j=0; j<c; j++){
           mat[i][j] = 0;
           inverser[i][j] = 0;
        }
    }
} //cette fonction peremet d'initialiser les tableaux a 0

void matriceinitial2(int val[],int n){

  int i,j;
for (i=0; i<n/2; i++){

    val[i]=i+1;}
  for (j=n/2; j<n; j++){

    val[j]=1+j-n/2;}
}
//remplir les elements du tableau de 1 a n/2(pair) et refaire cela pour le reste du tableau
int generateur(int n)
{
    srand(time(NULL));
    int nbgen=rand()%n;

    return nbgen;
}//cette fonction nous permet de generer un nombre aleatoire entre 1 et n

void remplir(int val[], int **mat,int a,int b){
 int i,j,indice,x=a*b;
 for(i=0; i<a; i++){
     for(j=0; j<b; j++){
        indice =generateur(x);
        mat[i][j]=val[indice];
        int k;
        int var=val[indice];
        for(k=indice;k<x-1;k++){
          val[k]=val[k+1];
        }
        val[x-1]=var;
        x--;
     }
  }
}
// cette fonction est utile pour le remplissage de la matrice de facon aleatoire
void game(SDL_Window*ecran,SDL_Surface *surface,SDL_Event event,int l,int c){

  int len=0;
  int val[l*c];
  matriceinitial2(val,l*c); //remplir le tableau de 1 a a*b/2  et refaire cela pour le reste du tableau si on est au niveau facile 1 2 1 2
  int *p,*q, **M,**inverser;
  len = sizeof(int *) * l + sizeof(int) * c * l;
  M = (int **)malloc(len);
  inverser = (int **)malloc(len);
  p = (int *)(M + l);
  q = (int *)(inverser + l);
  int k;
  for(k = 0; k < l; k++){
    M[k] = (p + c * k);
    inverser[k] = (q + c * k);}
  matriceinitiale1(M, inverser,l,c);//matrice des 0
  remplir(val, M ,l,c);// la matrice aleatoire

attender(ecran,surface,M,l,c);

switch(l){
case 2:Sleep(2000);break;
case 3:Sleep(4000);break;
case 4:Sleep(6000);break;
}

afficher(ecran,surface,inverser,M,l,c);

int h=360/l,w=360/c;

int gagne=0,compteur=0;

int score=0;


while(gagne==0){

        int retour=0,i,j;
        int lig,col,valeur;
        SDL_PollEvent(&event);
        switch(event.type){
        case SDL_QUIT:
        exit(0);
        break;
        case SDL_MOUSEBUTTONDOWN:
           // printf("%dx     %dy\n",event.button.x,event.button.y);
            if(event.button.button==SDL_BUTTON_LEFT &&event.button.clicks==1){
                if(event.button.x>=0&&event.button.x<=360 &&event.button.y>=0&&event.button.y<=360){
            lig=event.button.y/h;
            col=event.button.x/w;
            if(inverser[lig][col]!=2){
            inverser[lig][col]=1;
            valeur=M[lig][col];
            afficher(ecran,surface,inverser,M,l,c);
            compteur++;}
             }
            }
        break;
        }
        Sleep(200);
if(compteur==2){
    int carreau=0,valeur1,valeur2,lig1,col1,lig2,col2;
    for(i=0;i<l;i++){
          for(j=0;j<c;j++){
            if(inverser[i][j]==1){
                carreau++;
                if(carreau==1){
                 valeur1=M[i][j];
                 lig1=i;col1=j;
                }
                if(carreau==2){
                 valeur2=M[i][j];
                 lig2=i;col2=j;
                }
            }}}
    if(valeur1==valeur2){
        inverser[lig1][col1]=2;
        inverser[lig2][col2]=2;
        score++;
    }
    else{

        inverser[lig1][col1]=0;
        inverser[lig2][col2]=0;

    }

    compteur=0;

}
afficher(ecran,surface,inverser,M,l,c);
int k,h;
for(k=0;k<l;k++){
    for(h=0;h<c;h++){
        if(inverser[k][h]==2){
            retour++;}}}
if(retour==l*c){gagne=1;}
else{gagne=0;}

}
printf("vorte score est :%d",score);
}

void menu2(SDL_Window *window,SDL_Renderer *renderer){
SDL_Surface* image = SDL_LoadBMP("lesmenus/MENU2.bmp");
SDL_Texture* pTextureImage = SDL_CreateTextureFromSurface(renderer, image);
SDL_FreeSurface(image);
SDL_RenderClear(renderer);
SDL_RenderCopy(renderer, pTextureImage, NULL, NULL); // Affiche ma texture sur touts l'écran
SDL_RenderPresent(renderer);
SDL_Surface *surface;
surface=SDL_GetWindowSurface(window);
int level;
SDL_Event event;
int continuer=1,a,b;
while (continuer)
{
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {

                    break;
                case SDLK_KP_1: // level1
                       a=2;b=2;

                        break;
                    case SDLK_KP_2: // level2
                        a=3;b=4;

                        break;
                    case SDLK_KP_3: // Demande l'éditeur de niveaux
                        a=4;b=4;

                        break;



            }
game(window,surface,event,a,b);
            break;
    }
}}
