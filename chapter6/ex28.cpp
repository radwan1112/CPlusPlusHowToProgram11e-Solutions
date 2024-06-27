#include <iostream>
#include <array>

int main()
{
    std::array<bool, 1000> prime;
    prime.fill(true);

    for (int i = 2; i < 1000; i++)
    {
        for (int j = i + 1; j < 1000; j++)
        {
            if (j % i == 0)
            {
                prime[j] = false;
            }
        }
    }

    // Print the prime numbers
    int line{1};
    for (int i = 2; i < 1000; i++)
    {
        if (prime[i])
        {
            std::cout << i << "  ";
            if (line % 10 == 0)
            {
                std::cout << '\n';
            }
            line++;
        }
    }
    std::cout << '\n'
              << std::endl;

    return 0;
}