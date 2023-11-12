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

SDL_Rect pieces::getClip()
{
    return this->clip;
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

void pieces::ClipChanger(SDL_Rect r)
{
    this->clip = r;
}
void pieces::set_clips()
{
    switch (this->typePiece)
    {
    case 1:
        if (this->camp == "black")
        {
            this->clip.h = 170;
            this->clip.w = 170;
            this->clip.x = 1013;
            this->clip.y = 216;
        }
        else
        {
            this->clip.h = 170;
            this->clip.w = 170;
            this->clip.x = 1013;
            this->clip.y = 22;
        }
        break;
    case 2:
        if (this->camp == "black")
        {
            this->clip.h = 170;
            this->clip.w = 170;
            this->clip.x = 816;
            this->clip.y = 216;
        }
        else
        {
            this->clip.h = 170;
            this->clip.w = 170;
            this->clip.x = 816;
            this->clip.y = 22;
        }
        break;

    case 3:
        if (this->camp == "black")
        {
            this->clip.h = 170;
            this->clip.w = 170;
            this->clip.x = 618;
            this->clip.y = 216;
        }
        else
        {
            this->clip.h = 170;
            this->clip.w = 170;
            this->clip.x = 618;
            this->clip.y = 22;
        }
        break;

    case 4:
        if (this->camp == "black")
        {
            this->clip.h = 170;
            this->clip.w = 170;
            this->clip.x = 415;
            this->clip.y = 216;
        }
        else
        {
            this->clip.h = 170;
            this->clip.w = 170;
            this->clip.x = 415;
            this->clip.y = 16;
        }
        break;
    case 5:
        if (this->camp == "black")
        {
            this->clip.h = 177;
            this->clip.w = 170;
            this->clip.x = 212;
            this->clip.y = 216;
        }
        else
        {
            this->clip.h = 177;
            this->clip.w = 170;
            this->clip.x = 212;
            this->clip.y = 16;
        }
        break;
    case 6:
        if (this->camp == "black")
        {
            this->clip.h = 177;
            this->clip.w = 170;
            this->clip.x = 10;
            this->clip.y = 216;
        }
        else
        {
            this->clip.h = 177;
            this->clip.w = 170;
            this->clip.x = 10;
            this->clip.y = 16;
        }
        break;

    default:
        break;
    }
}