#include <iostream>
#include <cmath>
#include <iomanip>

int roundToInteger(double x)
{
    return floor(x + 0.5);
}

double roundToTenths(double x)
{
    return floor(x * 10 + 0.5) / 10;
}

double roundToHundredths(double x)
{
    return floor(x * 100 + 0.5) / 100;
}

double roundToThousandths(double x)
{
    return floor(x * 1000 + 0.5) / 1000;
}

int main()
{
    int array_size{5};
    double numbers[array_size];

    int i{};
    while (i < array_size)
    {
        double x{};
        std::cout << "Enter a number: ";
        std::cin >> numbers[i];
        std::cout << "Original number: " << std::fixed << numbers[i] << '\n';
        std::cout << "Rounded to integer: " << roundToInteger(numbers[i]) << '\n';
        std::cout << "Rounded to tenths: " << roundToTenths(numbers[i]) << '\n';
        std::cout << "Rounded to hundredths: " << roundToHundredths(numbers[i]) << '\n';
        std::cout << "Rounded to thousandths: " << roundToThousandths(numbers[i]) << '\n';
        i++;
    }
    return 0;
}