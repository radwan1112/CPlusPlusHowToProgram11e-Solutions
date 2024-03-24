#include <iostream>
#include <cmath>

struct Time
{
    int hours{};
    int min{};
    int sec{};
};

int seconds_since_12(int hours, int min, int sec)
{
    return ((hours % 12) * 3600 + (min * 60) + sec);
}

int main()
{
    Time time1;
    Time time2;

    std::cout << "Enter the first time as hr min sec: ";
    std::cin >> time1.hours >> time1.min >> time1.sec;

    std::cout << "Enter the second time as hr min sec: ";
    std::cin >> time2.hours >> time2.min >> time2.sec;

    int time_difference = std::abs(seconds_since_12(time1.hours, time1.min, time1.sec) - seconds_since_12(time2.hours, time2.min, time2.sec));

    std::cout << "Total seconds between " << time1.hours << " : " << time1.min << " : " << time1.sec << " and "
              << time2.hours << " : " << time2.min << " : " << time2.sec << " is " << time_difference << '\n';

    return 0;
}