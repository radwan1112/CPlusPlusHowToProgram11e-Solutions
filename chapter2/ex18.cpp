#include <iostream>

int main()
{

    int a{};
    int b{};
    int c{};
    int d{};
    int e{};

    std::cout << "Enter five integers: ";
    std::cin >> a >> b >> c >> d >> e;

    int largest{a};
    int smallest{a};

    if (b > largest)
    {
        largest = b;
    }
    if (c > largest)
    {
        largest = c;
    }
    if (d > largest)
    {
        largest = d;
    }
    if (e > largest)
    {
        largest = e;
    }
    
    if (b < smallest)
    {
        smallest = b;
    }
    if (c < smallest)
    {
        smallest = c;
    }
    if (d < smallest)
    {
        smallest = d;
    }
    if (e < smallest)
    {
        smallest = e;
    }

    std::cout << largest << " is the largest integer" << std::endl;
    std::cout << smallest << " is the smallest integer" << std::endl;

    return 0;
}