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

void pieces::setType(int i)
{
    this->typePiece = i;
}

int pieces::getType()
{
    return this->typePiece;
}

void pieces::setDirection(string s)
{
    this->direction = s;
}

string pieces::getDirection()
{
    return this->direction;
}

bool pieces::getMove()
{
    return this->asMove;
}

void pieces::setMove(bool b)
{
    this->asMove = true;
}

void pieces::setCamp(string s)
{
    this->camp = s;
}

string pieces::getCamp()
{
    return this->camp;
}