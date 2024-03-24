#include <iostream>

double findSmallest(double x, double y, double z)
{
    double smallest{x};
    if (y < smallest)
    {
        smallest = y;
    }
    if (z < smallest)
    {
        smallest = z;
    }
    return smallest;
}

int main()
{
    double num1, num2, num3;
    std::cout << "Enter three decimal numbers: ";
    std::cin >> num1 >> num2 >> num3;
    double smallest = findSmallest(num1, num2, num3);

    std::cout << "The smallest number is: " << smallest << '\n';

    return 0;
}