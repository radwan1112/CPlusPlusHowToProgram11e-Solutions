#include <iostream>
#include <array>

int recursiveMin(const std::array<int, 12> &numbers, int start, int end)
{
    if (start >= end)
    {
        return numbers[start];
    }
    int min = recursiveMin(numbers, start + 1, end); 
    return std::min(numbers[start], min);
}

int main()
{
    std::array<int, 12> numbers{10, 23, 23, 43, 30, 50, 30, 2, 10, 2, 0, 10};
    std::cout << "Min is " << recursiveMin(numbers, 1, 4) << '\n';
    return 0;
}