#include <iostream>

int main()
{
    int x{};
    int y{};

    std::cout << "Enter two integers: ";
    std::cin >> x >> y;

    std::cout << x << " + " << y << " = " << x + y << std::endl;
    std::cout << x << " * " << y << " = " << x * y << std::endl;
    std::cout << x << " - " << y << " = " << x - y << std::endl;
    std::cout << x << " / " << y << " = " << x / y << std::endl;

}