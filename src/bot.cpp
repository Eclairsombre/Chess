#include "bot.h"
#include <climits>

ChessBot::ChessBot(/* args */)
{
}

ChessBot::~ChessBot()
{
}

void copyGrid(pieces tab[10][10], pieces tab2[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int y = 0; y < 10; y++)
        {
            tab2[i][y] = tab[i][y];
        }
    }
}

void getIfEmptyTabGrid(pieces tabGrid[10][10])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            cout << tabGrid[j][i].getEmpty() << " ";
        }
        cout << endl;
    }
}

void getIfCampTabGrid(pieces tabGrid[10][10])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)

        {
            cout << tabGrid[j][i].getCamp() << " ";
        }
        cout << endl;
    }
}
void ChessBot::makeMove(pieces tabGrid[10][10], tuple<int, int> move, tuple<int, int> destination)
{
    // cout << "Bot move from " << get<0>(move) << " " << get<1>(move) << " to " << get<0>(destination) << " " << get<1>(destination) << endl;

    SDL_Rect rect = {120 + get<0>(destination) * 100, 120 + get<1>(destination) * 100, 60, 60};

    // cout << tabGrid[get<0>(destination)][get<1>(destination)].getEmpty() << endl;
    pieces p;

    tabGrid[get<0>(destination)][get<1>(destination)] = tabGrid[get<0>(move)][get<1>(move)];
    tabGrid[get<0>(move)][get<1>(move)] = p;

    tabGrid[get<0>(move)][get<1>(move)].setEmpty(true);

    tabGrid[get<0>(destination)][get<1>(destination)].setEmpty(false);
    tabGrid[get<0>(destination)][get<1>(destination)].setPieces(rect);

    tabGrid[get<0>(destination)][get<1>(destination)].setMove(true);

    // cout << tabGrid[get<0>(destination)][get<1>(destination)] << endl;
    //  getIfEmptyTabGrid(tabGrid);
    //  getIfCampTabGrid(tabGrid);

    vector<tuple<tuple<int, int>, tuple<int, int>>> temp;
    this->move = temp;
}

void ChessBot::checkAllPossibleMoves(grid &g, pieces tabGrid[10][10])
{
    int x, y;

    if (g.checkCaseMate(get<0>(posRoi), get<1>(posRoi), tabGrid[get<0>(posRoi)][get<1>(posRoi)], tabGrid, g.getPlayerTwoCamp(), x, y))
    {

        this->move = g.checkStopMate(tabGrid[get<0>(posRoi)][get<1>(posRoi)], tabGrid, g.getPlayerTwoCamp(), x, y, get<0>(posRoi), get<1>(posRoi));
        vector<tuple<int, int>> po;
        g.posibleMove(get<0>(posRoi), get<1>(posRoi), tabGrid[get<0>(posRoi)][get<1>(posRoi)], tabGrid, po);
        addVector(this->move, po, get<0>(posRoi), get<1>(posRoi));
        cout << "Size of all possible moves: " << this->move.size() << endl;
        if (this->move.empty())
        {
            // g.setCheckMate(true);
            cout << "Checkmate" << endl;
        }
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (tabGrid[i][j].getCamp() == g.getPlayerTwoCamp())
                {
                    vector<tuple<int, int>> po;

                    g.posibleMove(i, j, tabGrid[i][j], tabGrid, po);

                    for (int k = 0; k < po.size(); k++)
                    {

                        this->move.push_back(make_tuple(make_tuple(i, j), po[k]));
                    }
                }
            }
        }
    }
}

void ChessBot::playAsSecondPlayer(grid &g)
{

    pieces tabGrid[10][10];
    pieces(*tempTabGrid)[10] = g.getTabGrid();
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (tempTabGrid[i][j].getType() == 6 && tempTabGrid[i][j].getCamp() == g.getPlayerTwoCamp())
            {
                this->posRoi = make_tuple(i, j);
            }
            tabGrid[i][j] = tempTabGrid[i][j];
        }
    }

    if (g.getTurn() == g.getPlayerTwoCamp())
    {
        g.setTurn(g.getPlayerOneCamp());

        checkAllPossibleMoves(g, tabGrid);
        cout << "Size of all possible moves: " << move.size() << endl;
        int nb = rand() % this->move.size();

        this->makeMove(tabGrid, get<0>(move[nb]), get<1>(move[nb]));

        g.setTabGrid(tabGrid);
    }
}
