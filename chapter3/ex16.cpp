#include <iostream>

int main()
{
    int size{};
    std::cout << "Enter the size of the square side (1 - 20): ";
    std::cin >> size;

    while (size < 1 || size > 20)
    {
        std::cout << "invalid input!" << std::endl;
        std::cout << "Enter the size of the square side (1 - 20): ";
        std::cin >> size;
    }

    for (int i = 0; i < size; i++)
    {
        if (i == 0 || i == size - 1)
        {
            int j{0};
            while (j < size)
            {
                std::cout << "* ";
                j++;
            }
        }
        else
        {
            std::cout << "* ";
            int j{0};
            while (j < size - 2)
            {
                std::cout << "  ";
                j++;
            }
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}