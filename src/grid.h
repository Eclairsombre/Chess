#ifndef GRID
#define GRID

#include <SDL2/SDL.h>
#include <tuple>
#include "pieces.cpp"

class grid
{
private:
    SDL_Rect square;
    pieces tabGrid[10][10];
    vector<tuple<int, int>> posibility;

    bool isDragging = false;
    int offsetX, offsetY, indiceDragX, indiceDragY;
    bool checkmate = false;
    string winner = "", turn = "white", playerOneCamp, playerTwoCamp;

    tuple<int, int> posRoiWhite = {}, posRoiBlack = {};

public:
    grid(/* args */);
    ~grid();

    void showGrid(SDL_Renderer *rend);
    void resetGrid();
    void eventHolder(SDL_Event e, bool &quit);
    tuple<bool, string> checkMate();
};

#endif