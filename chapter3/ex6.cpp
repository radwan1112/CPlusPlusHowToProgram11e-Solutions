#include <iostream>

int main()
{
    while (true)
    {
        int total_hours{};
        float hourly_rate{};
        std::cout << "Enter hours worked (-1 to end): ";
        std::cin >> total_hours;
        if (total_hours == -1)
        {
            break;
        }
        std::cout << "Enter rate of the employee: ";
        std::cin >> hourly_rate;

        float salary{};

        if (total_hours > 40)
        {
            salary = (40 * hourly_rate) + ((total_hours - 40) * (hourly_rate / 2 + hourly_rate));
        }
        else
        {
            salary = total_hours * hourly_rate;
        }
        std::cout << "Salary is $" << salary << std::endl;
    }
    return 0;
}