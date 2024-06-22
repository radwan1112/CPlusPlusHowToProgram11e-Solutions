#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <iomanip>
#include <algorithm>

// Create an 8 * 8 chessboard using a 2d array
std::array<std::array<int, 8>, 8> board = {0};

// Define the eight possible moves of the knight by a two one-dimensional array
std::array<int, 8> horizontal = {2, 1, -1, -2, -2, -1, 1, 2};
std::array<int, 8> vertical = {-1, -2, -2, -1, 1, 2, 2, 1};

// Define an array to store the results of 1000 tour
std::array<int, 1000> tours = {0};

// Function to generate random int
int randomNumberGenerator(int x1, int x2);

// Print the chessboard
void showBoard();

// Start knight tour simulation
int simKnightTour();

// Check for valid moves and stores them in moves vector
void testPotentialMoves(std::vector<int> &validMoves, int currentRow, int currentCol);

int main()
{
    int maxTours{0};
    std::cout << "No." << '\t' << "Number of Tours" << '\n';
    int count{1};
    for (int &tour : tours)
    {
        tour = simKnightTour();
        std::cout << count << '\t' << tour;
        count++;
        if (tour >= maxTours)
        {
            maxTours = tour;
            std::cout << "  *" << '\n';
        }
        else
        {
            std::cout << '\n';
        }
    }
    std::cout << "\nMax number of tours: " << maxTours << std::endl;
    return 0;
}

int simKnightTour()
{
    int currentRow = randomNumberGenerator(0, 7);
    int currentCol = randomNumberGenerator(0, 7);
    int counter = 1;
    board[currentRow][currentCol] = counter;
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
    std::fill(board.begin(), board.end(), std::array<int, 8>{0});
    return counter;
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