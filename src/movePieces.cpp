
#include "check.cpp"
#include <tuple>
#include <vector>
#include <iostream>

using namespace std;

void movePion(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po)
{
    if (p.getDirection() == (string) "Haut")
    {
        if (p.getMove())
        {
            if (y - 1 >= 0)
            {
                if (tab[x][y - 1].getEmpty())
                {
                    po.push_back(make_tuple(x, y - 1));
                }
            }
        }
        else
        {

            if (tab[x][y - 1].getEmpty())
            {
                po.push_back(make_tuple(x, y - 1));
                if (tab[x][y - 2].getEmpty())
                {
                    po.push_back(make_tuple(x, y - 2));
                }
            }
        }
        if (x - 1 >= 0)
        {
            if (y - 1 >= 0)
            {
                if (!tab[x - 1][y - 1].getEmpty())
                {

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
            }
        }
    }

    else
    {
        if (p.getMove())
        {
            if (y + 1 <= 7)
            {
                if (tab[x][y + 1].getEmpty())
                {
                    po.push_back(make_tuple(x, y + 1));
                }
            }
        }
        else
        {

            if (tab[x][y + 1].getEmpty())
            {
                po.push_back(make_tuple(x, y + 1));
                if (tab[x][y + 2].getEmpty())
                {
                    po.push_back(make_tuple(x, y + 2));
                }
            }
        }
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
                            po.push_back(make_tuple(x + 1, y + 1));
                        }
                    }
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
            }
        }
    }
}

void moveTour(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po)
{
    bool stop = false;
    for (int i = x + 1; i < 8; i++)
    {

        if (tab[i][y].getEmpty())
        {

            if (!stop)
            {
                po.push_back(make_tuple(i, y));
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
                        po.push_back(make_tuple(i, y));
                    }
                }
                else
                {
                    if (tab[i][y].getCamp() == (string) "black")
                    {
                        po.push_back(make_tuple(i, y));
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

                po.push_back(make_tuple(i, y));
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
                        po.push_back(make_tuple(i, y));
                    }
                }
                else
                {
                    if (tab[i][y].getCamp() == (string) "black")
                    {
                        po.push_back(make_tuple(i, y));
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
                po.push_back(make_tuple(x, i));
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
                        po.push_back(make_tuple(x, i));
                    }
                }
                else
                {
                    if (tab[x][i].getCamp() == (string) "black")
                    {
                        po.push_back(make_tuple(x, i));
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

                po.push_back(make_tuple(x, i));
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
                        po.push_back(make_tuple(x, i));
                    }
                }
                else
                {
                    if (tab[x][i].getCamp() == (string) "black")
                    {
                        po.push_back(make_tuple(x, i));
                    }
                }
            }
            stop = true;
        }
    }
}

