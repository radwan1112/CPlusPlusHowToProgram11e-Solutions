#include <iostream>
#include <random>

int main()
{
    static std::random_device rd;
    static std::default_random_engine engine{rd()};
    static std::uniform_int_distribution random_number{1, 1000};
    int number{random_number(engine)};

    int guess{};

    std::cout << "I have a number between 1 and 1000. \n";
    std::cout << "Can you guess the number? \n";
    std::cout << "Please type your first guess: ";

    char option{'y'};
    while (guess != number || option == 'y')
    {
        std::cin >> guess;
        if (guess == number)
        {
            std::cout << "Excellent! you guessed the number! \n";
            std::cout << "Would you like to play again (y or n)?";
            std::cin >> option;
            if (option == 'y')
            {
                number = random_number(engine);
            }
        }
        else if (guess < number)
        {
            std::cout << "Too low. Try again \n";
        }
        else
        {
            std::cout << "Too high. Try again \n";
        }
    }

    return 0;
}