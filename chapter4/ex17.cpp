#include <iostream>

int n{10};

int main()
{
    for (int i = 0; i < n; i++)
    {
        // Triangle 1
        for (int j = 0; j <= i; j++)
        {
            std::cout << "*";
        }
        for (int k = i; k < n; k++)
        {
            std::cout << ' ';
        }

        // Triangle 2
        for (int j = 0; j < n - i; j++)
        {
            std::cout << "*";
        }
        for (int k = 0; k <= i; k++)
        {
            std::cout << ' ';
        }

        // Triangle 3
        for (int k = 0; k < i; k++)
        {
            std::cout << ' ';
        }
        for (int j = 0; j < n - i; j++)
        {
            std::cout << '*';
        }

        // Triangle 4
        for (int k = i; k < n; k++)
        {
            std::cout << ' ';
        }
        for (int j = 0; j <= i; j++)
        {
            std::cout << '*';
        }

        std::cout << '\n';
    }

    return 0;
}