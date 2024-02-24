#include <iostream>
#include <cmath>

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

long double estimate_e(int n)
{
    long double e{};
    for (int i = 0; i < n; i++)
    {
        e += 1 / static_cast<long double>(factorial(i));
    }
    return e;
}

long double estimate_e_raised_to_x(int n, int x)
{
    long double e{};
    for (int i = 0; i < n; i++)
    {
        e += std::pow(x, i) / static_cast<long double>(factorial(i));
    }
    return e;
}

int main()
{

    int option{};

    std::cout << "********* Menu *********\n"
              << std::endl;
    std::cout << "1. Find the factorial of a number" << std::endl;
    std::cout << "2. Estimate euler number" << std::endl;
    std::cout << "3. Estimate e^x" << std::endl;
    std::cout << "\nSelect an option: ";
    std::cin >> option;

    switch (option)
    {
    case 1:
    {
        int n{};
        std::cout << "Enter a number: ";
        std::cin >> n;
        std::cout << n << "! = " << factorial(n) << std::endl;
        break;
    }
    case 2:
    {
        int t{};
        std::cout << "Enter the number of terms: ";
        std::cin >> t;
        std::cout << "Estimating euler number: " << estimate_e(t) << std::endl;
        break;
    }
    case 3:
    {
        int t{};
        int p{};
        std::cout << "Enter the number of terms: ";
        std::cin >> t;
        std::cout << "Enter the value of x: ";
        std::cin >> p;
        std::cout << "Estimating e^x: " << estimate_e_raised_to_x(t, p) << std::endl;
        break;
    }
    default:
        std::cout << "No such option!" << std::endl;
        break;
    }

    return 0;
}