void moveCavalier(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po)
{
    if (y - 1 >= 0)
    {
        if (x + 2 <= 7)
        {
            if (tab[x + 2][y - 1].getEmpty())
            {
                po.push_back(make_tuple(x + 2, y - 1));
            }
            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x + 2][y - 1].getCamp() == (string) "white")
                    {
                        po.push_back(make_tuple(x + 2, y - 1));
                    }
                }
                else
                {
                    if (tab[x + 2][y - 1].getCamp() == (string) "black")
                    {
                        po.push_back(make_tuple(x + 2, y - 1));
                    }
                }
            }
        }
        if (x - 2 >= 0)
        {
            if (tab[x - 2][y - 1].getEmpty())
            {
                po.push_back(make_tuple(x - 2, y - 1));
            }

            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x - 2][y - 1].getCamp() == (string) "white")
                    {
                        po.push_back(make_tuple(x - 2, y - 1));
                    }
                }
                else
                {
                    if (tab[x - 2][y - 1].getCamp() == (string) "black")
                    {
                        po.push_back(make_tuple(x - 2, y - 1));
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
                po.push_back(make_tuple(x + 1, y - 2));
            }
            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x + 1][y - 2].getCamp() == (string) "white")
                    {
                        po.push_back(make_tuple(x + 1, y - 2));
                    }
                }
                else
                {
                    if (tab[x + 1][y - 2].getCamp() == (string) "black")
                    {
                        po.push_back(make_tuple(x + 1, y - 2));
                    }
                }
            }
        }
        if (x - 1 >= 0)
        {
            if (tab[x - 1][y - 2].getEmpty())
            {
                po.push_back(make_tuple(x - 1, y - 2));
            }

            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x - 1][y - 2].getCamp() == (string) "white")
                    {
                        po.push_back(make_tuple(x - 1, y - 2));
                    }
                }
                else
                {
                    if (tab[x - 1][y - 2].getCamp() == (string) "black")
                    {
                        po.push_back(make_tuple(x - 1, y - 2));
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
                po.push_back(make_tuple(x + 1, y + 2));
            }
            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x + 1][y + 2].getCamp() == (string) "white")
                    {
                        po.push_back(make_tuple(x + 1, y + 2));
                    }
                }
                else
                {
                    if (tab[x + 1][y + 2].getCamp() == (string) "black")
                    {
                        po.push_back(make_tuple(x + 1, y + 2));
                    }
                }
            }
        }
        if (x - 1 >= 0)
        {
            if (tab[x - 1][y + 2].getEmpty())
            {
                po.push_back(make_tuple(x - 1, y + 2));
            }

            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x - 1][y + 2].getCamp() == (string) "white")
                    {
                        po.push_back(make_tuple(x - 1, y + 2));
                    }
                }
                else
                {
                    if (tab[x - 1][y + 2].getCamp() == (string) "black")
                    {
                        po.push_back(make_tuple(x - 1, y + 2));
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
                po.push_back(make_tuple(x + 2, y + 1));
            }
            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x + 2][y + 1].getCamp() == (string) "white")
                    {
                        po.push_back(make_tuple(x + 2, y + 1));
                    }
                }
                else
                {
                    if (tab[x + 2][y + 1].getCamp() == (string) "black")
                    {
                        po.push_back(make_tuple(x + 2, y + 1));
                    }
                }
            }
        }
        if (x - 2 >= 0)
        {
            if (tab[x - 2][y + 1].getEmpty())
            {
                po.push_back(make_tuple(x - 2, y + 1));
            }

            else
            {
                if (tab[x][y].getCamp() == (string) "black")
                {
                    if (tab[x - 2][y + 1].getCamp() == (string) "white")
                    {
                        po.push_back(make_tuple(x - 2, y + 1));
                    }
                }
                else
                {
                    if (tab[x - 2][y + 1].getCamp() == (string) "black")
                    {
                        po.push_back(make_tuple(x - 2, y + 1));
                    }
                }
            }
        }
    }
}

