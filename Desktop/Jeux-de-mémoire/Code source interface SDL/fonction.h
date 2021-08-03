//#ifdef fonction_h
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_image.h>
#include<SDL_ttf.h>
#include<time.h>
#include<windows.h>
#define fonction_h
char* facile(int y);
char* normale(int y);
char* diffcile(int y);
int generateur(int n);
void Afficherimage(char*photo,SDL_Surface*image,int i,int j,int l,int c);
void attender(SDL_Window*ecran,SDL_Surface *image , int **M ,int l,int c);
void afficher(SDL_Window*ecran,SDL_Surface *image,int **inverser , int **M ,int l,int c);
void matriceinitiale1(int **mat, int **inverser,int a,int b);
void matriceinitial2(int val[],int n);
void remplir(int val[], int **mat,int a,int b);
void game(SDL_Window*ecran,SDL_Surface *surface,SDL_Event event,int l,int c);
void menu2(SDL_Window *window,SDL_Renderer *renderer);
