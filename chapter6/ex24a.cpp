#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <iomanip>

// Create an 8 * 8 chessboard using a 2d array
std::array<std::array<int, 8>, 8> board = {0};

// Define the eight possible moves of the knight by a two one-dimensional array
std::array<int, 8> horizontal = {2, 1, -1, -2, -2, -1, 1, 2};
std::array<int, 8> vertical = {-1, -2, -2, -1, 1, 2, 2, 1};

// Function to generate random int
int randomNumberGenerator(int x1, int x2);

// Print the chessboard
void showBoard();

// Start knight tour simulation
void simKnightTour();

// Check for valid moves and stores them in moves vector
void testPotentialMoves(std::vector<int> &validMoves, int currentRow, int currentCol);

int main()
{
    simKnightTour();
    return 0;
}

void simKnightTour()
{
    int currentRow = randomNumberGenerator(0, 7);
    int currentCol = randomNumberGenerator(0, 7);
    board[currentRow][currentCol] = 1;
    int counter = 1;
    std::vector<int> moves;
    do
    {
        moves.clear();
        testPotentialMoves(moves, currentRow, currentCol);
        if (!moves.empty())
        {
            int index = randomNumberGenerator(0, moves.size() - 1);
            int randomMove = moves[index];
            currentRow += vertical[randomMove];
            currentCol += horizontal[randomMove];
            board[currentRow][currentCol] = ++counter;
        }
    } while (!moves.empty());
    showBoard();
    std::cout << "Counter =  " << counter << '\n';
}

void testPotentialMoves(std::vector<int> &validMoves, int currentRow, int currentCol)
{
    int nextRow{};
    int nextCol{};
    for (int i{0}; i < 8; i++)
    {
        nextRow = currentRow + vertical[i];
        nextCol = currentCol + horizontal[i];
        if (nextRow >= 0 && nextRow < 8 && nextCol >= 0 && nextCol < 8 && board[nextRow][nextCol] == 0)
        {
            validMoves.push_back(i);
        }
    }
}

int randomNumberGenerator(int x1, int x2)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution dist(x1, x2);
    return dist(engine);
}

void showBoard()
{
    for (const std::array<int, 8> &row : board)
    {
        for (const int &square : row)
        {
            std::cout << std::setw(4) << square; // Adjust width as needed
        }
        std::cout << '\n'
                  << std::endl;
    }
}