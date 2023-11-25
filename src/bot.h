#ifndef BOT
#define BOT

#include <SDL2/SDL.h>
#include <tuple>
#include <iostream>
using namespace std;
#include "grid.h"
#include "pieces.h"

class ChessBot
{

private:
    /* data */

public:
    void playAsSecondPlayer(grid &g);
    void makeMove(pieces tabGrid[10][10], tuple<int, int> move, tuple<int, int> destination);
};

#endif