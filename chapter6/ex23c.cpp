#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <iomanip>

// Create an 8 * 8 chessboard using a 2d array
std::array<std::array<int, 8>, 8> board = {0};

// Create an accessibility array
std::array<std::array<int, 8>, 8> accessibility = {{{2, 3, 4, 4, 4, 4, 3, 2},
                                                    {3, 4, 6, 6, 6, 6, 4, 3},
                                                    {4, 6, 8, 8, 8, 8, 6, 4},
                                                    {4, 6, 8, 8, 8, 8, 6, 4},
                                                    {4, 6, 8, 8, 8, 8, 6, 4},
                                                    {4, 6, 8, 8, 8, 8, 6, 4},
                                                    {3, 4, 6, 6, 6, 6, 4, 3},
                                                    {2, 3, 4, 4, 4, 4, 3, 2}}};

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

// Update the accessbiility array
void updateAccessibility(int currentRow, int currentCol);

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
    void updateAccessibility(int currentRow, int currentCol);

    std::vector<int> moves;
    std::vector<int> nextMoves;

    do
    {
        moves.clear();
        testPotentialMoves(moves, currentRow, currentCol);
        if (!moves.empty())
        {
            int bestMove{-1};
            int minAccess{9};
            int nextMinAccess{9};
            for (int move : moves)
            {
                int nextRow = currentRow + vertical[move];
                int nextCol = currentCol + horizontal[move];
                if (accessibility[nextRow][nextCol] <= minAccess)
                {
                    if (accessibility[nextRow][nextCol] == minAccess)
                    {
                        nextMoves.clear();
                        testPotentialMoves(nextMoves, nextRow, nextCol);
                        for (int nextMove : nextMoves)
                        {
                            int nextNextRow = nextRow + vertical[nextMove];
                            int nextNextCol = nextCol + horizontal[nextMove];
                            if (accessibility[nextNextRow][nextNextCol] < nextMinAccess)
                            {
                                nextMinAccess = accessibility[nextNextRow][nextNextCol];
                                bestMove = move;
                            }
                        }
                    }
                    else
                    {
                        minAccess = accessibility[nextRow][nextCol];
                        bestMove = move;
                    }
                }
            }
            currentRow += vertical[bestMove];
            currentCol += horizontal[bestMove];
            board[currentRow][currentCol] = ++counter;
            updateAccessibility(currentRow, currentCol);
        }
        showBoard();
        std::cout << "\n---------------------------------\n";
    } while (!moves.empty());
    std::cout << "Counter =  " << counter << '\n';
}

void updateAccessibility(int currentRow, int currentCol)
{
    accessibility[currentRow][currentCol] = 9;

    for (int i{0}; i < 8; i++)
    {
        int nextRow = currentRow + vertical[i];
        int nextCol = currentCol + horizontal[i];
        if (nextRow >= 0 && nextRow < 8 && nextCol >= 0 && nextCol < 8 && board[nextRow][nextCol] == 0)
        {
            accessibility[nextRow][nextCol]--;
        }
    }
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