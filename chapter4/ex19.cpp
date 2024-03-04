#include <iostream>
#include <cmath>

int main()
{
    // has to be odd number greater than 1
    int size{9};
    int astricks{};

    for (int i = 0; i < size; i++)
    {
        int space{std::abs(size / 2 - i)};
        std::cout << ' ';
        for (int s = 0; s < space; s++)
        {
            std::cout << ' ';
        }

        if (i >= 0 && i <= (size / 2))
        {
            astricks = 2 * i + 1;
        }
        else
        {
            astricks = size - 2 * (i - 4);
        }

        for (int j = 0; j < astricks; j++)
        {
            std::cout << '*';
        }

        std::cout << '\n';
    }

    return 0;
}