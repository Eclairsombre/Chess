#ifndef PIECES
#define PIECES

#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

class pieces
{
private:
    bool empty = false, asMove = false;
    SDL_Rect rect, clip;
    SDL_Color color;
    int typePiece = 0, x, y;
    string direction, camp;

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
    bool getMove();
    void setMove(bool b);
    void setCamp(string s);
    string getCamp();
    void set_clips();
    SDL_Rect getClip();
    void ClipChanger(SDL_Rect r);

    int getValue();
    int getValuePosition(int x, int y);

    void operator=(pieces p);
    friend ostream &operator<<(ostream &out, pieces p);
};

#endif