#include "grid.h"
#include <tuple>
#include <vector>
#include <iostream>
using namespace std;

grid::grid(/* args */)
{
    this->square = {100, 100, 100, 100};
}

grid::~grid()
{
}

void grid::resetGrid()
{
    SDL_Color color;
    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {

            if (y == 1 || y == 6)
            {
                if (y == 1)
                {
                    this->tabGrid[i][y].setDirection("Bas");
                    SDL_Color color = {255, 255, 255};
                    this->tabGrid[i][y].setColor(color);
                    this->tabGrid[i][y].setCamp("white");
                }
                else
                {
                    this->tabGrid[i][y].setDirection("Haut");
                    SDL_Color color = {0, 0, 0};
                    this->tabGrid[i][y].setColor(color);
                    this->tabGrid[i][y].setCamp("black");
                }

                SDL_Rect rect = {120 + i * 100, 120 + y * 100, 60, 60};

                this->tabGrid[i][y].setType(1);

                this->tabGrid[i][y].setPieces(rect);
                this->tabGrid[i][y].setEmpty(false);
            }
            else if (y == 0 || y == 7)
            {
                if (y == 0)
                {
                    this->tabGrid[i][y].setDirection("Bas");
                    SDL_Color color = {255, 255, 255};
                    this->tabGrid[i][y].setColor(color);
                    this->tabGrid[i][y].setCamp("white");
                }
                else
                {
                    this->tabGrid[i][y].setDirection("Haut");
                    SDL_Color color = {0, 0, 0};
                    this->tabGrid[i][y].setColor(color);
                    this->tabGrid[i][y].setCamp("black");
                }

                switch (i)
                {
                case 0:
                case 7:
                    this->tabGrid[i][y].setType(2);
                    break;
                case 1:
                case 6:
                    this->tabGrid[i][y].setType(3);
                    break;
                case 2:
                case 5:
                    this->tabGrid[i][y].setType(4);
                    break;
                case 3:
                    this->tabGrid[i][y].setType(5);
                    break;
                case 4:
                    this->tabGrid[i][y].setType(6);
                    break;

                default:
                    break;
                }
                SDL_Rect rect = {120 + i * 100, 120 + y * 100, 60, 60};

                this->tabGrid[i][y].setPieces(rect);
                this->tabGrid[i][y].setEmpty(false);
            }
            else
            {

                this->tabGrid[i][y].setEmpty(true);
            }
        }
    }
}

