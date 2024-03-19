#include <iostream>

bool isEven(int x)
{
    return !(x % 2);
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        int n{};
        std::cout << i + 1 << ". Enter an integer: ";
        std::cin >> n;
        std::cout << std::endl;
        if (isEven(n))
        {
            std::cout << n << " is an Even number" << '\n';
        }
        else
        {
            std::cout << n << " is not an Even number" << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}