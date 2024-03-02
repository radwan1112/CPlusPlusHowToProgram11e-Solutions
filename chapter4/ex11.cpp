#include <iostream>

int n{10};

int main()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            std::cout << ' ';
        }
        for (int k = i; k < n; k++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            std::cout << ' ';
        }
        for (int k = 0; k <= i; k++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }

    return 0;
}