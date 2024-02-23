#include <iostream>

long int factorial(int n)
{
    if (n < 0)
    {
        std::cout << "invalid input, number needs to be > 0" << std::endl;
        return -1;
    }
    if (n == 0)
    {
        return 1;
    }
    long int nfactorial{1};
    while (n > 0)
    {
        nfactorial *= (n);
        n--;
    }
    return nfactorial;
}

int main()
{

    int option{};

    std::cout << "********* Menu *********\n"
              << std::endl;
    std::cout << "1. Find the factorial of a number" << std::endl;
    std::cout << "2. Find";
    std::cout << "\nSelect an option: " << std::endl;
    std::cin >> option;
        int n{};

    switch (option)
    {
    case 1:
        std::cout << "Enter a number" << std::endl;
        std::cin >> n;
        std::cout << n << "! = " << factorial(n) << std::endl;
        break;
    default:
        std::cout << "No such option!" << std::endl;
        break;
    }

    return 0;
}