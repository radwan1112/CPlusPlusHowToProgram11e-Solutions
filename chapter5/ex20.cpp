#include <iostream>

int quality_points()
{
    int avg{};
    std::cout << "Enter student average: ";
    std::cin >> avg;

    if (avg >= 90)
    {
        return 4;
    }
    else if (avg >= 80)
    {
        return 3;
    }
    else if (avg >= 70)
    {
        return 2;
    }
    else if (avg >= 60)
    {
        return 1;
    }
    else if (avg < 60)
    {
        return 0;
    }
    else
    {
        std::cout << "invalid input" << '\n';
        return -1;
    }
}

int main()
{
    int grade = quality_points();

    std::cout << "returned value " << grade << '\n';

    return 0;
}