void grid::showGrid(SDL_Renderer *rend)
{
    for (int i = 1; i <= 8; i++)
    {
        for (int y = 1; y <= 8; y++)
        {
            this->square = {100 + 100 * (i - 1), 100 + 100 * (y - 1), 100, 100};
            if (i % 2 != 0)
            {
                if (y % 2 == 0)
                {
                    SDL_SetRenderDrawColor(rend, 0, 150, 0, 255);
                }
                else if (y % 2 != 0)
                {
                    SDL_SetRenderDrawColor(rend, 232, 220, 202, 255);
                }
            }
            else
            {
                if (y % 2 != 0)
                {
                    SDL_SetRenderDrawColor(rend, 0, 150, 0, 255);
                }
                else if (y % 2 == 0)
                {
                    SDL_SetRenderDrawColor(rend, 232, 220, 202, 255);
                }
            }
            SDL_RenderFillRect(rend, &this->square);
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {

            if (!this->tabGrid[i][y].getEmpty())
            {
                SDL_Color color = this->tabGrid[i][y].getColor();
                SDL_SetRenderDrawColor(rend, color.r, color.g, color.b, 255);

                SDL_Rect temp = this->tabGrid[i][y].getPiece();
                SDL_RenderFillRect(rend, &temp);
            }
        }
    }
}
bool CoordonneinTuple(int x, int y, vector<tuple<int, int>> &posibility)
{
    for (int i = 0; i < posibility.size(); i++)
    {
        if (get<0>(posibility[i]) == x && get<1>(posibility[i]) == y)
        {
            return true;
        }
    }
    return false;
}
void posibleMove(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &posibility)
{
    vector<tuple<int, int>> temp;
    posibility = temp;
    bool stop = false;
    SDL_Color black = {0, 0, 0};
    SDL_Color white = {255, 255, 255};
    switch (p.getType())
    {
    case 1:
        if (p.getDirection() == (string) "Haut")
        {
            if (p.getMove())
            {
                if (y - 1 >= 0 && tab[x][y - 1].getEmpty())
                {
                    posibility.push_back(make_tuple(x, y - 1));
                }
            }
            else
            {
                if (tab[x][y - 2].getEmpty())
                {
                    posibility.push_back(make_tuple(x, y - 2));
                }
                if (tab[x][y - 1].getEmpty())
                {
                    posibility.push_back(make_tuple(x, y - 1));
                }
            }
            if (x >= 1)
            {
                if (y - 1 >= 0 && !tab[x - 1][y - 1].getEmpty())
                {

                    if (tab[x][y].getCamp() == (string) "black")
                    {

                        if (tab[x - 1][y - 1].getCamp() == (string) "white")
                        {
                            posibility.push_back(make_tuple(x - 1, y - 1));
                        }
                    }
                    else
                    {
                        if (tab[x - 1][y - 1].getCamp() == (string) "black")
                        {
                            posibility.push_back(make_tuple(x - 1, y - 1));
                        }
                    }
                }
            }
            if (x <= 6)
            {
                if (y - 1 >= 0 && !tab[x + 1][y - 1].getEmpty())
                {
                    if (tab[x][y].getCamp() == (string) "black")
                    {
                        if (tab[x + 1][y - 1].getCamp() == (string) "white")
                        {
                            posibility.push_back(make_tuple(x + 1, y - 1));
                        }
                    }
                    else
                    {
                        if (tab[x + 1][y - 1].getCamp() == (string) "black")
                        {
                            posibility.push_back(make_tuple(x + 1, y - 1));
                        }
                    }
                }
            }
        }

        else
        {
            if (p.getMove())
            {
                if (y + 1 <= 7 && tab[x][y + 1].getEmpty())
                {
                    posibility.push_back(make_tuple(x, y + 1));
                }
            }
            else
            {
                if (tab[x][y + 2].getEmpty())
                {
                    posibility.push_back(make_tuple(x, y + 1));
                }
                if (tab[x][y + 1].getEmpty())
                {
                    posibility.push_back(make_tuple(x, y + 2));
                }
            }
            if (x >= 1)
            {
                if (y + 1 <= 7 && !tab[x - 1][y + 1].getEmpty())
                {
                    if (tab[x][y].getCamp() == (string) "black")
                    {
                        if (tab[x - 1][y + 1].getCamp() == (string) "white")
                        {
                            posibility.push_back(make_tuple(x - 1, y + 1));
                        }
                    }
                    else
                    {
                        if (tab[x + 1][y + 1].getCamp() == (string) "black")
                        {
                            posibility.push_back(make_tuple(x + 1, y + 1));
                        }
                    }
                }
                if (x <= 6)
                {
                    if (y + 1 <= 7 && !tab[x + 1][y + 1].getEmpty())
                    {
                        if (tab[x][y].getCamp() == (string) "black")
                        {
                            if (tab[x + 1][y + 1].getCamp() == (string) "white")
                            {
                                posibility.push_back(make_tuple(x + 1, y + 1));
                            }
                        }
                        else
                        {
                            if (tab[x + 1][y + 1].getCamp() == (string) "black")
                            {
                                posibility.push_back(make_tuple(x + 1, y + 1));
                            }
                        }
                    }
                }
            }
        }
        break;
    case 2:

        for (int i = x + 1; i < 8; i++)
        {

            if (tab[i][y].getEmpty())
            {

                if (!stop)
                {
                    posibility.push_back(make_tuple(i, y));
                }
            }
            else
            {
                if (!stop)
                {
                    if (tab[x][y].getCamp() == (string) "black")
                    {
                        if (tab[i][y].getCamp() == (string) "white")
                        {
                            posibility.push_back(make_tuple(i, y));
                        }
                    }
                    else
                    {
                        if (tab[i][y].getCamp() == (string) "black")
                        {
                            posibility.push_back(make_tuple(i, y));
                        }
                    }
                }
                stop = true;
            }
        }
        stop = false;

        for (int i = x - 1; i >= 0; i--)
        {
            if (tab[i][y].getEmpty())
            {

                if (!stop)
                {

                    posibility.push_back(make_tuple(i, y));
                }
            }
            else
            {
                if (!stop)
                {
                    if (tab[x][y].getCamp() == (string) "black")
                    {
                        if (tab[i][y].getCamp() == (string) "white")
                        {
                            posibility.push_back(make_tuple(i, y));
                        }
                    }
                    else
                    {
                        if (tab[i][y].getCamp() == (string) "black")
                        {
                            posibility.push_back(make_tuple(i, y));
                        }
                    }
                }
                stop = true;
            }
        }
        stop = false;

        for (int i = y + 1; i < 8; i++)
        {
            if (tab[x][i].getEmpty())
            {

                if (!stop)
                {
                    posibility.push_back(make_tuple(x, i));
                }
            }
            else
            {
                if (!stop)
                {
                    if (tab[x][y].getCamp() == (string) "black")
                    {
                        if (tab[x][i].getCamp() == (string) "white")
                        {
                            posibility.push_back(make_tuple(x, i));
                        }
                    }
                    else
                    {
                        if (tab[x][i].getCamp() == (string) "black")
                        {
                            posibility.push_back(make_tuple(x, i));
                        }
                    }
                }
                stop = true;
            }
        }
        stop = false;
        for (int i = y - 1; i >= 0; i--)
        {
            if (tab[x][i].getEmpty())
            {

                if (!stop)
                {

                    posibility.push_back(make_tuple(x, i));
                }
            }
            else
            {
                if (!stop)
                {
                    if (tab[x][y].getCamp() == (string) "black")
                    {
                        if (tab[x][i].getCamp() == (string) "white")
                        {
                            posibility.push_back(make_tuple(x, i));
                        }
                    }
                    else
                    {
                        if (tab[x][i].getCamp() == (string) "black")
                        {
                            posibility.push_back(make_tuple(x, i));
                        }
                    }
                }
                stop = true;
            }
        }

    default:
        break;
    }
}

void grid::eventHolder(SDL_Event e, bool &quit)
{
    while (SDL_PollEvent(&e))
    {

        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            if (e.button.button == SDL_BUTTON_LEFT)
            {
                for (int i = 0; i < 8; i++)
                {
                    for (int y = 0; y < 8; y++)
                    {
                        if (e.button.x >= this->tabGrid[i][y].getPiece().x && e.button.x <= this->tabGrid[i][y].getPiece().x + this->tabGrid[i][y].getPiece().w && e.button.y >= this->tabGrid[i][y].getPiece().y && e.button.y <= this->tabGrid[i][y].getPiece().y + this->tabGrid[i][y].getPiece().h)
                        {

                            this->isDragging = true;

                            indiceDragX = i;
                            indiceDragY = y;
                            posibleMove(i, y, this->tabGrid[i][y], this->tabGrid, posibility);
                            cout << "Move : " << endl;
                            for (int i = 0; i < posibility.size(); i++)
                            {
                                cout << get<0>(posibility[i]) << " " << get<1>(posibility[i]) << endl;
                            }
                            this->offsetX = e.button.x - this->tabGrid[i][y].getPiece().x;
                            this->offsetY = e.button.y - this->tabGrid[i][y].getPiece().y;
                        }
                    }
                }
            }
        }
        else if (e.type == SDL_MOUSEBUTTONUP)
        {
            if (e.button.button == SDL_BUTTON_LEFT && this->isDragging)
            {
                this->isDragging = false;
                SDL_Rect temp, rect = tabGrid[this->indiceDragX][this->indiceDragY].getPiece();
                if (CoordonneinTuple(rect.x / 100 - 1, rect.y / 100 - 1, this->posibility))
                {

                    rect = {120 + ((rect.x / 100) - 1) * 100, 120 + ((rect.y / 100) - 1) * 100, 60, 60};

                    this->tabGrid[this->indiceDragX][this->indiceDragY].setPieces(temp);
                    this->tabGrid[this->indiceDragX][this->indiceDragY].setEmpty(true);

                    this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].setColor(this->tabGrid[this->indiceDragX][this->indiceDragY].getColor());
                    this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].setPieces(rect);
                    this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].setEmpty(false);
                    this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].setType(this->tabGrid[this->indiceDragX][this->indiceDragY].getType());
                    this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].setDirection(this->tabGrid[this->indiceDragX][this->indiceDragY].getDirection());
                    this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].setMove(true);
                    this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].setCamp(this->tabGrid[this->indiceDragX][this->indiceDragY].getCamp());

                    this->tabGrid[this->indiceDragX][this->indiceDragY].setType(0);
                    this->tabGrid[this->indiceDragX][this->indiceDragY].setCamp("");
                }
                else
                {
                    rect = {120 + this->indiceDragX * 100, 120 + this->indiceDragY * 100, 60, 60};
                    this->tabGrid[this->indiceDragX][this->indiceDragY].setPieces(rect);
                }
            }
        }
        else if (e.type == SDL_MOUSEMOTION)
        {
            if (this->isDragging)

            {
                SDL_Rect temp = {e.motion.x - this->offsetX, e.motion.y - this->offsetY, 60, 60};
                this->tabGrid[this->indiceDragX][this->indiceDragY].setPieces(temp);
            }
        }
    }
}
