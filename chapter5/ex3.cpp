#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

int main()
{
    std::vector<float> numbers;

    int i{};
    while (i < 5)
    {
        float x{};
        std::cout << "Enter a number: ";
        std::cin >> x;
        numbers.push_back(std::floor(x + 0.5));
        std::cout << std::fixed << std::setprecision(2) << "Original number: " << x << " | Rounded number: " << numbers[i] << '\n';
        i++;
    }
    return 0;
}