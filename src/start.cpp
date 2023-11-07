
// Include
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
using namespace std;
#include <string.h>
#include <cstdio>
#include <SDL2/SDL_mixer.h>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_video.h"

void menu(bool &choix, bool &musique)
{

    srand(time(NULL));
    // Initialisation
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Erreur lors de l'initialisation de SDL: %s\n", SDL_GetError());
    }
    if (TTF_Init() == -1)
    {
        printf("TTF_Init: %s\n", TTF_GetError());
    }

    // Initialisation window

    SDL_Window *win = SDL_CreateWindow("DINO RUNNER", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 500, 0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);

    bool stop = false;

    int mouseX;
    int mouseY;

    SDL_Color blanc = {255, 255, 255};
    SDL_Color noir = {0, 0, 0};
    TTF_Font *dogica = TTF_OpenFont("font/dogica.ttf", 16);
    if (dogica == NULL)
    {
        fprintf(stderr, "Impossible de charger \"dogica.ttf\"");
        exit(EXIT_FAILURE);
    }

    SDL_Event event;

    while (!stop)

    {

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

        SDL_RenderClear(rend);

        while (SDL_PollEvent(&event))
        {

            switch (event.type)
            {
            case SDL_QUIT:
                // Quit
                stop = true;
            }
        }

        SDL_RenderPresent(rend);
        SDL_Delay(1000 / 60);
    }
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);

    SDL_Quit();
}