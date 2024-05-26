#include <iostream>
#include <random>
#include <array>
#include <iomanip>

int main()
{
    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution coinToss{1, 2};
    constexpr size_t arraySize{3};
    std::array<int, arraySize> frequency{};

    long long int totalFLips{2000000};

    for (int flip{0}; flip < totalFLips; flip++)
    {
        ++frequency.at(coinToss(engine));
    }

    std::cout << std::setw(5) << "Face" << std::setw(15) << "Frequency" << std::setw(15) << "Percentage" << "\n\n";

    for (size_t i{1}; i < frequency.size(); i++)
    {
        std::cout << std::setw(5) << ((i == 1) ? "H" : "T")
                  << std::setw(15) << frequency.at(i)
                  << std::setw(15) << std::fixed << std::setprecision(2)
                  << (frequency.at(i) / static_cast<double>(totalFLips)) * 100 << "%" << '\n';
    }

    return 0;
}