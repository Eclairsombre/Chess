
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

bool pointInRect(int x, int y, SDL_Rect rect)
{
    return x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h;
}

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

    bool stop = false;

    int mouseX;
    int mouseY;

    bool isDragging = false;

    vector<SDL_Rect> pieces;

    grid g;
    int offsetX, offsetY, indiceDrag;

    SDL_Event e;

    for (int i = 0; i < 2; i++)
    {
        for (int y = 0; y < 8; y++)
        {
            SDL_Rect rect = {120 + y * 100, 120 + i * 100, 60, 60};
            pieces.push_back(rect);
        }
    }

    while (!stop)

    {

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

        SDL_RenderClear(rend);

        g.showGrid(rend);
        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        for (int i = 0; i < pieces.size(); i++)
        {
            SDL_RenderFillRect(rend, &pieces[i]);
        }

        while (SDL_PollEvent(&e))
        {

            if (e.type == SDL_QUIT)
            {
                stop = true;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    for (int i = 0; i < pieces.size(); i++)
                    {
                        if (e.button.x >= pieces[i].x && e.button.x <= pieces[i].x + pieces[i].w && e.button.y >= pieces[i].y && e.button.y <= pieces[i].y + pieces[i].h)
                        {

                            isDragging = true;
                            indiceDrag = i;
                            offsetX = e.button.x - pieces[i].x;
                            offsetY = e.button.y - pieces[i].y;
                        }
                    }
                }
            }
            else if (e.type == SDL_MOUSEBUTTONUP)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    isDragging = false;
                }
            }
            else if (e.type == SDL_MOUSEMOTION)
            {
                if (isDragging)

                {

                    pieces[indiceDrag].x = e.motion.x - offsetX;
                    pieces[indiceDrag].y = e.motion.y - offsetY;
                }
            }
        }

        SDL_RenderPresent(rend);
        SDL_Delay(1000 / 60);
    }
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;
}