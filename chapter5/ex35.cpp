#include <iostream>
#include <random>
#include <limits>

int bankBalance{0};

int rollDice()
{
    static std::random_device rd;
    static std::default_random_engine engine{rd()};
    static std::uniform_int_distribution randomDie{1, 6};

    const int die1{randomDie(engine)};
    const int die2{randomDie(engine)};
    const int sum{die1 + die2};
    std::cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << '\n';

    return sum;
}

int readInteger()
{
    int input{-1};
    bool valid{false};
    do
    {
        std::cin >> input;
        if (std::cin.good())
        {
            valid = true;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ivalid input; please re-enter." << std::endl;
        }
    } while (!valid);
    return input;
}

int readWager()
{
    int input{-1};
    bool valid{false};
    do
    {
        std::cin >> input;
        if (std::cin.good())
        {
            valid = true;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ivalid input; please re-enter." << std::endl;
        }
        if (input > bankBalance || input < 1)
        {
            valid = false;
            std::cout << "Ivalid input; please re-enter." << std::endl;
        }
    } while (!valid);
    return input;
}

void playOneGame(int wager)
{
    enum class Status
    {
        keepRolling,
        won,
        lost
    };

    std::cout << '\n';

    int myPoint{0};
    Status gameStatus{Status::keepRolling};

    switch (const int sumOfDice{rollDice()})
    {
    case 7:
    case 11:
        gameStatus = Status::won;
        break;
    case 2:
    case 3:
    case 12:
        gameStatus = Status::lost;
        break;
    default:
        myPoint = sumOfDice;
        std::cout << "Point is " << myPoint << '\n';
        break;
    }

    while (Status::keepRolling == gameStatus)
    {
        if (const int sumOfDice{rollDice()}; sumOfDice == myPoint)
        {
            gameStatus = Status::won;
        }
        else if (sumOfDice == 7)
        {
            gameStatus = Status::lost;
        }
    }

    if (Status::won == gameStatus)
    {
        std::cout << "Player wins\n";
        bankBalance += wager;
        if (bankBalance > 1500)
        {
            std::cout << "Your up big Now's the time to cash in your chips!" << '\n';
        }
    }
    else
    {
        std::cout << "Player loses\n";
        bankBalance -= wager;
        if (bankBalance < 100)
        {
            std::cout << "Oh, you 're going for broke, huh?" << '\n';
        }
    }
    if (bankBalance < 1)
    {
        std::cout << "Sorry. busted!" << '\n';
    }
    std::cout << "Bank Balance: " << bankBalance << '\n';
}

void startGame()
{
    bankBalance = 1000;
    int wager{};
    int option{};

    do
    {
        std::cout << '\n';
        std::cout << "1. Continue Playing.\n";
        std::cout << "2. Cash In.\n";
        std::cout << "\nEnter option: ";
        option = readInteger();
        switch (option)
        {
        case 1:
            std::cout << "\nEnter your wager: ";
            wager = readWager();
            playOneGame(wager);
            break;
        case 2:
            option = 2;
            std::cout << "Bank Balance: " << bankBalance << '\n';
            break;
        default:
            std::cout << "Invalid input! \n";
            break;
        }
    } while (option != 2 && bankBalance > 0);
}

int main()
{
    int option{};

    do
    {
        std::cout << "GAME OF CRAPS"
                  << "\n\n";
        std::cout << "1. Start New Game." << '\n';
        std::cout << "2. Exit." << '\n';
        std::cout << "\nEnter option: ";
        option = readInteger();

        switch (option)
        {
        case 1:
            startGame();
            break;
        case 2:
            std::cout << "Goodbye!" << '\n';
            option = 2;
            break;
        default:
            std::cout << "Invalid input Goodbye!" << '\n';
            option = 2;
            break;
        }
    } while (option != 2);

    return 0;
}