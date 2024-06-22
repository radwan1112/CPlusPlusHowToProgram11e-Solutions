#include <iostream>
#include <ranges>
#include <array>
#include <algorithm>
#include <string>
#include <iterator>

int main()
{
    auto showValues{
        [](auto &values, const std::string &message)
        {
            std::cout << message << ": ";
            for (const auto &value : values)
            {
                std::cout << value << " ";
            }
            std::cout << '\n';
        }};

    constexpr int size{15};
    std::array<int, size> numbers;
    std::ranges::copy(std::views::iota(1, 16), numbers.begin());

    showValues(numbers, "Content of array");

    // filter even numbers
    auto evenNumbers{numbers | std::views::filter([](int n)
                                                  { return n % 2 == 0; })};
    showValues(evenNumbers, "Filtering even integers");

    // Map numbers to their square
    auto squareNumbers{numbers | std::views::transform([](const auto &x)
                                                       { return x * x; })};
    showValues(squareNumbers, "Square of numbers");

    // Filter and square
    auto filterThenSquare{
        numbers | std::views::filter([](const auto &x)
                                     { return x % 2 == 0; }) |
        std::views::transform([](const auto &x)
                              { return x * x; })};
    showValues(filterThenSquare, "Squares of even integers");

    return 0;
}