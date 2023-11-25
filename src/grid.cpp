#include "grid.h"
#include <tuple>
#include <vector>
#include <iostream>
using namespace std;
#include "movePieces.cpp"
#include "attackPieces.cpp"
#include "SDL2/SDL_image.h"

grid::grid(SDL_Renderer *rend)
{
    this->square = {100, 100, 100, 100};
    SDL_Surface *imageSurface = IMG_Load("./pictures/sprites.png");
    this->image = SDL_CreateTextureFromSurface(rend, imageSurface);
    SDL_FreeSurface(imageSurface);
}

grid::~grid()
{
}

void grid::resetGrid()
{
    SDL_Color color;
    int chooseCamp = rand() % 2;

    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {

            if (y == 1 || y == 6)
            {
                if (y == 1)
                {
                    this->tabGrid[i][y].setDirection("Bas");
                    switch (chooseCamp)
                    {
                    case 0:
                        color = {255, 255, 255};
                        this->tabGrid[i][y].setColor(color);
                        this->tabGrid[i][y].setCamp("white");
                        playerTwoCamp = "white";
                        break;
                    case 1:
                        color = {0, 0, 0};
                        this->tabGrid[i][y].setColor(color);
                        this->tabGrid[i][y].setCamp("black");
                        playerTwoCamp = "black";
                    default:
                        break;
                    }
                }
                else
                {
                    this->tabGrid[i][y].setDirection("Haut");
                    switch (chooseCamp)
                    {
                    case 1:
                        color = {255, 255, 255};
                        this->tabGrid[i][y].setColor(color);
                        this->tabGrid[i][y].setCamp("white");
                        playerOneCamp = "white";
                        break;
                    case 0:
                        color = {0, 0, 0};
                        this->tabGrid[i][y].setColor(color);
                        this->tabGrid[i][y].setCamp("black");
                        playerOneCamp = "black";
                    default:
                        break;
                    }
                }

                SDL_Rect rect = {115 + i * 100, 115 + y * 100, 65, 65};

                this->tabGrid[i][y].setType(1);

                this->tabGrid[i][y].setPieces(rect);
                this->tabGrid[i][y].setEmpty(false);
            }
            else if (y == 0 || y == 7)
            {
                if (y == 0)
                {
                    this->tabGrid[i][y].setDirection("Bas");

                    switch (chooseCamp)
                    {
                    case 0:
                        color = {255, 255, 255};
                        this->tabGrid[i][y].setColor(color);
                        this->tabGrid[i][y].setCamp("white");
                        break;
                    case 1:
                        color = {0, 0, 0};
                        this->tabGrid[i][y].setColor(color);
                        this->tabGrid[i][y].setCamp("black");
                    default:
                        break;
                    }
                }
                else
                {
                    this->tabGrid[i][y].setDirection("Haut");

                    switch (chooseCamp)
                    {
                    case 1:
                        color = {255, 255, 255};
                        this->tabGrid[i][y].setColor(color);
                        this->tabGrid[i][y].setCamp("white");
                        break;
                    case 0:
                        color = {0, 0, 0};
                        this->tabGrid[i][y].setColor(color);
                        this->tabGrid[i][y].setCamp("black");
                    default:
                        break;
                    }
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
                    if (tabGrid[i][y].getCamp() == "black")
                    {
                        this->posRoiBlack = make_tuple(i, y);
                    }
                    else
                    {
                        this->posRoiWhite = make_tuple(i, y);
                    }
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
            this->tabGrid[i][y].set_clips();
        }
    }
}

void grid::showGrid(SDL_Renderer *rend)
{
    int a, b;
    for (int i = 1; i <= 8; i++)
    {
        for (int y = 1; y <= 8; y++)
        {
            this->square = {100 + 100 * (i - 1), 100 + 100 * (y - 1), 100, 100};

            if (CoordonneinTuple(i - 1, y - 1, this->posibility))
            {
                SDL_SetRenderDrawColor(rend, 255, 255, 0, 255);
            }
            else
            {
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
                // SDL_SetRenderDrawColor(rend, color.r, color.g, color.b, 255);
                SDL_Rect temp = this->tabGrid[i][y].getPiece(), temp2 = this->tabGrid[i][y].getClip();

                // SDL_RenderFillRect(rend, &temp);
                SDL_RenderCopy(rend, this->image, &temp2, &temp);
            }
        }
    }
}

void grid::eventHolder(SDL_Event e, bool &quit)
{

    while (SDL_PollEvent(&e))
    {
        int a, b;

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
                            if ((this->turn == "black" && this->tabGrid[i][y].getCamp() == "black") || (this->turn == "white" && this->tabGrid[i][y].getCamp() == "white"))

                            {

                                this->isDragging = true;

                                this->indiceDragX = i;
                                this->indiceDragY = y;

                                this->posibleMove(this->indiceDragX, this->indiceDragY, this->tabGrid[i][y], this->tabGrid, this->posibility);

                                if (checkCaseMate(get<0>(this->posRoiBlack), get<1>(this->posRoiBlack), tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)], tabGrid, tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)].getCamp(), a, b))
                                {
                                    vector<tuple<int, int>> v;

                                    if (i == get<0>(this->posRoiBlack) && y == get<1>(this->posRoiBlack))
                                    {
                                        this->posibleMove(get<0>(this->posRoiBlack), get<1>(this->posRoiBlack), this->tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)], this->tabGrid, v);
                                        this->posibility = v;
                                        for (int z = 0; z < this->posibility.size(); z++)
                                        {
                                            if (checkCaseMate(get<0>(this->posibility[z]), get<1>(this->posibility[z]), this->tabGrid[get<0>(this->posibility[z])][get<1>(this->posibility[z])], this->tabGrid, this->tabGrid[get<0>(this->posibility[z])][get<1>(this->posibility[z])].getCamp(), a, b))
                                            {
                                                this->posibility.erase(this->posibility.begin() + z);
                                            }
                                        }
                                    }

                                    else
                                    {
                                        this->posibility = v;
                                        this->posibleMoveRoiBlack = this->checkStopMate(this->tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)], this->tabGrid, this->tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)].getCamp(), a, b, get<0>(this->posRoiBlack), get<1>(this->posRoiBlack));
                                        for (int z = 0; z < this->posibleMoveRoiBlack.size(); z++)
                                        {
                                            if (get<0>(this->posibleMoveRoiBlack[z]) == make_tuple(i, y))
                                            {
                                                this->posibility.push_back(get<1>(this->posibleMoveRoiBlack[z]));
                                            }
                                        }
                                    }
                                }
                                else if (checkCaseMate(get<0>(this->posRoiWhite), get<1>(this->posRoiWhite), tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)], tabGrid, tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)].getCamp(), a, b))
                                {
                                    vector<tuple<int, int>> v;

                                    if (i == get<0>(this->posRoiWhite) && y == get<1>(this->posRoiWhite))
                                    {
                                        this->posibleMove(get<0>(this->posRoiWhite), get<1>(this->posRoiWhite), this->tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)], this->tabGrid, v);
                                        this->posibility = v;
                                    }
                                    else
                                    {
                                        this->posibleMoveRoiWhite = this->checkStopMate(this->tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)], this->tabGrid, this->tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)].getCamp(), a, b, get<0>(this->posRoiWhite), get<1>(this->posRoiWhite));
                                        for (int z = 0; z < this->posibleMoveRoiWhite.size(); z++)
                                        {
                                            if (get<0>(this->posibleMoveRoiWhite[z]) == make_tuple(i, y))
                                            {
                                                this->posibility.push_back(get<1>(this->posibleMoveRoiWhite[z]));
                                            }
                                        }
                                    }
                                }

                                if (this->tabGrid[this->indiceDragX][this->indiceDragY].getType() == 6)
                                {
                                    this->CoCastle = this->canCastle(this->indiceDragX, this->indiceDragY, this->tabGrid[this->indiceDragX][this->indiceDragY], this->tabGrid, this->posibility);
                                }
                                cout << "Move : " << endl;
                                for (int i = 0; i < posibility.size(); i++)
                                {
                                    cout << get<0>(posibility[i]) << " " << get<1>(posibility[i]) << endl;
                                }
                                cout << endl;
                                cout << endl;
                                cout << endl;
                                cout << endl;

                                this->offsetX = e.button.x - this->tabGrid[i][y].getPiece().x;
                                this->offsetY = e.button.y - this->tabGrid[i][y].getPiece().y;
                            }
                        }
                    }
                }
            }
        }
        else if (e.type == SDL_MOUSEBUTTONUP)
        {
            SDL_Rect rect;
            if (e.button.button == SDL_BUTTON_LEFT && this->isDragging)
            {

                if (this->tabGrid[this->indiceDragX][this->indiceDragY].getType() == 6)
                {

                    if (tabGrid[this->indiceDragX][this->indiceDragY].getCamp() == "black")
                    {
                        this->posRoiBlack = make_tuple(e.button.x / 100 - 1, e.button.y / 100 - 1);
                    }
                    else
                    {
                        this->posRoiWhite = make_tuple(e.button.x / 100 - 1, e.button.y / 100 - 1);
                    }
                }

                this->isDragging = false;

                if (this->checkCaseMate(get<0>(this->posRoiWhite), get<1>(this->posRoiWhite), this->tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)], this->tabGrid, this->tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)].getCamp(), a, b))
                {

                    this->posibleMoveRoiWhite = this->checkStopMate(this->tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)], this->tabGrid, this->tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)].getCamp(), a, b, get<0>(this->posRoiWhite), get<1>(this->posRoiWhite));
                    this->moveRoi(get<0>(this->posRoiWhite), get<1>(this->posRoiWhite), this->tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)], this->tabGrid, this->posibility);
                    for (int i = 0; i < this->posibility.size(); i++)
                    {
                        if (CoordonneinTuple(e.button.x / 100 - 1, e.button.y / 100 - 1, this->posibility))
                        {
                            this->performMove();
                            break;
                        }
                        else
                        {

                            rect = {120 + this->indiceDragX * 100, 120 + this->indiceDragY * 100, 60, 60};
                            this->tabGrid[this->indiceDragX][this->indiceDragY].setPieces(rect);
                        }
                    }
                    for (int i = 0; i < this->posibleMoveRoiWhite.size(); i++)
                    {
                        if (get<0>(this->posibleMoveRoiWhite[i]) == make_tuple(this->indiceDragX, this->indiceDragY) && get<1>(this->posibleMoveRoiWhite[i]) == make_tuple(e.button.x / 100 - 1, e.button.y / 100 - 1))
                        {
                            this->performMove();
                            break;
                        }
                        else
                        {

                            rect = {120 + this->indiceDragX * 100, 120 + this->indiceDragY * 100, 60, 60};
                            this->tabGrid[this->indiceDragX][this->indiceDragY].setPieces(rect);
                        }
                    }
                }

                else if (this->checkCaseMate(get<0>(this->posRoiBlack), get<1>(this->posRoiBlack), this->tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)], this->tabGrid, this->tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)].getCamp(), a, b))
                {

                    this->posibleMoveRoiBlack = this->checkStopMate(this->tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)], this->tabGrid, this->tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)].getCamp(), a, b, get<0>(this->posRoiBlack), get<1>(this->posRoiBlack));
                    if (indiceDragX == get<0>(this->posRoiBlack) && indiceDragY == get<1>(this->posRoiBlack))
                    {
                        this->moveRoi(get<0>(this->posRoiBlack), get<1>(this->posRoiBlack), this->tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)], this->tabGrid, this->posibility);

                        for (int i = 0; i < this->posibility.size(); i++)
                        {
                            if (CoordonneinTuple(e.button.x / 100 - 1, e.button.y / 100 - 1, this->posibility))
                            {
                                this->performMove();
                                break;
                            }
                            else
                            {

                                rect = {120 + this->indiceDragX * 100, 120 + this->indiceDragY * 100, 60, 60};
                                this->tabGrid[this->indiceDragX][this->indiceDragY].setPieces(rect);
                            }
                        }
                    }

                    for (int i = 0; i < this->posibleMoveRoiBlack.size(); i++)
                    {
                        if (get<0>(this->posibleMoveRoiBlack[i]) == make_tuple(this->indiceDragX, this->indiceDragY) && get<1>(this->posibleMoveRoiBlack[i]) == make_tuple(e.button.x / 100 - 1, e.button.y / 100 - 1))
                        {
                            this->performMove();
                            break;
                        }
                        else
                        {

                            rect = {120 + this->indiceDragX * 100, 120 + this->indiceDragY * 100, 60, 60};
                            this->tabGrid[this->indiceDragX][this->indiceDragY].setPieces(rect);
                        }
                    }
                }

                else
                {

                    if (tabGrid[this->indiceDragX][this->indiceDragY].getType() != 6)
                    {
                        this->tabGrid[this->indiceDragX][this->indiceDragY].setEmpty(true);
                        if (this->tabGrid[this->indiceDragX][this->indiceDragY].getCamp() == "black")
                        {
                            if (!this->checkCaseMate(get<0>(this->posRoiBlack), get<1>(this->posRoiBlack), this->tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)], this->tabGrid, this->tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)].getCamp(), a, b))
                            {

                                this->tabGrid[this->indiceDragX][this->indiceDragY].setEmpty(false);

                                this->performMove();
                            }
                            else
                            {

                                this->tabGrid[this->indiceDragX][this->indiceDragY].setEmpty(false);
                                rect = {120 + this->indiceDragX * 100, 120 + this->indiceDragY * 100, 60, 60};
                                this->tabGrid[this->indiceDragX][this->indiceDragY].setPieces(rect);
                            }
                        }
                        else
                        {
                            if (!this->checkCaseMate(get<0>(this->posRoiWhite), get<1>(this->posRoiWhite), this->tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)], this->tabGrid, this->tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)].getCamp(), a, b))
                            {

                                this->tabGrid[this->indiceDragX][this->indiceDragY].setEmpty(false);

                                this->performMove();
                            }
                            else
                            {

                                this->tabGrid[this->indiceDragX][this->indiceDragY].setEmpty(false);
                                rect = {120 + this->indiceDragX * 100, 120 + this->indiceDragY * 100, 60, 60};
                                this->tabGrid[this->indiceDragX][this->indiceDragY].setPieces(rect);
                            }
                        }
                    }
                    else if (tabGrid[this->indiceDragX][this->indiceDragY].getType() == 6)
                    {
                        if (!this->checkCaseMate((e.button.x / 100) - 1, (e.button.y / 100) - 1, this->tabGrid[(e.button.x / 100) - 1][(e.button.y / 100) - 1], this->tabGrid, this->tabGrid[this->indiceDragX][this->indiceDragY].getCamp(), a, b))
                        {

                            this->performMove();
                        }
                        else
                        {

                            rect = {120 + this->indiceDragX * 100, 120 + this->indiceDragY * 100, 60, 60};
                            this->tabGrid[this->indiceDragX][this->indiceDragY].setPieces(rect);
                        }
                    }
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
