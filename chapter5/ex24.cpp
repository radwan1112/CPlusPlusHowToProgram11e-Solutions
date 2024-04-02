#include <iostream>

int power(int base, int exponent)
{
    if (exponent == 1)
    {
        return base;
    }
    return base * power(base, exponent - 1);
}

int main()
{
    std::cout << power(2, 2);

    return 0;
}