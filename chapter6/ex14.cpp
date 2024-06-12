#include <iostream>
#include <random>
#include <array>
#include <iomanip>
#include <numeric>

struct Game
{
    int result; // 0 player has lost, 1 indicate player won the game
    int total_rolls{0};
};

int rollDice(); // rolls dice, calculates and displays sum

Game playGame()
{
    // scoped enumeration with constants that represent the game status
    enum class Status
    {
        keepRolling,
        won,
        lost
    };

    struct Game crap_game;

    int myPoint{0}; // point if no win or loss on first roll

    Status gameStatus{Status::keepRolling}; // game is not over

    // determine game status and point (if needed) based on first roll
    switch (const int sumOfDice{rollDice()})
    {
    case 7:  // win with 7 on first roll
    case 11: // win with 11 on first roll
        gameStatus = Status::won;
        break;
    case 2:  // lose with 2 on first roll
    case 3:  // lose with 3 on first roll
    case 12: // lose with 12 on first roll
        gameStatus = Status::lost;
        break;
    default:                 // did not win or lose, so remember point
        myPoint = sumOfDice; // remember the point
        // std::cout << "Point is " << myPoint << '\n';
        break; // optional (but recommended) at end of switch
    }

    while (Status::keepRolling == gameStatus)
    { // not won or lost
        // roll dice again and determine game status
        if (const int sumOfDice{rollDice()}; sumOfDice == myPoint)
        {
            gameStatus = Status::won;
        }
        else if (sumOfDice == 7)
        { // lose by rolling 7 before point
            gameStatus = Status::lost;
        }
        ++crap_game.total_rolls;
    }

    if (Status::won == gameStatus)
    {
        // std::cout << "Player wins\n";
        crap_game.result = 1;
    }
    else
    {
        // std::cout << "Player loses\n";
        crap_game.result = 0;
    }

    if (crap_game.total_rolls > 12)
    {
        crap_game.total_rolls = 12;
    }

    return crap_game;
}

int main()
{
    int no_of_games{1000};
    std::array<int, 13> win{};
    std::array<int, 13> loss{};

    struct Game gameCraps;

    for (int i{0}; i < 1000; i++)
    {
        gameCraps = playGame();
        if (gameCraps.result)
        {
            ++win.at(gameCraps.total_rolls);
        }
        else
        {
            ++loss.at(gameCraps.total_rolls);
        }
    }

    std::cout << std::setw(12) << "Roll number" << std::setw(8) << "Win" << std::setw(8) << "Lost" << "\n\n";

    for (int i{0}; i < 13; i++)
    {
        if (i == 12)
        {
            std::cout << std::setw(3) << ">" << i
                      << std::setw(15) << win.at(i)
                      << std::setw(15) << loss.at(i) << '\n';
        }
        else
        {
            std::cout << std::setw(5) << i + 1
                      << std::setw(15) << win.at(i)
                      << std::setw(15) << loss.at(i) << '\n';
        }
    }
    std::cout << std::endl;
    std::cout << std::setw(8) << "Total"
              << std::setw(8) << "won"
              << std::setw(8) << "lost"
              << std::setw(20) << "Win percentage"
              << std::setw(20) << "Loss percentage"
              << "\n\n";
    int total_wins = std::accumulate(win.begin(), win.end(), 0);
    int total_losses = std::accumulate(loss.begin(), loss.end(), 0);
    int total_games = total_wins + total_losses;
    double win_percentage = (total_wins / static_cast<double>(total_games)) * 100;
    double loss_percentage = (total_losses / static_cast<double>(total_games)) * 100;
    std::cout << std::setw(8) << total_games
              << std::setw(8) << total_wins
              << std::setw(8) << total_losses
              << std::setw(20) << std::fixed << std::setprecision(2) << win_percentage
              << std::setw(20) << std::fixed << std::setprecision(2) << loss_percentage
              << "\n\n";
}

// roll dice, calculate sum and display results
int rollDice()
{
    // set up random-number generation
    static std::random_device rd;                   // used to seed the default_random_engine
    static std::default_random_engine engine{rd()}; // rd() produces a seed
    static std::uniform_int_distribution randomDie{1, 6};
    const int die1{randomDie(engine)}; // first die roll
    const int die2{randomDie(engine)}; // second die roll
    const int sum{die1 + die2};        // compute sum of die values
    // display results of this roll
    // std::cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << '\n';
    return sum;
}