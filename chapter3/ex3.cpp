#include <iostream>
#include <iomanip>

int main()
{

    int total_miles{0};
    int total_gallons{0};
    double total_miles_per_gallon{0};
    int miles{0};

    std::cout << std::setprecision(6) << std::fixed;

    while (miles != -1)
    {
        int gallons{};
        long double miles_per_gallon{};
        std::cout << "Enter miles driven (-1 to quit): ";
        std::cin >> miles;
        if (miles == -1)
            break;
        std::cout << "Enter gallons used: ";
        std::cin >> gallons;
        miles_per_gallon = static_cast<double>(miles) / gallons;
        total_gallons += gallons;
        total_miles += miles;
        total_miles_per_gallon = static_cast<double>(total_miles) / total_gallons;
        std::cout << "MPG this trip: " << miles_per_gallon << std::endl;
        std::cout << "Total MPG: " << total_miles_per_gallon << std::endl;
        std::cout << std::endl;
    }

    return 0;
}