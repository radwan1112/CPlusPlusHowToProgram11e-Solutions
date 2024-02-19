#include <iostream>

int main()
{
    int x{};
    int y{};
    std::cout << "Enter two integers: ";
    std::cin >> x >> y;

    if (x != 0 && x % y)
    {
        std::cout << x << " is a not multiple of " << y << std::endl;
    }
    else
    {
        std::cout << x << " is a multiple of " << y << std::endl;
    }
}