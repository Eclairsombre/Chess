#ifndef BOT
#define BOT

#include <SDL2/SDL.h>
#include <tuple>
#include <vector>
#include <iostream>
using namespace std;
#include "grid.h"
#include "pieces.h"

class ChessBot
{

private:
    /* data */
    vector<tuple<tuple<int, int>, tuple<int, int>>> move;
    tuple<int, int>
        posRoi = {};

public:
    ChessBot(/* args */);
    ~ChessBot();
    void playAsSecondPlayer(grid &g);
    void checkAllPossibleMoves(grid &g, pieces tabGrid[10][10]);
    void makeMove(pieces tabGrid[10][10], tuple<int, int> move, tuple<int, int> destination);

    // int evaluatePosition(grid &g, pieces tabGrid[10][10]);
};

#endif