#include "grid.h"
#include <tuple>
#include <vector>
#include <iostream>
using namespace std;

void grid::attackPion(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po)
{
    if (p.getDirection() == (string) "Haut")
    {

        if (x - 1 >= 0)
        {
            if (y - 1 >= 0)
            {
                if (!tab[x - 1][y - 1].getEmpty())
                {

                    if (tab[x][y].getCamp() == (string) "black")
                    {

                        if (tab[x - 1][y - 1].getCamp() == (string) "white")
                        {
                            po.push_back(make_tuple(x - 1, y - 1));
                        }
                    }
                    else
                    {
                        if (tab[x - 1][y - 1].getCamp() == (string) "black")
                        {
                            po.push_back(make_tuple(x - 1, y - 1));
                        }
                    }
                }
                else
                {
                    po.push_back(make_tuple(x - 1, y - 1));
                }
            }
        }
        if (x + 1 <= 7)
        {
            if (y - 1 >= 0)
            {
                if (!tab[x + 1][y - 1].getEmpty())
                {
                    {
                        if (tab[x][y].getCamp() == (string) "black")
                        {
                            if (tab[x + 1][y - 1].getCamp() == (string) "white")
                            {
                                po.push_back(make_tuple(x + 1, y - 1));
                            }
                        }
                        else
                        {
                            if (tab[x + 1][y - 1].getCamp() == (string) "black")
                            {
                                po.push_back(make_tuple(x + 1, y - 1));
                            }
                        }
                    }
                }
                else
                {
                    po.push_back(make_tuple(x + 1, y - 1));
                }
            }
        }
    }

    else if (p.getDirection() == (string) "Bas")
    {

        if (x - 1 >= 0)
        {
            if (y + 1 <= 7)
            {
                if (!tab[x - 1][y + 1].getEmpty())
                {
                    if (tab[x][y].getCamp() == (string) "black")
                    {
                        if (tab[x - 1][y + 1].getCamp() == (string) "white")
                        {
                            po.push_back(make_tuple(x - 1, y + 1));
                        }
                    }
                    else
                    {
                        if (tab[x + 1][y + 1].getCamp() == (string) "black")
                        {
                            po.push_back(make_tuple(x - 1, y + 1));
                        }
                    }
                }
                else
                {
                    po.push_back(make_tuple(x - 1, y + 1));
                }
            }
        }
        if (x + 1 <= 7)
        {
            if (y + 1 <= 7)
            {
                if (!tab[x + 1][y + 1].getEmpty())
                {
                    if (tab[x][y].getCamp() == (string) "black")
                    {
                        if (tab[x + 1][y + 1].getCamp() == (string) "white")
                        {
                            po.push_back(make_tuple(x + 1, y + 1));
                        }
                    }
                    else
                    {
                        if (tab[x + 1][y + 1].getCamp() == (string) "black")
                        {
                            po.push_back(make_tuple(x + 1, y + 1));
                        }
                    }
                }
                else
                {
                    po.push_back(make_tuple(x + 1, y + 1));
                }
            }
        }
    }
}

