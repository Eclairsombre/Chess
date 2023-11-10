#include "grid.h"
#include <tuple>
#include <vector>
#include <iostream>
using namespace std;

void movePion(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &posibility)
{
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
}

void moveTour(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &posibility)
{
    bool stop = false;
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
}

void moveCavalier(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &posibility)
{
    if (y - 1 >= 0)
    {
        if (x + 2 <= 7)
        {
            if (tab[x + 2][y - 1].getEmpty())
            {
                posibility.push_back(make_tuple(x + 2, y - 1));
            }
            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x + 2][y - 1].getCamp() == (string) "white")
                    {
                        posibility.push_back(make_tuple(x + 2, y - 1));
                    }
                }
                else
                {
                    if (tab[x + 2][y - 1].getCamp() == (string) "black")
                    {
                        posibility.push_back(make_tuple(x + 2, y - 1));
                    }
                }
            }
        }
        if (x - 2 >= 0)
        {
            if (tab[x - 2][y - 1].getEmpty())
            {
                posibility.push_back(make_tuple(x - 2, y - 1));
            }

            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x - 2][y - 1].getCamp() == (string) "white")
                    {
                        posibility.push_back(make_tuple(x - 2, y - 1));
                    }
                }
                else
                {
                    if (tab[x - 2][y - 1].getCamp() == (string) "black")
                    {
                        posibility.push_back(make_tuple(x - 2, y - 1));
                    }
                }
            }
        }
    }

    if (y - 2 >= 0)
    {
        if (x + 1 <= 7)
        {
            if (tab[x + 1][y - 2].getEmpty())
            {
                posibility.push_back(make_tuple(x + 1, y - 2));
            }
            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x + 1][y - 2].getCamp() == (string) "white")
                    {
                        posibility.push_back(make_tuple(x + 1, y - 2));
                    }
                }
                else
                {
                    if (tab[x + 1][y - 2].getCamp() == (string) "black")
                    {
                        posibility.push_back(make_tuple(x + 1, y - 2));
                    }
                }
            }
        }
        if (x - 1 >= 0)
        {
            if (tab[x - 1][y - 2].getEmpty())
            {
                posibility.push_back(make_tuple(x - 1, y - 2));
            }

            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x - 1][y - 2].getCamp() == (string) "white")
                    {
                        posibility.push_back(make_tuple(x - 1, y - 2));
                    }
                }
                else
                {
                    if (tab[x - 1][y - 2].getCamp() == (string) "black")
                    {
                        posibility.push_back(make_tuple(x - 1, y - 2));
                    }
                }
            }
        }
    }
    if (y + 2 <= 7)
    {
        if (x + 1 <= 7)
        {
            if (tab[x + 1][y + 2].getEmpty())
            {
                posibility.push_back(make_tuple(x + 1, y + 2));
            }
            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x + 1][y + 2].getCamp() == (string) "white")
                    {
                        posibility.push_back(make_tuple(x + 1, y + 2));
                    }
                }
                else
                {
                    if (tab[x + 1][y + 2].getCamp() == (string) "black")
                    {
                        posibility.push_back(make_tuple(x + 1, y + 2));
                    }
                }
            }
        }
        if (x - 1 >= 0)
        {
            if (tab[x - 1][y + 2].getEmpty())
            {
                posibility.push_back(make_tuple(x - 1, y + 2));
            }

            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x - 1][y + 2].getCamp() == (string) "white")
                    {
                        posibility.push_back(make_tuple(x - 1, y + 2));
                    }
                }
                else
                {
                    if (tab[x - 1][y + 2].getCamp() == (string) "black")
                    {
                        posibility.push_back(make_tuple(x - 1, y + 2));
                    }
                }
            }
        }
    }

    if (y + 1 <= 7)
    {
        if (x + 2 <= 7)
        {
            if (tab[x + 2][y + 1].getEmpty())
            {
                posibility.push_back(make_tuple(x + 2, y + 1));
            }
            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x + 2][y + 1].getCamp() == (string) "white")
                    {
                        posibility.push_back(make_tuple(x + 2, y + 1));
                    }
                }
                else
                {
                    if (tab[x + 2][y + 1].getCamp() == (string) "black")
                    {
                        posibility.push_back(make_tuple(x + 2, y + 1));
                    }
                }
            }
        }
        if (x - 2 >= 0)
        {
            if (tab[x - 2][y + 1].getEmpty())
            {
                posibility.push_back(make_tuple(x - 2, y + 1));
            }

            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x - 2][y + 1].getCamp() == (string) "white")
                    {
                        posibility.push_back(make_tuple(x - 2, y + 1));
                    }
                }
                else
                {
                    if (tab[x - 2][y + 1].getCamp() == (string) "black")
                    {
                        posibility.push_back(make_tuple(x - 2, y + 1));
                    }
                }
            }
        }
    }
}

