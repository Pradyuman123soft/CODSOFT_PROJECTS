#include <iostream>
using namespace std;

const int size = 3;
char board[size][size];

void switchPlayer(char &currentplayer)
{
    currentplayer = (currentplayer == 'X') ? 'O' : 'X';
}
void initializeBoard()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void displayBoard()
{
    cout << "  0 1 2" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i << " ";
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j];
            if (j < size - 1)
            {
                cout << '|';
            }
        }
        cout << endl;
        if (i < size - 1)
        {
            cout << "_ _ _ _ _" << endl;
        }
    }
}
bool checkWin(char player)
{
    for (int i = 0; i < size; i++)
    {
        // check for raws and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    // lets check the diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}
bool checkDraw()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][i] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}
void playGame()
{
    char currentPlayer = 'X';
    bool gameover = false;

    initializeBoard();

    while (!gameover)
    {
        displayBoard();
        int row, col;
        cout << "Player " << currentPlayer;
        cout << ", enter you move (row and column): ";
        cin >> row >> col;
        if (row < 0 || row > size - 1 || col < 0 || col > size - 1 || board[row][col] != ' ')
        {
            cout << "Invalid Move Try Again. " << endl;
            continue;
        }
        board[row][col] = currentPlayer;

        if (checkWin(currentPlayer))
        {
            displayBoard();
            cout << "Player " << currentPlayer << " Wins!" << endl;
            gameover = true;
        }
        else if (checkDraw())
        {
            displayBoard();
            cout << "Game Draw!" << endl;
            gameover = true;
        }
        else
        {
            switchPlayer(currentPlayer);
        }
    }
}
int main()
{
    char playAgain;
    do
    {
        playGame();
        cout << "Do You Want To Play Again (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}