#include <iostream>

int main()
{

    int passes{0};
    int failures{0};
    int studentCounter{1};

    while (studentCounter <= 10)
    {
        std::cout << "Enter result(1 = pass, 2 = fail): ";
        int result{};
        std::cin >> result;

        while (result != 1 && result != 2)
        {
            std::cout << "Invalid input!" << std::endl;
            std::cout << "Enter result(1 = pass, 2 = fail): ";
            std::cin >> result;
        }

        if (result == 1)
        {
            passes++;
        }
        else
        {
            failures++;
        }
        studentCounter++;
    }

    std::cout << "Passed: " << passes << "\nFailed: " << failures << std::endl;

    if (passes > 8)
    {
        std::cout << "Bonus to instructor!" << std::endl;
    }

    return 0;
}