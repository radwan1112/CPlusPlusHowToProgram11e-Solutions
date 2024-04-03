#include <iostream>
#include <cmath>

int mystery(int, int);

int main()
{
    std::cout << "Enter two integers: ";
    int x{};
    int y{};

    std::cin >> x >> y;

    std::cout << "The result is " << mystery(x, y) << std::endl;

    return 0;
}

int mystery(int a, int b)
{
    int result{};
    if (std::abs(b) == 1)
    {
        return a;
    }
    else
    {
        result = a + mystery(a, (std::abs(b) - 1));
    }
    if (b < 0)
    {
        return result * -1;
    }
    else
    {
        return result;
    }
}