#include <iostream>
#include <cmath>

int main()
{
    const double PI = std::acos(-1);
    double radius{};

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    double diameter{radius * 2};
    double circumference{2 * PI * radius};
    double area{PI * std::pow(radius, 2)};

    std::cout << "Diameter: "
              << diameter
              << "\nCircumference: "
              << circumference
              << "\nArea: " << area
              << std::endl;

    return 0;
}