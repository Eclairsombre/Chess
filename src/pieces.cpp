#include "pieces.h"

pieces::pieces(/* args */)
{
}

pieces::~pieces()
{
}

void pieces::setPieces(SDL_Rect r)
{
    this->rect = r;
}

void pieces::setEmpty(bool s)
{
    this->empty = s;
}

bool pieces::getEmpty()
{
    return this->empty;
}

SDL_Rect pieces::getPiece()
{
    return this->rect;
}

void pieces::setColor(SDL_Color c)
{
    this->color = c;
}

SDL_Color pieces::getColor()
{
    return this->color;
}