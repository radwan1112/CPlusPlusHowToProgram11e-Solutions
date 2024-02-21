#include <iostream>
#include <iomanip>

int main()
{
    std::cout << std::setprecision(2) << std::fixed;
    float commision{0.09};
    float weekly_pay{200};
    while (true)
    {
        float sales{};
        std::cout << "Enter sales in dollars: ";
        std::cin >> sales;
        if (sales == -1)
        {
            break;
        }
        float salary = weekly_pay + (commision * sales);
        std::cout << "Salary is: $" << salary << std::endl;
    }
    return 0;
}