#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

double hypotenuse(double side1, double side2)
{
    return std::sqrt(std::pow(side1, 2) + std::pow(side2, 2));
}

struct Triangle
{
    double side1{};
    double side2{};
    double hypotenuse{};
};

int main()
{
    std::cout << std::setw(10) << "Triangle" << std::setw(10) << "Side 1" << std::setw(10) << "Side 2" << std::setw(12) << "Hypotenuse" << '\n';
    std::vector<Triangle> triangle;

    triangle.push_back({3.0, 4.0});
    triangle.push_back({5.0, 12.0});
    triangle.push_back({8.0, 15.0});

    std::cout << std::fixed << std::setprecision(1);
    for (int i = 0; i < 4; i++)
    {
        std::cout << std::setw(8) << i + 1 << std::setw(10) << triangle[i].side1 << std::setw(10) << triangle[i].side2 << std::setw(12) << hypotenuse(triangle[i].side1, triangle[i].side2) << '\n';
    }
    return 0;
}