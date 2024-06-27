#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <iomanip>
#include <algorithm>

// Struct of a square
struct Square
{
    bool hasQueen = false;
};

// Diminsions of the 2d array
const int N = 8;

// Create an 8 * 8 chessboard using a 2d array
std::array<std::array<Square, N>, N> board;

// Print the chessboard
void showBoard();

bool eightQueenSolver(int col);

void initializeBoard();

int main()
{
    eightQueenSolver(0);
    showBoard();

    return 0;
}

bool isSafe(int row, int col)
{

    for (int x = 0; x < col; x++)
    {
        if (board[row][x].hasQueen)
            return false;
    }
    for (int x = row, y = col; x >= 0 && y >= 0; x--, y--)
    {
        if (board[x][y].hasQueen)
            return false;
    }
    for (int x = row, y = col; x < N && y >= 0; x++, y--)
    {
        if (board[x][y].hasQueen)
        {
            return false;
        }
    }
    return true;
}

bool eightQueenSolver(int col)
{
    if (col == N)
    {
        return true;
    }

    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col].hasQueen = true;
            if (eightQueenSolver(col + 1))
                return true;
            board[i][col].hasQueen = false;
        }
    }
    return false;   
}

void initializeBoard()
{
    for (auto &row : board)
    {
        for (auto &square : row)
        {
            square.hasQueen = false;
        }
    }
}

// Function to show the board
void showBoard()
{
    for (const auto &row : board)
    {
        for (const auto &square : row)
        {
            if (square.hasQueen)
            {
                std::cout << " Q ";
            }
            else
            {
                std::cout << " . ";
            }
        }
        std::cout << '\n'
                  << std::endl;
    }
    std::cout << "____________________________\n";
}
