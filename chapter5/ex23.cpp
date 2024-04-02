#include <iostream>
#include <random>

int main()
{
    static std::random_device rd;
    static std::default_random_engine engine{rd()};
    static std::uniform_int_distribution random_number{1, 1000};
    int number{random_number(engine)};

    int guess{};
    int no_guesses{1};
    std::cout << "I have a number between 1 and 1000. \n";
    std::cout << "Can you guess the number? \n";
    std::cout << "Please type your first guess. \n";

    char option{'y'};
    while (option == 'y')
    {
        std::cout << "Guess " << no_guesses << ": ";
        std::cin >> guess;
        if (guess == number)
        {
            if (no_guesses < 10)
            {
                std::cout << "Either you know the secret or you got lucky! \n";
            }
            else if (no_guesses == 10)
            {
                std::cout << "Ahah! you know the secret! \n";
            }
            else
            {
                std::cout << "You should be able to do better! \n";
            }
            std::cout << "Would you like to play again (y or n)?";
            std::cin >> option;
            if (option == 'y')
            {
                number = random_number(engine);
                no_guesses = 0;
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
        no_guesses++;
    }

    return 0;
}