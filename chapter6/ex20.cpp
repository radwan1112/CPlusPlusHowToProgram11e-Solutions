#include <iostream>
#include <ranges>
#include <vector>

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

    auto values1{std::views::iota(1, 6)};
    showValues(values1, "Generate integers 1-5");

    auto values2{
        values1 | std::views::transform([](const auto &x)
                                        { return x * x * x; })};
    showValues(values2, "Mapping integers to their cubic");

    return 0;
}