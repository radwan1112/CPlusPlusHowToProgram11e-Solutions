#include <iostream>

void recursive_fun(int x)
{
    if (x == 0)
    {
        return;
    }
    recursive_fun(x / 10);
    std::cout << x % 10 << "   ";
}

int main()
{
    int x{};

    std::cout << "Enter an integer: ";
    std::cin >> x;

    recursive_fun(x);

    std::cout << std::endl;

    return 0;
}