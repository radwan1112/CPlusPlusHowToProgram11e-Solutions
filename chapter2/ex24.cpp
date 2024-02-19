#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    std::cout << std::setw(9) << std::left << "integer"
              << std::setw(9) << std::left << "square"
              << std::setw(8) << std::left << "cube" << std::endl;

    // Print data
    for (int i = 0; i <= 10; i++)
    {
        std::cout << std::setw(9) << std::left << i
                  << std::setw(9) << std::left << std::pow(i, 2)
                  << std::setw(8) << std::left << std::pow(i, 3) << std::endl;
    }

    return 0;
}