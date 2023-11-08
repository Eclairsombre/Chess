#ifndef PIECES
#define PIECES

#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

class pieces
{
private:
    bool empty = false;
    SDL_Rect rect;
    SDL_Color color;
    int typePiece = 0, x, y;
    string direction;

    /*
    0=vide
    1=pion
    2=tour
    3=cavalier
    4=fou
    5=reine
    6=roi
    */

public:
    pieces(/* args */);
    ~pieces();
    void setPieces(SDL_Rect r);
    void setEmpty(bool s);
    bool getEmpty();
    SDL_Rect getPiece();
    void setColor(SDL_Color c);
    SDL_Color getColor();
    void setType(int i);
    int getType();
    void setDirection(string s);
    string getDirection();
};

#endif