#ifndef GRID
#define GRID

#include <SDL2/SDL.h>
#include <tuple>
#include <iostream>
using namespace std;
#include <vector>
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

    tuple<bool, vector<tuple<int, int>>> CoCastle;
    vector<tuple<tuple<int, int>, tuple<int, int>>> posibleMoveRoiWhite, posibleMoveRoiBlack;

public:
    grid(SDL_Renderer *rend);
    ~grid();
    void showGrid(SDL_Renderer *rend);
    void resetGrid();
    void eventHolder(SDL_Event e, bool &quit);
    tuple<bool, string> checkMate();
    vector<tuple<tuple<int, int>, tuple<int, int>>> checkStopMate(pieces p, pieces tab[10][10], string camp, int a, int b, int x, int z);
    void moveRoi(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po);
    void posibleMove(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po);
    bool checkCaseMate(const int x, const int z, pieces p, pieces tab[10][10], string camp, int &xOfPieceWhoCheck, int &yOfPieceWhoCheck);
    void checkEnd(bool &quit);
    tuple<bool, vector<tuple<int, int>>> canCastle(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po);
    void performMove();
    void posibleMoveAttack(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po);
    void attackPion(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po);
    void attackRoi(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po);
    void changePion(int x, int y);

    pieces (*getTabGrid())[10];
    string getTurn();
    string getPlayerOneCamp();
    string getPlayerTwoCamp();

    void setTabGrid(pieces tab[10][10]);
    void setTurn(string s);
    void setPlayerOneCamp(string s);
    void setPlayerTwoCamp(string s);
    void setCheckMate(bool b);
};

#endif