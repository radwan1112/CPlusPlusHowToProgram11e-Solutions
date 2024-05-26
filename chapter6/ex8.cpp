#include <iostream>
#include <vector>
#include <random>

bool isValid(const std::vector<int> &numbers, int temp)
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
    std::vector<int> numbers;

    while (numbers.size() < 20) // Continue until the vector has 20 unique numbers
    {
        int temp;
        do
        {
            temp = dist(engine);
        } while (!isValid(numbers, temp));
        numbers.push_back(temp);
    }

    std::cout << std::endl;
    std::cout << "Printing Unique values:" << std::endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers.at(i) << ' '; // Print all unique numbers
    }
    std::cout << std::endl;
}