#include <random>
#include <iostream>
#include <array>
#include <iomanip>

int main()
{
    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution randomDie{1, 6};
    constexpr size_t arraySize{13};
    std::array<int, arraySize> frequency{}; // Ignore the 0 index

    long long int no_of_rolls{36'000'000};

    for (size_t i{0}; i < no_of_rolls; i++)
    {
        int dice_1{randomDie(engine)};
        int dice_2{randomDie(engine)};
        int sum{dice_1 + dice_2};
        frequency.at(sum) += 1;
    }

    std::cout << std::setw(5) << "Sum" << std::setw(15) << "Frequency" << std::setw(15) << "Percentage" << "\n\n";

    for (size_t i{2}; i < frequency.size(); i++)
    {
        std::cout << std::setw(5) << i
                  << std::setw(15) << frequency.at(i)
                  << std::setw(15) << std::fixed << std::setprecision(5)
                  << (frequency.at(i) / static_cast<double>(no_of_rolls)) * 100 << "%" << '\n';
    }

    return 0;
}