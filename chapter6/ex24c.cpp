#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <random>
#include <iomanip>
#include <algorithm>
#include <chrono>

// Create an 8 * 8 chessboard using a 2d array
std::array<std::array<int, 8>, 8> board = {0};

// Define the eight possible moves of the knight by a two one-dimensional array
std::array<int, 8> horizontal = {2, 1, -1, -2, -2, -1, 1, 2};
std::array<int, 8> vertical = {-1, -2, -2, -1, 1, 2, 2, 1};

// Function to generate random int
int randomNumberGenerator(int x1, int x2, std::mt19937 &engine);

// Print the chessboard
void showBoard();

// Start knight tour simulation
int simKnightTour(std::mt19937 &engine);

// Check for valid moves and stores them in moves vector
void testPotentialMoves(std::vector<int> &validMoves, int currentRow, int currentCol);

int main()
{
    int tours{0};
    std::cout << "No." << '\t' << "Number of Tours" << '\n';
    long long int count{1};

    std::random_device rd;
    std::mt19937 engine(rd());

    auto start = std::chrono::high_resolution_clock::now();

    while (tours < 64)
    {
        tours = simKnightTour(engine);
        std::cout << count << '\t' << tours;
        count++;
        std::cout << '\n';
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    // Calculate hours, minutes, and seconds
    auto hours = std::chrono::duration_cast<std::chrono::hours>(elapsed);
    elapsed -= hours;
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(elapsed);
    elapsed -= minutes;
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed);

    std::cout << "\nTotal tours attempts: " << count << std::endl;
    std::cout << "Time taken: " << hours.count() << " hours, "
              << minutes.count() << " minutes, "
              << seconds.count() << " seconds" << std::endl;

    return 0;
}

int simKnightTour(std::mt19937 &engine)
{
    int currentRow = randomNumberGenerator(0, 7, engine);
    int currentCol = randomNumberGenerator(0, 7, engine);
    int counter = 1;
    board[currentRow][currentCol] = counter;
    std::vector<int> moves;
    do
    {
        moves.clear();
        testPotentialMoves(moves, currentRow, currentCol);
        if (!moves.empty())
        {
            int index = randomNumberGenerator(0, moves.size() - 1, engine);
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

int randomNumberGenerator(int x1, int x2, std::mt19937 &engine)
{
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