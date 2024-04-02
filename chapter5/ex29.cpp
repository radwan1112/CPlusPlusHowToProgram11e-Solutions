#include <iostream>
#include <algorithm>

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
}

int main()
{
    int a{};
    int b{};
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;
    if (a < b)
        std::swap(a, b);

    std::cout << "The greatest common divisor is " << gcd(a, b) << '\n';

    return 0;
}