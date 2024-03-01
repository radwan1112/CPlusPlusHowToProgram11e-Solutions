#include <iostream>

int main()
{
    int n{};
    std::cout << "Enter the number of integers: ";
    std::cin >> n;

    int narr[n] = {};
    int smallest{};
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter integer[" << i << "]: ";
        std::cin >> narr[i];
        if (i == 0)
        {
            smallest = narr[i];
        }
        if (narr[i] < smallest)
        {
            smallest = narr[i];
        }
    }

    std::cout << "Smallest int: " << smallest << std::endl;

    return 0;
}