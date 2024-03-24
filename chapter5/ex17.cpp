#include <iostream>
#include <cmath>

bool isPrime(int x)
{
    if (x == 1 || x == 0)
    {
        return false;
    }
    else
    {
        int root = sqrt(x);
        bool isPrime{true};
        for (int i = 2; i <= root; i++)
        {
            if (x % i == 0)
            {
                isPrime = false;
            }
        }
        return isPrime;
    }
}

int main()
{
    std::cout << "Prime numbers: " << '\n';
    for (int i = 2; i < 10000; i++)
    {
        if (isPrime(i))
        {
            std::cout << i << '\n';
        }
    }
    return 0;
}