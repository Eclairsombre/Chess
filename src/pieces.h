#ifndef PIECES
#define PIECES

#include <SDL2/SDL.h>

class pieces
{
private:
    bool empty = false;
    SDL_Rect rect;
    SDL_Color color;

public:
    pieces(/* args */);
    ~pieces();
    void setPieces(SDL_Rect r);
    void setEmpty(bool s);
    bool getEmpty();
    SDL_Rect getPiece();
    void setColor(SDL_Color c);
    SDL_Color getColor();
};

#endif