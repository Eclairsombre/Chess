
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
#include <vector>
#include "grid.cpp"
#include "bot.cpp"

int main()
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

    SDL_Window *win = SDL_CreateWindow("CHESS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);

    bool stop = false;

    int mouseX;
    int mouseY;

    bool isDragging = false;

    vector<SDL_Rect> pieces;

    grid g(rend);
    int offsetX, offsetY, indiceDrag;

    SDL_Event e;
    ChessBot bot;
    int delay = 60;
    g.resetGrid();

    while (!stop)

    {

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

        SDL_RenderClear(rend);
        g.checkEnd(stop);
        g.showGrid(rend);

        g.eventHolder(e, stop);
        if (g.getTurn() == g.getPlayerTwoCamp() && delay == 0)
        {
            bot.playAsSecondPlayer(g);
            delay = 60;
        }
        else if (g.getTurn() == g.getPlayerTwoCamp() && delay > 0)
        {
            delay--;
        }

        SDL_RenderPresent(rend);
        SDL_Delay(1000 / 60);
    }
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
}