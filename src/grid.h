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
    vector<tuple<int, int>> posibility, check;
    SDL_Texture *image;
    bool isDragging = false;
    int offsetX, offsetY, indiceDragX, indiceDragY;
    bool checkmate = false;
    string winner = "", turn = "white", playerOneCamp, playerTwoCamp;
    vector<tuple<int, int>> move;
    tuple<int, int>
        posRoiWhite = {},
        posRoiBlack = {};

public:
    grid(SDL_Renderer *rend);
    ~grid();

    void showGrid(SDL_Renderer *rend);
    void resetGrid();
    void eventHolder(SDL_Event e, bool &quit);
    tuple<bool, string> checkMate();
    bool checkStopMate(pieces p, pieces tab[10][10], string camp, int a, int b, int x, int z);
    void moveRoi(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po);
    void posibleMove(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &posibility);
    bool checkCaseMate(const int x, const int z, pieces p, pieces tab[10][10], string camp, int &a, int &b);
    void checkEnd(bool &quit);
};

#endif