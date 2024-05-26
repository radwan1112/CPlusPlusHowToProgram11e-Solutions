#include <iostream>
#include <array>
#include <random>

bool isValid(const std::array<int, 20> &numbers, int temp)
{
    for (const int &number : numbers)
    {
        if (number == 0)
        {
            break;
        }
        if (temp == number)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(10, 100); // Uniform distribution between 10 and 100
    std::array<int, 20> numbers{};

    for (int &number : numbers)
    {
        int temp = dist(engine);
        std::cout << temp << ' ';
        while (!isValid(numbers, temp))
        {
            temp = dist(engine);
        }
        number = temp;
    }
    std::cout << std::endl;
    std::cout << "Printing Unique values" << '\n';
    for (const int &number : numbers)
    {
        std::cout << number << ' ';
    }
    std::cout << std::endl;
    return 0;
}