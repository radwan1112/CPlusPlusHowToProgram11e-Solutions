#include <iostream>
#include <ranges>
#include <vector>
#include <numeric>

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

    auto values1{std::views::iota(1, 11)};
    showValues(values1, "Generate integers 1-10");

    auto values2{values1 | std::views::filter([](const auto &x)
                                              { return x % 2 == 0; })};
    showValues(values2, "Filtering even integers");

    auto values3{values2 | std::views::transform([](const auto &x)
                                                 { return x * 3; })};
    showValues(values3, "Mapping even integers to their times 3 form");

    std::cout << "Sum of triples of even integers: " << std::accumulate(std::begin(values3), std::end(values3), 0) << '\n';

    return 0;
}