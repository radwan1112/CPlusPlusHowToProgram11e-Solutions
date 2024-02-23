#include <iostream>

int main()
{
    int base2{101010101};
    int base10{};
    int i{1};
    while (base2 != 0)
    {
        base10 += (base2 % 10) * i;
        base2 /= 10;
        i *= 2;
    }
    std::cout << base10 << std::endl;
    return 0;
}