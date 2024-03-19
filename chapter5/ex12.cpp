#include <iostream>

int division(int a, int b)
{
    return a / b;
}

int remainder(int a, int b)
{
    return a % b;
}

void print(int x)
{
    if (x == 0)
    {
        return;
    }
    print(division(x, 10));
    std::cout << remainder(x, 10) << "  ";
}

int main()
{
    int x{};
    std::cout << "Enter an integer between 1 and 32767: ";
    std::cin >> x;
    print(x);
    std::cout << '\n';
}