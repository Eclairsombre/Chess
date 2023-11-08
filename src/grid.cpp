#include "grid.h"

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
                }
                else
                {
                    this->tabGrid[i][y].setDirection("Haut");
                    SDL_Color color = {0, 0, 0};
                    this->tabGrid[i][y].setColor(color);
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
                }
                else
                {
                    this->tabGrid[i][y].setDirection("Haut");
                    SDL_Color color = {0, 0, 0};
                    this->tabGrid[i][y].setColor(color);
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

bool testMove(int x, int y, int a, int b, pieces p)
{
    if (p.getDirection() == (string) "Haut")
    {
        cout << 1 << endl;
        switch (p.getType())
        {
        case 1:
            return (b == y - 1);
            break;

        default:
            break;
        }
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
                if (testMove(this->indiceDragX, this->indiceDragY, ((rect.x / 100) - 1), ((rect.y / 100) - 1), tabGrid[this->indiceDragX][this->indiceDragY]))
                {
                    rect = {120 + ((rect.x / 100) - 1) * 100, 120 + ((rect.y / 100) - 1) * 100, 60, 60};

                    this->tabGrid[this->indiceDragX][this->indiceDragY].setPieces(temp);
                    this->tabGrid[this->indiceDragX][this->indiceDragY].setEmpty(true);

                    this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].setColor(this->tabGrid[this->indiceDragX][this->indiceDragY].getColor());
                    this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].setPieces(rect);
                    this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].setEmpty(false);
                    this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].setType(this->tabGrid[this->indiceDragX][this->indiceDragY].getType());
                    this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].setDirection(this->tabGrid[this->indiceDragX][this->indiceDragY].getDirection());

                    this->tabGrid[this->indiceDragX][this->indiceDragY].setType(0);
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
