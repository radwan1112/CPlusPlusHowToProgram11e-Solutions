#include <iostream>
#include <random>

using u32 = uint_least32_t;
using engine = std::mt19937;

int main()
{
    std::random_device os_seed;
    const u32 seed = os_seed();

    engine generator(seed);
    std::uniform_int_distribution<u32> distribute(0, 5);

    int count{0};
    int num_list[10] = {};
    int largest{};

    while (count < 10)
    {
        num_list[count] = distribute(generator);
        std::cout << "Generated random number: " << num_list[count] << std::endl;
        if (num_list[count] > largest)
        {
            largest = num_list[count];
        }
        count++;
    }

    std::cout << "The largest integer is: " << largest << std::endl;

    return 0;
}