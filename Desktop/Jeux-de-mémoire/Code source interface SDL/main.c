#include "fonction.h"


int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int statut = EXIT_FAILURE;

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    window = SDL_CreateWindow("jeux de memoire", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              360, 360, SDL_WINDOW_SHOWN);
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(NULL == renderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto Quit;
    }

SDL_Surface* image = SDL_LoadBMP("lesmenus/nvmenu.bmp");
SDL_Texture* pTextureImage = SDL_CreateTextureFromSurface(renderer, image);
SDL_FreeSurface(image);
SDL_RenderClear(renderer);
SDL_RenderCopy(renderer, pTextureImage, NULL, NULL); // Affiche ma texture sur touts l'écran
SDL_RenderPresent(renderer);
SDL_Event event;
int continuer=1;
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
                case SDLK_KP_1: // Demande à
                        SDL_RenderClear(renderer);


                        menu2(window,renderer);

                        break;
                    case SDLK_KP_2: // Demande l'éditeur de niveaux
                        continuer = 0;;
                        break;


            }
            break;
    }
}Quit:
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();

    return statut;
}

