#include "pieces.h"

pieces::pieces(/* args */)
{
    this->asMove = false;
    this->empty = true;
    this->typePiece = 0;
    this->direction = "none";
    this->camp = "none";
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

void pieces::operator=(pieces p)
{
    this->rect = p.getPiece();
    this->clip = p.getClip();
    this->color = p.getColor();
    this->empty = p.getEmpty();
    this->typePiece = p.getType();
    this->direction = p.getDirection();
    this->asMove = p.getMove();
    this->camp = p.getCamp();
}

ostream &operator<<(ostream &out, pieces p)
{
    out << "rect: " << p.getPiece().x << " " << p.getPiece().y << " " << p.getPiece().w << " " << p.getPiece().h << endl;
    out << "clip: " << p.getClip().x << " " << p.getClip().y << " " << p.getClip().w << " " << p.getClip().h << endl;
    out << "color: " << p.getColor().r << " " << p.getColor().g << " " << p.getColor().b << " " << p.getColor().a << endl;
    out << "empty: " << p.getEmpty() << endl;
    out << "typePiece: " << p.getType() << endl;
    out << "direction: " << p.getDirection() << endl;
    out << "asMove: " << p.getMove() << endl;
    out << "camp: " << p.getCamp() << endl;
    return out;
}

int pieces::getValue()
{
    switch (this->typePiece)
    {
    case 1:
        return 1;
        break;
    case 2:
        return 5;
        break;
    case 3:
        return 3;
        break;
    case 4:
        return 3;
        break;
    case 5:
        return 9;
        break;
    case 6:
        return 1000;
        break;
    default:
        return 0;
        break;
    }
}

int pieces::getValuePosition(int x, int y)
{
    int value = 0;
    switch (this->typePiece)
    {
    case 1:
        if (this->camp == "white")
        {
            value = 10 + (y * 10);
        }
        else
        {
            value = 10 + ((7 - y) * 10);
        }
        break;
    case 2:
        if (this->camp == "white")
        {
            value = 50 + (y * 10);
        }
        else
        {
            value = 50 + ((7 - y) * 10);
        }
        break;
    case 3:
        if (this->camp == "white")
        {
            value = 30 + (y * 10);
        }
        else
        {
            value = 30 + ((7 - y) * 10);
        }
        break;
    case 4:
        if (this->camp == "white")
        {
            value = 30 + (y * 10);
        }
        else
        {
            value = 30 + ((7 - y) * 10);
        }
        break;
    case 5:
        if (this->camp == "white")
        {
            value = 90 + (y * 10);
        }
        else
        {
            value = 90 + ((7 - y) * 10);
        }
        break;
    case 6:
        if (this->camp == "white")
        {
            value = 900 + (y * 10);
        }
        else
        {
            value = 900 + ((7 - y) * 10);
        }
        break;

    default:
        break;
    }
    return value;
}