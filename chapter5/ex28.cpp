#include <iostream>

long long unsigned int factorial(long long unsigned int number)
{
    if (number <= 1)
    {
        return 1;
    }
    else
    {
        std::cout << number << '\n';
        return number * factorial(number - 1);
    }
}

int main()
{
    for (int counter{0}; counter <= 10; ++counter)
    {
        std::cout << counter << "! = " << factorial(counter) << '\n';
    }

    std::cout << "\n20! = " << factorial(20)
              << "\n30! = " << factorial(30)
              << "\n40! = " << factorial(40) << '\n';

    return 0;
}