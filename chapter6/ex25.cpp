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
    bool isAvailable = true;
    int eliminationNumber{0};
};

// Create an 8 * 8 chessboard using a 2d array
std::array<std::array<Square, 8>, 8> board;

// Define the eight possible directions a queen can move
std::array<int, 8> horizontal = {0, 1, 1, 1, 0, -1, -1, -1};
std::array<int, 8> vertical = {1, 1, 0, -1, -1, -1, 0, 1};

// Global declaration
std::random_device rd; // Random device to seed the engine
std::mt19937 engine(rd());

// Function to generate random int
int randomNumberGenerator(int x1, int x2);

// Print the chessboard
void showBoard();

void calculateEliminationNumber();

int testPotentialMoves(int currentRow, int currentCol);

// Function to print the elmination numbers of the board
void showEliminationNumbers();

void eightQueenPlacer(std::mt19937 &engine);

void updateAvailableSquares(int startRow, int startCol);

int findMinElimination();

void initializeBoard();

int main()
{
    std::random_device rd;
    std::mt19937 engine(rd());

    calculateEliminationNumber();
    eightQueenPlacer(engine);
    showBoard();
    showEliminationNumbers();

    return 0;
}

void eightQueenPlacer(std::mt19937 &engine)
{
    int totalQueens{0};
    while (totalQueens < 8)
    {
        totalQueens = 0;
        int currentRow{};
        int currentCol{};
        int minEliminationNo{22};
        do
        {
            currentRow = randomNumberGenerator(0, 7);
            currentCol = randomNumberGenerator(0, 7);

        } while (board[currentRow][currentCol].eliminationNumber > minEliminationNo);
        board[currentRow][currentCol].hasQueen = true;
        board[currentRow][currentCol].isAvailable = false;
        totalQueens++;
        updateAvailableSquares(currentRow, currentCol);
        calculateEliminationNumber();
        showEliminationNumbers();
        showBoard();

        for (int queen{0}; queen < 7; queen++)
        {
            int bestRow{-1};
            int bestCol{-1};
            for (int i{0}; i < 8; i++)
            {
                for (int j{0}; j < 8; j++)
                {
                    minEliminationNo = findMinElimination();
                    if (board[i][j].isAvailable && board[i][j].eliminationNumber <= minEliminationNo)
                    {
                        bestRow = i;
                        bestCol = j;
                    }
                }
            }
            if (bestRow != -1 && bestCol != -1)
            {
                totalQueens++;
                board[bestRow][bestCol].hasQueen = true;
                board[bestRow][bestCol].isAvailable = false;
                updateAvailableSquares(bestRow, bestCol);
                calculateEliminationNumber();
                showEliminationNumbers();
                showBoard();
            }
        }
        initializeBoard();
        calculateEliminationNumber();
    }
}

void initializeBoard()
{
    for (auto &row : board)
    {
        for (auto &square : row)
        {
            square.hasQueen = false;
            square.isAvailable = true;
            square.eliminationNumber = 0;
        }
    }
}

void updateAvailableSquares(int startRow, int startCol)
{
    for (int i{0}; i < 8; i++)
    {
        int currentRow{startRow};
        int currentCol{startCol};
        int nextRow = currentRow + vertical[i];
        int nextCol = currentCol + horizontal[i];
        while (nextRow >= 0 && nextRow < 8 && nextCol >= 0 && nextCol < 8)
        {
            if (board[nextRow][nextCol].isAvailable)
            {
                board[nextRow][nextCol].isAvailable = false;
            }
            currentRow = nextRow;
            currentCol = nextCol;
            nextRow = currentRow + vertical[i];
            nextCol = currentCol + horizontal[i];
        }
    }
}

int testPotentialMoves(int startRow, int startCol)
{
    int validMove{0};

    for (int i{0}; i < 8; i++)
    {
        int currentRow{startRow};
        int currentCol{startCol};
        int nextRow = currentRow + vertical[i];
        int nextCol = currentCol + horizontal[i];
        while (nextRow >= 0 && nextRow < 8 && nextCol >= 0 && nextCol < 8)
        {
            if (board[nextRow][nextCol].isAvailable)
            {
                validMove++;
            }
            currentRow = nextRow;
            currentCol = nextCol;
            nextRow = currentRow + vertical[i];
            nextCol = currentCol + horizontal[i];
        }
    }
    return validMove;
}

int findMinElimination()
{
    // Range-based for loop to iterate through each row
    int min{100};
    for (int row{0}; row < 8; row++)
    {
        // Range-based for loop to iterate through each square in the current row
        for (int col{0}; col < 8; col++)
        {
            if (board[row][col].isAvailable)
            {
                // Perform operations on the square
                board[row][col].eliminationNumber = testPotentialMoves(row, col) + 1;
                if (board[row][col].eliminationNumber < 100)
                {
                    min = board[row][col].eliminationNumber;
                }
            }
        }
    }
    return min;
}

void calculateEliminationNumber()
{
    // Range-based for loop to iterate through each row
    for (int row{0}; row < 8; row++)
    {
        // Range-based for loop to iterate through each square in the current row
        for (int col{0}; col < 8; col++)
        {
            if (board[row][col].isAvailable)
            {
                // Perform operations on the square
                board[row][col].eliminationNumber = testPotentialMoves(row, col) + 1;
            }
            else
            {
                board[row][col].eliminationNumber = 100;
            }
        }
    }
}

int randomNumberGenerator(int x1, int x2)
{
    std::uniform_int_distribution<int> distribution(x1, x2);
    return distribution(engine);
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
            else if (!square.isAvailable)
            {
                std::cout << " * ";
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

// Function to show the board
void showEliminationNumbers()
{
    for (const auto &row : board)
    {
        for (const auto &square : row)
        {
            std::cout << std::setw(3) << square.eliminationNumber << " ";
        }
        std::cout << "\n";
    }
    std::cout << "____________________________\n";
}