void moveFou(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &posibility)
{
    bool stopH = false, stopB = false;
    int temp = 1;
    if (x + 1 <= 7)
    {

        for (int i = x + 1; i < 8; i++)
        {

            if (y + temp <= 7)
            {
                if (tab[i][y + temp].getEmpty())
                {

                    if (!stopB)
                    {
                        posibility.push_back(make_tuple(i, y + temp));
                    }
                }
                else
                {
                    if (!stopB)
                    {
                        if (tab[x][y].getCamp() == (string) "black")
                        {
                            if (tab[i][y + temp].getCamp() == (string) "white")
                            {
                                posibility.push_back(make_tuple(i, y + temp));
                            }
                        }
                        else
                        {
                            if (tab[i][y + temp].getCamp() == (string) "black")
                            {
                                posibility.push_back(make_tuple(i, y + temp));
                            }
                        }
                    }
                    stopB = true;
                }
            }
            if (y - temp >= 0)
            {
                if (tab[i][y - temp].getEmpty())
                {

                    if (!stopH)
                    {

                        posibility.push_back(make_tuple(i, y - temp));
                    }
                }
                else
                {
                    if (!stopH)
                    {

                        if (tab[x][y].getCamp() == (string) "black")
                        {
                            if (tab[i][y - temp].getCamp() == (string) "white")
                            {
                                posibility.push_back(make_tuple(i, y - temp));
                            }
                        }
                        else
                        {
                            if (tab[i][y - temp].getCamp() == (string) "black")
                            {
                                posibility.push_back(make_tuple(i, y - temp));
                            }
                        }
                    }
                    stopH = true;
                }
            }
            temp += 1;
        }
    }

    stopB = false;
    stopH = false;
    temp = 1;

    if (x - 1 >= 0)
    {
        for (int i = x - 1; i >= 0; i--)
        {
            if (y + temp <= 7)
            {
                if (tab[i][y + temp].getEmpty())
                {

                    if (!stopB)
                    {
                        posibility.push_back(make_tuple(i, y + temp));
                    }
                }
                else
                {
                    if (!stopB)
                    {
                        if (tab[x][y].getCamp() == (string) "black")
                        {
                            if (tab[i][y + temp].getCamp() == (string) "white")
                            {
                                posibility.push_back(make_tuple(i, y + temp));
                            }
                        }
                        else
                        {
                            if (tab[i][y + temp].getCamp() == (string) "black")
                            {
                                posibility.push_back(make_tuple(i, y + temp));
                            }
                        }
                    }
                    stopB = true;
                }
            }
            if (y - temp >= 0)
            {
                if (tab[i][y - temp].getEmpty())
                {

                    if (!stopH)
                    {
                        posibility.push_back(make_tuple(i, y - temp));
                    }
                }
                else
                {
                    if (!stopH)
                    {
                        if (tab[x][y].getCamp() == (string) "black")
                        {
                            if (tab[i][y - temp].getCamp() == (string) "white")
                            {
                                posibility.push_back(make_tuple(i, y - temp));
                            }
                        }
                        else
                        {
                            if (tab[i][y - temp].getCamp() == (string) "black")
                            {
                                posibility.push_back(make_tuple(i, y - temp));
                            }
                        }
                    }
                    stopH = true;
                }
            }
            temp += 1;
        }
    }
}