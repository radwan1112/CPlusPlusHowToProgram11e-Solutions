#include <iostream>
#include <algorithm>

int gcd(int a, int b)
{
    if (a < b)std::swap(a, b);    
    
    int remainder{};
    do
    {
        remainder = a % b;
        a = b;
        b = remainder;
    } while (remainder > 0);
    return a;
}

int main()
{
    int a{};
    int b{};
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;

    std::cout << "The greatest common divisor is " << gcd(a, b) << '\n';

    return 0;
}