void grid::attackRoi(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po)
{
    int a, b;

    if (x + 1 <= 7)
    {
        if (y + 1 <= 7)
        {
            if (p.getCamp() == "black")
            {

                if (!tab[x + 1][y + 1].getEmpty() && tab[x + 1][y + 1].getCamp() == "white")
                {
                    tab[x + 1][y + 1].setEmpty(true);
                    if (!checkCaseMate(x + 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y + 1));
                    }
                    tab[x + 1][y + 1].setEmpty(false);
                }
                else if (tab[x + 1][y + 1].getEmpty())
                {

                    if (!checkCaseMate(x + 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y + 1));
                    }
                }
            }

            else
            {

                if (!tab[x + 1][y + 1].getEmpty() && tab[x + 1][y + 1].getCamp() == "black")
                {
                    tab[x + 1][y + 1].setEmpty(true);
                    if (!checkCaseMate(x + 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y + 1));
                    }
                    tab[x + 1][y + 1].setEmpty(false);
                }
                else if (tab[x + 1][y + 1].getEmpty())
                {

                    if (!checkCaseMate(x + 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y + 1));
                    }
                }
            }
        }
        if (y - 1 >= 0)
        {
            if (p.getCamp() == "black")
            {

                if (!tab[x + 1][y - 1].getEmpty() && tab[x + 1][y - 1].getCamp() == "white")
                {
                    tab[x + 1][y - 1].setEmpty(true);
                    if (!checkCaseMate(x + 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y - 1));
                    }
                    tab[x + 1][y - 1].setEmpty(false);
                }
                else if (tab[x + 1][y - 1].getEmpty())
                {

                    if (!checkCaseMate(x + 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y - 1));
                    }
                }
            }
            else
            {

                if (!tab[x + 1][y - 1].getEmpty() && tab[x + 1][y - 1].getCamp() == "black")
                {
                    tab[x + 1][y - 1].setEmpty(true);
                    if (!checkCaseMate(x + 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y - 1));
                    }
                    tab[x + 1][y - 1].setEmpty(false);
                }
                else if (tab[x + 1][y - 1].getEmpty())
                {

                    if (!checkCaseMate(x + 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y - 1));
                    }
                }
            }
            if (p.getCamp() == "black")
            {

                if (!tab[x + 1][y].getEmpty() && tab[x + 1][y].getCamp() == "white")
                {
                    tab[x + 1][y].setEmpty(true);
                    if (!checkCaseMate(x + 1, y, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y));
                    }
                    tab[x + 1][y].setEmpty(false);
                }
                else if (tab[x + 1][y].getEmpty())
                {

                    if (!checkCaseMate(x + 1, y, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y));
                    }
                }
            }
            else
            {

                if (!tab[x + 1][y].getEmpty() && tab[x + 1][y].getCamp() == "black")
                {
                    tab[x + 1][y].setEmpty(true);
                    if (!checkCaseMate(x + 1, y, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y));
                    }
                    tab[x + 1][y].setEmpty(false);
                }
                else if (tab[x + 1][y].getEmpty())
                {

                    if (!checkCaseMate(x + 1, y, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y));
                    }
                }
            }
        }
    }

    if (x - 1 >= 0)
    {
        if (y + 1 <= 7)
        {
            if (p.getCamp() == "black")
            {

                if (!tab[x - 1][y + 1].getEmpty() && tab[x - 1][y + 1].getCamp() == "white")
                {
                    tab[x - 1][y + 1].setEmpty(true);
                    if (!checkCaseMate(x - 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x - 1, y + 1));
                    }
                    tab[x - 1][y + 1].setEmpty(false);
                }
                else if (tab[x - 1][y + 1].getEmpty())
                {

                    if (!checkCaseMate(x - 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x - 1, y + 1));
                    }
                }
            }
            else
            {

                if (!tab[x - 1][y + 1].getEmpty() && tab[x - 1][y + 1].getCamp() == "black")
                {
                    tab[x - 1][y + 1].setEmpty(true);
                    if (!checkCaseMate(x - 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x - 1, y + 1));
                    }
                    tab[x - 1][y + 1].setEmpty(false);
                }
                else if (tab[x - 1][y + 1].getEmpty())
                {

                    if (!checkCaseMate(x - 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x - 1, y + 1));
                    }
                }
            }
        }
        if (y - 1 >= 0)
        {
            if (p.getCamp() == "black")
            {

                if (!tab[x - 1][y - 1].getEmpty() && tab[x - 1][y - 1].getCamp() == "white")
                {
                    tab[x - 1][y - 1].setEmpty(true);
                    if (!checkCaseMate(x - 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x - 1, y - 1));
                    }
                    tab[x - 1][y - 1].setEmpty(false);
                }
                else if (tab[x - 1][y - 1].getEmpty())
                {

                    if (!checkCaseMate(x - 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x - 1, y - 1));
                    }
                }
            }
            else
            {

                if (!tab[x - 1][y - 1].getEmpty() && tab[x - 1][y - 1].getCamp() == "black")
                {
                    tab[x - 1][y - 1].setEmpty(true);
                    if (!checkCaseMate(x - 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x - 1, y - 1));
                    }
                    tab[x - 1][y - 1].setEmpty(false);
                }
                else if (tab[x - 1][y - 1].getEmpty())
                {

                    if (!checkCaseMate(x - 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x - 1, y - 1));
                    }
                }
            }
        }
    }

    if (y - 1 >= 0)
    {
        if (p.getCamp() == "black")
        {

            if (!tab[x][y - 1].getEmpty() && tab[x][y - 1].getCamp() == "white")
            {
                tab[x][y - 1].setEmpty(true);
                if (!checkCaseMate(x, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x, y - 1));
                }
                tab[x][y - 1].setEmpty(false);
            }
            else if (tab[x][y - 1].getEmpty())
            {

                if (!checkCaseMate(x, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x, y - 1));
                }
            }
        }

        else
        {

            if (!tab[x][y - 1].getEmpty() && tab[x][y - 1].getCamp() == "black")
            {
                tab[x][y - 1].setEmpty(true);
                if (!checkCaseMate(x, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x, y - 1));
                }
                tab[x][y - 1].setEmpty(false);
            }
            else if (tab[x][y - 1].getEmpty())
            {

                if (!checkCaseMate(x, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x, y - 1));
                }
            }
        }
    }
    if (y + 1 <= 7)
    {
        if (p.getCamp() == "black")
        {

            if (!tab[x][y + 1].getEmpty() && tab[x][y + 1].getCamp() == "white")
            {
                tab[x][y + 1].setEmpty(true);
                if (!checkCaseMate(x, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x, y + 1));
                }
                tab[x][y + 1].setEmpty(false);
            }
            else if (tab[x][y + 1].getEmpty())
            {

                if (!checkCaseMate(x, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x, y + 1));
                }
            }
        }
        else
        {

            if (!tab[x][y + 1].getEmpty() && tab[x][y + 1].getCamp() == "black")
            {
                tab[x][y + 1].setEmpty(true);
                if (!checkCaseMate(x, y + 1, p, tab, tab[x][y].getCamp(), a, b))

                {
                    po.push_back(make_tuple(x, y + 1));
                }
                tab[x][y + 1].setEmpty(false);
            }
            else if (tab[x][y + 1].getEmpty())
            {

                if (!checkCaseMate(x, y + 1, p, tab, tab[x][y].getCamp(), a, b))

                {
                    po.push_back(make_tuple(x, y + 1));
                }
            }
        }
    }
}
