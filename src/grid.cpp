#include "grid.h"

grid::grid(/* args */)
{
    this->square = {100, 100, 100, 100};
}

grid::~grid()
{
}

void grid::showGrid(SDL_Renderer *rend)
{
    for (int i = 1; i <= 8; i++)
    {
        for (int y = 1; y <= 8; y++)
        {
            this->square = {100 + 100 * (i - 1), 100 + 100 * (y - 1), 100, 100};
            if (i % 2 != 0)
            {
                if (y % 2 == 0)
                {
                    SDL_SetRenderDrawColor(rend, 0, 150, 0, 255);
                }
                else if (y % 2 != 0)
                {
                    SDL_SetRenderDrawColor(rend, 232, 220, 202, 255);
                }
            }
            else
            {
                if (y % 2 != 0)
                {
                    SDL_SetRenderDrawColor(rend, 0, 150, 0, 255);
                }
                else if (y % 2 == 0)
                {
                    SDL_SetRenderDrawColor(rend, 232, 220, 202, 255);
                }
            }
            SDL_RenderFillRect(rend, &this->square);
        }
    }
}