#ifndef GRID
#define GRID

#include <SDL2/SDL.h>
#include "pieces.cpp"

class grid
{
private:
    SDL_Rect square;
    pieces tabGrid[10][10];
    vector<tuple<int, int>> posibility;
    bool whiteRound = true;
    bool isDragging = false;
    int offsetX, offsetY, indiceDragX, indiceDragY;

public:
    grid(/* args */);
    ~grid();

    void showGrid(SDL_Renderer *rend);
    void resetGrid();
    void eventHolder(SDL_Event e, bool &quit);
};

#endif