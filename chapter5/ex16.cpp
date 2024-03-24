#include <iostream>

bool isPerfect(int x)
{
    int sum{};
    for (int i = 1; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            sum += i;
        }
    }
    if (sum == x)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    for (int i = 1; i <= 1000; i++)
    {
        if (isPerfect(i))
        {
            std::cout << i << " = ";
            for (int k = 1; k <= i / 2; k++)
            {
                if (i % k == 0)
                {
                    if (k >= i / 2)
                    {
                        std::cout << k << '.' << '\n';
                    }
                    else
                    {
                        std::cout << k << " + ";
                    }
                }
            }
        }
    }

    return 0;
}