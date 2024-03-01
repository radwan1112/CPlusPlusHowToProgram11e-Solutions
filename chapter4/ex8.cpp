#include <iostream>

int product{1};

int main()
{
    for (int i = 0; i <= 15; i++)
    {
        if (i % 2 != 0)
        {
            product *= i;
        }
    }

    std::cout << "Total product: " << product << "\n";

    return 0;
}