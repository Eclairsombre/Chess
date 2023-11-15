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
            if (y - 1 >= 0)
            {
                if (!tab[x - 1][y - 1].getEmpty())
                {

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
            }
        }
        if (x <= 6)
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

void moveDame(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &posibility)
{
    moveTour(x, y, p, tab, posibility);
    moveFou(x, y, p, tab, posibility);
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

bool grid::checkCaseMate(const int x, const int z, pieces p, pieces tab[10][10], string camp, int &a, int &b)
{

    vector<tuple<int, int>> otherPieceDeplacement;
    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (camp == "white")
            {
                if (tab[i][y].getCamp() == "black" && tab[i][y].getType() != 6)
                {

                    this->posibleMove(i, y, tab[i][y], tab, otherPieceDeplacement);
                    if (CoordonneinTuple(x, z, otherPieceDeplacement))
                    {

                        a = i;
                        b = y;
                        return true;
                    }
                }
            }
            else
            {
                if (tab[i][y].getCamp() == "white" && tab[i][y].getType() != 6)
                {
                    this->posibleMove(i, y, tab[i][y], tab, otherPieceDeplacement);
                    if (CoordonneinTuple(x, z, otherPieceDeplacement))
                    {
                        a = i;
                        b = y;

                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool grid::checkStopMate(pieces p, pieces tab[10][10], string camp, int a, int b, int x, int z)
{
    vector<tuple<int, int>> caseMate, temp;
    int f, g;
    this->posibleMove(a, b, tab[a][b], tab, caseMate);
    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (camp == "black" && tab[i][y].getCamp() == "black" && tab[i][y].getType() != 6)
            {

                this->posibleMove(i, y, tab[i][y], tab, this->move);
                for (int j = 0; j < this->move.size(); j++)
                {
                    if (CoordonneinTuple(get<0>(this->move[j]), get<1>(this->move[j]), caseMate))
                    {

                        tab[get<0>(this->move[j])][get<1>(this->move[j])].setEmpty(false);
                        if (!checkCaseMate(x, z, tab[x][z], tab, tab[x][z].getCamp(), f, g))
                        {
                            cout << tab[i][y].getType() << endl;
                            return true;
                        }
                        tab[get<0>(this->move[j])][get<1>(this->move[j])].setEmpty(true);
                    }
                }
            }
            else if (camp == "white" && tab[i][y].getCamp() == "white" && tab[i][y].getType() != 6)
            {

                this->posibleMove(i, y, tab[i][y], tab, this->move);
                for (int j = 0; j < this->move.size(); j++)
                {
                    if (CoordonneinTuple(get<0>(this->move[j]), get<1>(this->move[j]), caseMate))
                    {

                        tab[get<0>(this->move[j])][get<1>(this->move[j])].setEmpty(false);
                        if (!checkCaseMate(x, z, tab[x][z], tab, tab[x][z].getCamp(), f, g))
                        {
                            cout << tab[i][y].getType() << endl;
                            return true;
                        }
                        tab[get<0>(this->move[j])][get<1>(this->move[j])].setEmpty(true);
                    }
                }
            }
        }
    }
    return false;
}

void grid::moveRoi(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &po)
{
    int a, b;

    if (x + 1 <= 7)
    {
        if (y + 1 <= 7)
        {
            if (tab[x + 1][y + 1].getEmpty() && !checkCaseMate(x + 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
            {

                po.push_back(make_tuple(x + 1, y + 1));
            }
        }
        if (y - 1 >= 0)
        {
            if (tab[x + 1][y - 1].getEmpty() && !checkCaseMate(x + 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
            {

                po.push_back(make_tuple(x + 1, y - 1));
            }
        }
        if (tab[x + 1][y].getEmpty() && !checkCaseMate(x + 1, y, p, tab, tab[x][y].getCamp(), a, b))
        {

            posibility.push_back(make_tuple(x + 1, y));
        }
    }
    if (x - 1 >= 0)
    {
        if (y + 1 <= 7)
        {
            if (tab[x - 1][y + 1].getEmpty() && !checkCaseMate(x - 1, y + 1, p, tab, tab[x][y].getCamp(), a, b))
            {

                po.push_back(make_tuple(x - 1, y + 1));
            }
        }
        if (y - 1 >= 0)
        {
            if (tab[x - 1][y - 1].getEmpty() && !checkCaseMate(x - 1, y - 1, p, tab, tab[x][y].getCamp(), a, b))
            {

                posibility.push_back(make_tuple(x - 1, y - 1));
            }
        }
        if (tab[x - 1][y].getEmpty() && !checkCaseMate(x + 1, y, p, tab, tab[x][y].getCamp(), a, b))
        {

            po.push_back(make_tuple(x - 1, y));
        }
    }
    if (y - 1 >= 0)
    {
        if (tab[x][y - 1].getEmpty() && !checkCaseMate(x, y + -1, p, tab, tab[x][y].getCamp(), a, b))
        {

            po.push_back(make_tuple(x, y - 1));
        }
    }
    if (y + 1 <= 7)
    {
        if (tab[x][y + 1].getEmpty() && !checkCaseMate(x, y + 1, p, tab, tab[x][y].getCamp(), a, b))
        {

            po.push_back(make_tuple(x, y + 1));
        }
    }
    if (checkCaseMate(x, y, p, tab, tab[x][y].getCamp(), a, b) && po.size() == 0)
    {
        cout << 1 << endl;
        if (!this->checkStopMate(p, tab, tab[x][y].getCamp(), a, b, x, y))
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

void grid::posibleMove(int x, int y, pieces p, pieces tab[10][10], vector<tuple<int, int>> &posibility)
{
    vector<tuple<int, int>> temp;
    posibility = temp;

    switch (p.getType())
    {
    case 1:
        movePion(x, y, p, tab, posibility);

        break;
    case 2:
        moveTour(x, y, p, tab, posibility);
        break;
    case 3:
        moveCavalier(x, y, p, tab, posibility);
        break;
    case 4:
        moveFou(x, y, p, tab, posibility);
        break;

    case 5:
        moveDame(x, y, p, tab, posibility);
        break;
    case 6:
        this->moveRoi(x, y, p, tab, posibility);
        break;

    default:
        break;
    }
}