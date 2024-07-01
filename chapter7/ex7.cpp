#include <iostream>
#include <array>
#include <vector>
#include <span>

void displaySpan(std::span<const int> items)
{
    for (const auto &item : items)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void cubeElements(std::span<int> items)
{
    for (int &item : items)
    {
        item *= item * item;
    }
}

int main()
{
    int values1[]{1, 2, 3, 4, 5};
    std::array values2{6, 7, 8, 9, 10};
    std::vector values3{11, 12, 13, 14, 15};

    std::cout << "values 1: ";
    displaySpan(values1);
    std::cout << "values 2: ";
    displaySpan(values2);
    std::cout << "values 3: ";
    displaySpan(values3);

    cubeElements(values1);
    cubeElements(values2);
    cubeElements(values3);

    std::cout << "After cube operation\n";

    std::cout << "values 1: ";
    displaySpan(values1);
    std::cout << "values 2: ";
    displaySpan(values2);
    std::cout << "values 3: ";
    displaySpan(values3);
}