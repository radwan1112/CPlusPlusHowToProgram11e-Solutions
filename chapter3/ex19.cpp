#include <iostream>

int main()
{
    for (int i = 0; i < 8; i++)
    {
        if (i % 2)
        {
            std::cout << ' ';
        }
        for (int j = 0; j < 8; j++)
        {

            std::cout << "* ";
        }
        std::cout << "\n";
    }

    return 0;
}