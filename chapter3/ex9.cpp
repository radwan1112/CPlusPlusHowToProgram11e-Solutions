#include <iostream>
#include <random>

using u32 = uint_least32_t;
using engine = std::mt19937;

bool isUnique(int (&num_list)[10], int n)
{
    for (int i = 0; i < 10; i++)
    {
        if (num_list[i] == n)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::random_device os_seed;
    const u32 seed = os_seed();

    engine generator(seed);
    std::uniform_int_distribution<u32> distribute(0, 1000);

    int count{0};
    int num_list[10] = {};
    int largest{};
    int second_largest{};

    while (count < 10)
    {
        int num = distribute(generator);
        while (!isUnique(num_list, num))
        {
            num = distribute(generator);
        }
        num_list[count] = num;
        std::cout << "Generated random number: " << num_list[count] << std::endl;
        if (num_list[count] > largest)
        {
            second_largest = largest;
            largest = num_list[count];
        }
        else
        {
            if (num_list[count] > second_largest)
            {
                second_largest = num_list[count];
            }
        }

        count++;
    }

    std::cout << "The largest integer is: " << largest << std::endl;
    std::cout << "The second largest integer is: " << second_largest << std::endl;

    return 0;
}