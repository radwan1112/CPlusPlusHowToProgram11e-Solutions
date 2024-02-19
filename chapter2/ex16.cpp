#include <iostream>
#include <cmath>

int main()
{

    const double PI{std::acos(-1.0)};

    std::cout << "Enter the circle radius: " << std::endl;
    int radius{};
    std::cin >> radius;

    int diameter{2 * radius};
    double circumference{2 * PI * static_cast<double>(radius)};
    double area{PI * static_cast<double>(std::pow(radius, 2))};

    std::cout << "Diameter: " << diameter << std::endl;
    std::cout << "Circumference: " << circumference << std::endl;
    std::cout << "Area: " << area << std::endl;

    return 0;
}