void moveFou(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po)
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
                        po.push_back(make_tuple(i, y + temp));
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
                                po.push_back(make_tuple(i, y + temp));
                            }
                        }
                        else
                        {
                            if (tab[i][y + temp].getCamp() == (string) "black")
                            {
                                po.push_back(make_tuple(i, y + temp));
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

                        po.push_back(make_tuple(i, y - temp));
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
                                po.push_back(make_tuple(i, y - temp));
                            }
                        }
                        else
                        {
                            if (tab[i][y - temp].getCamp() == (string) "black")
                            {
                                po.push_back(make_tuple(i, y - temp));
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
                        po.push_back(make_tuple(i, y + temp));
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
                                po.push_back(make_tuple(i, y + temp));
                            }
                        }
                        else
                        {
                            if (tab[i][y + temp].getCamp() == (string) "black")
                            {
                                po.push_back(make_tuple(i, y + temp));
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
                        po.push_back(make_tuple(i, y - temp));
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
                                po.push_back(make_tuple(i, y - temp));
                            }
                        }
                        else
                        {
                            if (tab[i][y - temp].getCamp() == (string) "black")
                            {
                                po.push_back(make_tuple(i, y - temp));
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

void moveDame(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po)
{
    moveTour(x, y, p, tab, po);
    moveFou(x, y, p, tab, po);
}

tuple<bool, vector<tuple<int, int>>> grid::canCastle(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po)
{
    int a, b;
    vector<tuple<int, int>> temp;

    // Check if the king has moved
    if (p.getMove())
    {
        return make_tuple(false, temp);
    }

    // Check if the rook on the right has moved
    if (tab[7][y].getType() == 2 && tab[7][y].getMove())
    {
        return make_tuple(false, temp);
    }

    // Check if the rook on the left has moved
    if (tab[0][y].getType() == 2 && tab[0][y].getMove())
    {
        return make_tuple(false, temp);
    }

    // Check if there are any pieces between the king and the rook on the right
    if (tab[5][y].getEmpty() && tab[6][y].getEmpty())
    {
        // Check if the king is in check// Check if the king would be in check after castling
        if (!checkCaseMate(x, y, p, tab, p.getCamp(), a, b) && !checkCaseMate(x, y + 2, p, tab, p.getCamp(), a, b))
        {
            po.push_back(make_tuple(6, y));
            temp.push_back(make_tuple(6, y));
        }
    }

    // Check if there are any pieces between the king and the rook on the left
    if (tab[1][y].getEmpty() && tab[2][y].getEmpty() && tab[3][y].getEmpty())
    {
        // Check if the king is in check// Check if the king would be in check after castling
        if (!checkCaseMate(x, y, p, tab, p.getCamp(), a, b) && !checkCaseMate(x, y - 2, p, tab, p.getCamp(), a, b))
        {

            po.push_back(make_tuple(2, y));

            temp.push_back(make_tuple(2, y));
        }
    }

    if (temp.size() != 0)
    {
        return make_tuple(true, temp);
    }
    else
    {
        return make_tuple(false, temp);
    }
}

void grid::moveRoi(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po)
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
                    tab[x][y].setEmpty(true);
                    if (!checkCaseMate(x + 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y + 1));
                    }
                    tab[x][y].setEmpty(false);
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
                    tab[x][y].setEmpty(true);
                    if (!checkCaseMate(x + 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y + 1));
                    }
                    tab[x][y].setEmpty(false);
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
                    tab[x][y].setEmpty(true);

                    if (!checkCaseMate(x + 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y - 1));
                    }
                    tab[x][y].setEmpty(false);
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
                    tab[x][y].setEmpty(true);
                    if (!checkCaseMate(x + 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x + 1, y - 1));
                    }
                    tab[x][y].setEmpty(false);
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
                tab[x][y].setEmpty(true);
                if (!checkCaseMate(x + 1, y, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x + 1, y));
                }
                tab[x][y].setEmpty(false);
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
                tab[x][y].setEmpty(true);

                if (!checkCaseMate(x + 1, y, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x + 1, y));
                }
                tab[x][y].setEmpty(false);
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
                    tab[x][y].setEmpty(true);
                    if (!checkCaseMate(x - 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x - 1, y + 1));
                    }
                    tab[x][y].setEmpty(false);
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
                    tab[x][y].setEmpty(true);
                    if (!checkCaseMate(x - 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x - 1, y + 1));
                    }
                    tab[x][y].setEmpty(false);
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
                    tab[x][y].setEmpty(true);
                    if (!checkCaseMate(x - 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x - 1, y - 1));
                    }
                    tab[x][y].setEmpty(false);
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
                    tab[x][y].setEmpty(true);

                    if (!checkCaseMate(x - 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                    {
                        po.push_back(make_tuple(x - 1, y - 1));
                    }
                    tab[x][y].setEmpty(false);
                }
            }
        }
        if (p.getCamp() == "black")
        {

            if (!tab[x - 1][y].getEmpty() && tab[x - 1][y].getCamp() == "white")
            {
                tab[x - 1][y].setEmpty(true);
                if (!checkCaseMate(x - 1, y, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x - 1, y));
                }
                tab[x - 1][y].setEmpty(false);
            }
            else if (tab[x - 1][y].getEmpty())
            {
                tab[x][y].setEmpty(true);
                if (!checkCaseMate(x - 1, y, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x - 1, y));
                }
                tab[x][y].setEmpty(false);
            }
        }
        else
        {

            if (!tab[x - 1][y].getEmpty() && tab[x - 1][y].getCamp() == "black")
            {
                tab[x - 1][y].setEmpty(true);
                if (!checkCaseMate(x - 1, y, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x - 1, y));
                }
                tab[x - 1][y].setEmpty(false);
            }
            else if (tab[x - 1][y].getEmpty())
            {
                tab[x][y].setEmpty(true);

                if (!checkCaseMate(x - 1, y, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x - 1, y));
                }
                tab[x][y].setEmpty(false);
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
                tab[x][y].setEmpty(true);
                if (!checkCaseMate(x, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x, y - 1));
                }
                tab[x][y].setEmpty(false);
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
                tab[x][y].setEmpty(true);

                if (!checkCaseMate(x, y - 1, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x, y - 1));
                }
                tab[x][y].setEmpty(false);
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
                tab[x][y].setEmpty(true);
                if (!checkCaseMate(x, y + 1, p, tab, tab[x][y].getCamp(), a, b))
                {
                    po.push_back(make_tuple(x, y + 1));
                }
                tab[x][y].setEmpty(false);
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
                tab[x][y].setEmpty(true);

                if (!checkCaseMate(x, y + 1, p, tab, tab[x][y].getCamp(), a, b))

                {
                    po.push_back(make_tuple(x, y + 1));
                }
                tab[x][y].setEmpty(false);
            }
        }
    }

    if (checkCaseMate(x, y, p, tab, tab[x][y].getCamp(), a, b) && po.size() == 0)
    {
        vector<tuple<tuple<int, int>, tuple<int, int>>> possibleMoves;
        possibleMoves = this->checkStopMate(p, tab, tab[x][y].getCamp(), a, b, x, y);

        if (possibleMoves.size() == 0)
        {
            {
                this->checkmate = true;
                if (tab[x][y].getCamp() == "white")
                {
                    this->winner = "black";
                }
                else
                {
                    this->winner = "white";
                }
            }
        }
    }
}

