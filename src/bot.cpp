#include "bot.h"

void ChessBot::makeMove(pieces tabGrid[10][10], tuple<int, int> move, tuple<int, int> destination)
{
    cout << "Bot move from " << get<0>(move) << " " << get<1>(move) << " to " << get<0>(destination) << " " << get<1>(destination) << endl;
    SDL_Rect rect = {120 + get<0>(destination) * 100, 120 + get<1>(destination) * 100, 60, 60}, temp;

    tabGrid[get<0>(move)][get<1>(move)].setPieces(temp);
    tabGrid[get<0>(move)][get<1>(move)].setEmpty(true);

    tabGrid[get<0>(destination)][get<1>(destination)].setColor(tabGrid[get<0>(move)][get<1>(move)].getColor());
    tabGrid[get<0>(destination)][get<1>(destination)].setPieces(rect);
    tabGrid[get<0>(destination)][get<1>(destination)].setEmpty(false);
    tabGrid[get<0>(destination)][get<1>(destination)].setType(tabGrid[get<0>(move)][get<1>(move)].getType());
    tabGrid[get<0>(destination)][get<1>(destination)].setDirection(tabGrid[get<0>(move)][get<1>(move)].getDirection());
    tabGrid[get<0>(destination)][get<1>(destination)].setMove(true);
    tabGrid[get<0>(destination)][get<1>(destination)].setCamp(tabGrid[get<0>(move)][get<1>(move)].getCamp());

    tabGrid[get<0>(destination)][get<1>(destination)].ClipChanger(tabGrid[get<0>(move)][get<1>(move)].getClip());
    tabGrid[get<0>(move)][get<1>(move)].setType(0);
    tabGrid[get<0>(move)][get<1>(move)].setCamp("");
    tabGrid[get<0>(move)][get<1>(move)].ClipChanger(temp);
}

void ChessBot::playAsSecondPlayer(grid &g)
{

    pieces tabGrid[10][10];
    pieces(*tempTabGrid)[10] = g.getTabGrid();
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabGrid[i][j] = tempTabGrid[i][j];
        }
    }

    if (g.getTurn() == g.getPlayerTwoCamp())
    {

        g.setTurn(g.getPlayerOneCamp());
        this->makeMove(tabGrid, make_tuple(2, 1), make_tuple(2, 2));
        g.setTabGrid(tabGrid);
    }
}
