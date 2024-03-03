#include <iostream>

int main()
{
    int x{2}, y{8};
    int a{4}, b{6}, g{3};
    int i{3}, j{9};

    std::cout << std::boolalpha << (!(x < 5) && !(y >= 7)) << " = " << (!(x < 5 || y >= 7)) << '\n';
    std::cout << std::boolalpha << (!(a == b) || !(g != 5)) << " = " << (!(a == b && g != 5)) << '\n';
    std::cout << std::boolalpha << (!((x <= 8) && (y > 4))) << " = " << (!(x <= 8) || !(y > 4)) << '\n';
    std::cout << std::boolalpha << (!((i > 4) || (j <= 6))) << " = " << (!(i > 4) && !(j <= 6)) << '\n';

    return 0;
}