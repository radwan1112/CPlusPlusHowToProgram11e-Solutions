#include <iostream>
#include <iomanip>

int fahrenheit_to_celsius(int f)
{
    return ((f - 32) * 5 / 9);
}

int celsius_to_fahrenheit(int c)
{
    return ((9 / 5 * c) + 32);
}

int main()
{

    std::cout << std::left << std::setw(11) << "Celsius" << std::setw(11) << "Fahrenheit" << '\n';

    for (int i = 0; i <= 100; i++)
    {
        std::cout << std::left << std::setw(11) << i << std::setw(11) << celsius_to_fahrenheit(i) << '\n';
    }

    std::cout << '\n';

    std::cout << std::left << std::setw(11) << "Fahrenheit" << std::setw(11) << "Celsius" << '\n';

    for (int i = 32; i <= 212; i++)
    {
        std::cout << std::left << std::setw(11) << i << std::setw(11) << fahrenheit_to_celsius(i) << '\n';
    }

    return 0;
}