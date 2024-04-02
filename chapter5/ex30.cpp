#include <iostream>
#include <cmath>

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int main()
{
    double x1{4}, x2{-4}, y1{3}, y2{-3};
    std::cout << "Distance between (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ") is "
              << distance(x1, y1, x2, y2) << '\n';

    return 0;
}