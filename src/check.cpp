#include "grid.h"
#include <tuple>
#include <vector>
#include <iostream>

using namespace std;

bool CoordonneinTuple(int x, int y, vector<tuple<int, int>> &po)
{
    for (int i = 0; i < po.size(); i++)
    {
        if (get<0>(po[i]) == x && get<1>(po[i]) == y)
        {
            return true;
        }
    }
    return false;
}
void addVector(vector<tuple<tuple<int, int>, tuple<int, int>>> &v1, vector<tuple<int, int>> &v2, int x, int y)
{
    for (int i = 0; i < v2.size(); i++)
    {
        v1.push_back(make_tuple(make_tuple(x, y), make_tuple(get<0>(v2[i]), get<1>(v2[i]))));
    }
}

vector<tuple<tuple<int, int>, tuple<int, int>>> grid::checkStopMate(pieces p, pieces tab[10][10], string camp, int xOfPieceWhoCheck, int yOfPieceWhoCheck, int xKingCheck, int yKingCheck)
{
    vector<tuple<tuple<int, int>, tuple<int, int>>> possibleMoves;
    int a, b;

    // Iterate through all the pieces on the board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // Check if the piece belongs to the same camp and is not the king
            if (tab[i][j].getCamp() == camp && (i != xKingCheck || j != yKingCheck))
            {
                vector<tuple<int, int>> pieceMoves;
                this->posibleMove(i, j, tab[i][j], tab, pieceMoves);

                // Check if any of the possible moves of the piece can block the check
                for (int z = 0; z < pieceMoves.size(); z++)
                {
                    tuple<int, int> move = pieceMoves[z];
                    int x = get<0>(move);
                    int y = get<1>(move);

                    if (tab[x][y].getEmpty())
                    {
                        tab[x][y].setEmpty(false);
                        if (!checkCaseMate(xKingCheck, yKingCheck, p, tab, camp, a, b))
                        {
                            possibleMoves.push_back(make_tuple(make_tuple(i, j), make_tuple(x, y)));
                        }
                        tab[x][y].setEmpty(true);
                    }
                    else if (tab[x][y].getCamp() != camp)
                    {

                        pieces temp = tab[x][y];
                        tab[x][y] = tab[i][j];

                        if (!checkCaseMate(xKingCheck, yKingCheck, p, tab, camp, a, b))
                        {
                            possibleMoves.push_back(make_tuple(make_tuple(i, j), make_tuple(x, y)));
                        }
                        tab[i][j] = tab[x][y];
                        tab[x][y] = temp;
                    }
                }
            }
        }
    }

    return possibleMoves;
}

bool grid::checkCaseMate(const int x, const int z, pieces p, pieces tab[10][10], string camp, int &xOfPieceWhoCheck, int &yOfPieceWhoCheck)
{

    vector<tuple<int, int>> otherPieceDeplacement;

    for (int i = 0; i < 8; i++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (!tab[i][y].getEmpty())
            {
                if (camp == "white")
                {
                    if (tab[i][y].getCamp() == "black")
                    {
                        vector<tuple<int, int>> temp;

                        otherPieceDeplacement = temp;
                        this->posibleMoveAttack(i, y, tab[i][y], tab, otherPieceDeplacement);

                        if (CoordonneinTuple(x, z, otherPieceDeplacement))
                        {

                            xOfPieceWhoCheck = i;
                            yOfPieceWhoCheck = y;
                            return true;
                        }
                    }
                }
                else
                {
                    if (tab[i][y].getCamp() == "white")
                    {
                        vector<tuple<int, int>> temp;

                        otherPieceDeplacement = temp;
                        this->posibleMoveAttack(i, y, tab[i][y], tab, otherPieceDeplacement);

                        if (CoordonneinTuple(x, z, otherPieceDeplacement))
                        {

                            xOfPieceWhoCheck = i;
                            yOfPieceWhoCheck = y;

                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void grid::checkEnd(bool &quit)
{
    vector<tuple<int, int>> temp;
    this->check = temp;
    // cout << get<0>(this->posRoiBlack) << " " << get<1>(this->posRoiBlack) << endl;
    // cout << get<0>(this->posRoiWhite) << " " << get<1>(this->posRoiWhite) << endl;
    this->moveRoi(get<0>(this->posRoiBlack), get<1>(this->posRoiBlack), this->tabGrid[get<0>(this->posRoiBlack)][get<1>(this->posRoiBlack)], this->tabGrid, this->check);
    this->moveRoi(get<0>(this->posRoiWhite), get<1>(this->posRoiWhite), this->tabGrid[get<0>(this->posRoiWhite)][get<1>(this->posRoiWhite)], this->tabGrid, this->check);
    if (this->checkmate)
    {
        cout << this->winner << endl;
        quit = true;
    }
}