#include <iostream>

bool isMultiple(int n1, int n2)
{
    return !(n2 % n1);
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        int n1{};
        int n2{};
        std::cout << i + 1 << ". Enter a pair of integers: ";
        std::cin >> n1 >> n2;
        if (isMultiple(n1, n2))
        {
            std::cout << n2 << " is a multiple of " << n1 << '\n';
        }
        else
        {
            std::cout << n2 << " is not a multiple of " << n1 << '\n';
        }
    }
    return 0;
}