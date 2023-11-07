#ifndef GRID
#define GRID

#include <SDL2/SDL.h>

class grid
{
private:
    SDL_Rect square;

public:
    grid(/* args */);
    ~grid();

    void showGrid(SDL_Renderer *rend);
};

#endif