void grid::posibleMove(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po)
{
    vector<tuple<int, int>> temp;
    po = temp;

    switch (p.getType())
    {
    case 1:
        movePion(x, y, p, tab, po);

        break;
    case 2:
        moveTour(x, y, p, tab, po);
        break;
    case 3:
        moveCavalier(x, y, p, tab, po);
        break;
    case 4:
        moveFou(x, y, p, tab, po);
        break;

    case 5:
        moveDame(x, y, p, tab, po);
        break;
    case 6:
        this->moveRoi(x, y, p, tab, po);
        break;

    default:
        break;
    }
}

void grid::performMove()
{
    SDL_Rect temp, rect = tabGrid[this->indiceDragX][this->indiceDragY].getPiece(), vide;
    int a, b;

    if (CoordonneinTuple(rect.x / 100 - 1, rect.y / 100 - 1, this->posibility))
    {
        if (this->turn == "black")
        {
            this->turn = "white";
        }
        else
        {
            this->turn = "black";
        }

        if (this->tabGrid[this->indiceDragX][this->indiceDragY].getType() == 6)
        {

            if (get<0>(CoCastle))
            {

                vector<tuple<int, int>> listCoCastle = get<1>(CoCastle);
                for (int i = 0; i < listCoCastle.size(); i++)
                {
                    if (get<0>(listCoCastle[i]) == (rect.x / 100) - 1 && get<1>(listCoCastle[i]) == (rect.y / 100) - 1)
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

                        this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].ClipChanger(this->tabGrid[this->indiceDragX][this->indiceDragY].getClip());
                        this->tabGrid[this->indiceDragX][this->indiceDragY].setType(0);
                        this->tabGrid[this->indiceDragX][this->indiceDragY].setCamp("");
                        this->tabGrid[this->indiceDragX][this->indiceDragY].ClipChanger(vide);

                        if (get<0>(listCoCastle[i]) == 6)
                        {
                            rect = tabGrid[7][get<1>(listCoCastle[i])].getPiece();
                            rect = {120 + 5 * 100, 120 + (get<1>(listCoCastle[i])) * 100, 60, 60};

                            this->tabGrid[7][get<1>(listCoCastle[i])].setPieces(temp);
                            this->tabGrid[7][get<1>(listCoCastle[i])].setEmpty(true);

                            this->tabGrid[5][get<1>(listCoCastle[i])].setColor(this->tabGrid[7][get<1>(listCoCastle[i])].getColor());
                            this->tabGrid[5][get<1>(listCoCastle[i])].setPieces(rect);
                            this->tabGrid[5][get<1>(listCoCastle[i])].setEmpty(false);
                            this->tabGrid[5][get<1>(listCoCastle[i])].setType(this->tabGrid[7][get<1>(listCoCastle[i])].getType());
                            this->tabGrid[5][get<1>(listCoCastle[i])].setDirection(this->tabGrid[7][get<1>(listCoCastle[i])].getDirection());
                            this->tabGrid[5][get<1>(listCoCastle[i])].setMove(true);
                            this->tabGrid[5][get<1>(listCoCastle[i])].setCamp(this->tabGrid[7][get<1>(listCoCastle[i])].getCamp());

                            this->tabGrid[5][get<1>(listCoCastle[i])].ClipChanger(this->tabGrid[7][get<1>(listCoCastle[i])].getClip());
                            this->tabGrid[7][get<1>(listCoCastle[i])].setType(0);
                            this->tabGrid[7][get<1>(listCoCastle[i])].setCamp("");
                            this->tabGrid[7][get<1>(listCoCastle[i])].ClipChanger(vide);
                        }
                        else if (get<0>(listCoCastle[i]) == 2)
                        {
                            rect = tabGrid[0][get<1>(listCoCastle[i])].getPiece();
                            rect = {120 + 3 * 100, 120 + (get<1>(listCoCastle[i])) * 100, 60, 60};

                            this->tabGrid[0][get<1>(listCoCastle[i])].setPieces(temp);
                            this->tabGrid[0][get<1>(listCoCastle[i])].setEmpty(true);

                            this->tabGrid[3][get<1>(listCoCastle[i])].setColor(this->tabGrid[0][get<1>(listCoCastle[i])].getColor());
                            this->tabGrid[3][get<1>(listCoCastle[i])].setPieces(rect);
                            this->tabGrid[3][get<1>(listCoCastle[i])].setEmpty(false);
                            this->tabGrid[3][get<1>(listCoCastle[i])].setType(this->tabGrid[0][get<1>(listCoCastle[i])].getType());
                            this->tabGrid[3][get<1>(listCoCastle[i])].setDirection(this->tabGrid[0][get<1>(listCoCastle[i])].getDirection());
                            this->tabGrid[3][get<1>(listCoCastle[i])].setMove(true);
                            this->tabGrid[3][get<1>(listCoCastle[i])].setCamp(this->tabGrid[0][get<1>(listCoCastle[i])].getCamp());

                            this->tabGrid[3][get<1>(listCoCastle[i])].ClipChanger(this->tabGrid[0][get<1>(listCoCastle[i])].getClip());
                            this->tabGrid[0][get<1>(listCoCastle[i])].setType(0);
                            this->tabGrid[0][get<1>(listCoCastle[i])].setCamp("");
                            this->tabGrid[0][get<1>(listCoCastle[i])].ClipChanger(vide);
                        }

                        vector<tuple<int, int>> f;
                        this->posibility = f;
                        break;
                    }
                }
            }
            else
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

                this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].ClipChanger(this->tabGrid[this->indiceDragX][this->indiceDragY].getClip());
                this->tabGrid[this->indiceDragX][this->indiceDragY].setType(0);
                this->tabGrid[this->indiceDragX][this->indiceDragY].setCamp("");
                this->tabGrid[this->indiceDragX][this->indiceDragY].ClipChanger(vide);
                vector<tuple<int, int>> f;
                this->posibility = f;
            }
        }
        else
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

            this->tabGrid[(rect.x / 100) - 1][(rect.y / 100) - 1].ClipChanger(this->tabGrid[this->indiceDragX][this->indiceDragY].getClip());
            this->tabGrid[this->indiceDragX][this->indiceDragY].setType(0);
            this->tabGrid[this->indiceDragX][this->indiceDragY].setCamp("");
            this->tabGrid[this->indiceDragX][this->indiceDragY].ClipChanger(vide);
            vector<tuple<int, int>> f;
            this->posibility = f;
        }
    }
    else
    {
        rect = {120 + this->indiceDragX * 100, 120 + this->indiceDragY * 100, 60, 60};
        this->tabGrid[this->indiceDragX][this->indiceDragY].setPieces(rect);
    }
}

void grid::posibleMoveAttack(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po)
{
    vector<tuple<int, int>> temp;
    po = temp;

    switch (p.getType())
    {
    case 1:
        this->attackPion(x, y, p, tab, po);

        break;
    case 2:
        moveTour(x, y, p, tab, po);
        break;
    case 3:
        moveCavalier(x, y, p, tab, po);
        break;
    case 4:
        moveFou(x, y, p, tab, po);
        break;

    case 5:
        moveDame(x, y, p, tab, po);
        break;
    case 6:
        this->attackRoi(x, y, p, tab, po);
        break;

    default:
        break;
    }
}