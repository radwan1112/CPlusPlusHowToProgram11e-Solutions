#include <iostream>
#include <algorithm>

int main()
{

    std::cout << "Input three different integers: ";
    int x{};
    int y{};
    int z{};

    std::cin >> x >> y >> z;

    std::cout << "Sum is " << x + y + z << std::endl;
    std::cout << "Average is " << (x + y + z) / 3 << std::endl;
    std::cout << "Product is " << x * y * z << std::endl;

    std::cout << "Smallest is " << std::min({x, y, z}) << std::endl;
    std::cout << "Largest is " << std::max({x, y, z}) << std::endl;
    
    return 0;
}