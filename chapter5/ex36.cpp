#include <iostream>
#include <numbers>
#include <cmath>

inline double circleArea(double radius)
{
    return (std::numbers::pi * pow(radius, 2));
}

int main()
{
    double radius{};
    std::cout << "Enter radius of the circle: ";
    std::cin >> radius;
    std::cout << "Area of the circle: " << circleArea(radius) << '\n';
    return 0;
}