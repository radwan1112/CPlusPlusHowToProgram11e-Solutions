#include <iostream>
#include <random>

bool flip()
{
    static std::random_device rd;
    static std::default_random_engine engine{rd()};
    static std::uniform_int_distribution coinFlip{0, 1};
    const int event{coinFlip(engine)};
    return event;
}

int main()
{
    int n{};
    std::cout << "Enter the number of times to toss the coin: ";
    std::cin >> n;

    int heads{};
    int tails{};
    for (int i{0}; i < n; i++)
    {
        if (flip())
        {
            std::cout << 'H' << '\n';
            heads++;
        }
        else
        {
            std::cout << 'T' << '\n';
            tails++;
        }
    }

    std::cout << "Number of heads: " << heads << '\n';
    std::cout << "Number of tails: " << tails << '\n';
    std::cout << "Probability of heads: " << (heads / static_cast<double>(n)) * 100 << '%' << '\n';
    std::cout << "Probability of tails: " << (tails / static_cast<double>(n)) * 100 << '%' << '\n';

    return 0;
}