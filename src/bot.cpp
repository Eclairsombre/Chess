#include "bot.h"

ChessBot::ChessBot(/* args */)
{
}

ChessBot::~ChessBot()
{
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
    cout << "Bot move from " << get<0>(move) << " " << get<1>(move) << " to " << get<0>(destination) << " " << get<1>(destination) << endl;

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
    cout << g.getPlayerTwoCamp() << endl
         << endl;
    cout << get<0>(posRoi) << " " << get<1>(posRoi) << endl
         << endl;
    cout << g.checkCaseMate(get<0>(posRoi), get<1>(posRoi), tabGrid[get<0>(posRoi)][get<1>(posRoi)], tabGrid, g.getPlayerTwoCamp(), x, y) << endl
         << endl;

    if (g.checkCaseMate(get<0>(posRoi), get<1>(posRoi), tabGrid[get<0>(posRoi)][get<1>(posRoi)], tabGrid, g.getPlayerTwoCamp(), x, y))
    {
        cout << 1 << endl;
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
        // cout << "Size of all possible moves: " << move.size() << endl;
        int nb = rand() % this->move.size();

        this->makeMove(tabGrid, get<0>(move[nb]), get<1>(move[nb]));
        g.setTabGrid(tabGrid);
    }
}

tuple<int, tuple<tuple<int, int>, tuple<int, int>>> ChessBot::BestMoveToPlay(grid &g)
{

    // Implement your logic to find the best move here
    // You can access the generated moves using the 'move' member variable

    // For now, let's just return the first move as an example
    if (!move.empty())
    {
        tuple<int, int> source = get<0>(move[0]);
        tuple<int, int> destination = get<1>(move[0]);
        return make_tuple(0, make_tuple(make_tuple(get<0>(source), get<1>(source)), make_tuple(get<0>(destination), get<1>(destination))));
    }

    // If no move is available, return an invalid move
    return make_tuple(-1, make_tuple(make_tuple(-1, -1), make_tuple(-1, -1)));
}

int ChessBot::evaluatePosition(grid &g)
{
    int score = 0;
    pieces(*tabGrid)[10] = g.getTabGrid();

    // Evaluate the position based on the pieces on the board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (!tabGrid[i][j].getEmpty() && tabGrid[i][j].getCamp() == g.getPlayerTwoCamp())
            {
                // Assign scores to different pieces based on their type
                switch (tabGrid[i][j].getType())
                {
                case 6:
                    score += 100;
                    break;
                case 5:
                    score += 10;
                    break;
                case 2:
                    score += 5;
                    break;
                case 4:
                    score += 3;
                    break;
                case 3:
                    score += 3;
                    break;
                case 1:
                    score += 1;
                    break;
                default:
                    break;
                }

                // Add additional scores based on the position of the piece
                score += i;
            }
        }
    }

    return score;
}
