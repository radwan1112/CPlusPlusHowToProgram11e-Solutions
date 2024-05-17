#include <iostream>
#include <array>

int main()
{
    std::array<int, 10> salespersons{5000, 1000, 500, 0, 600, 20000, 9000, 40000, 100000, 6000};
    int base_salary{200};
    float commision{1.09};
    std::array<int, 9> range_counter{};
    int total{};

    for (const int &salesperson : salespersons)
    {
        total = base_salary + (salesperson * commision);
        if (total >= 200 && total < 300)
        {
            range_counter[0] += 1;
        }
        else if (total >= 300 && total < 400)
        {
            range_counter[1] += 1;
        }
        else if (total >= 400 && total < 500)
        {
            range_counter[2] += 1;
        }
        else if (total >= 500 && total < 600)
        {
            range_counter[3] += 1;
        }
        else if (total >= 600 && total < 700)
        {
            range_counter[4] += 1;
        }
        else if (total >= 700 && total < 800)
        {
            range_counter[5] += 1;
        }
        else if (total >= 800 && total < 900)
        {
            range_counter[6] += 1;
        }
        else if (total >= 900 && total < 1000)
        {
            range_counter[7] += 1;
        }
        else if (total >= 1000)
        {
            range_counter[8] += 1;
        }
        else
        {
            std::cout << "Error" << '\n';
        }
    }

    int lower_bound{200};
    int upper_bound{299};
    for (const int &range : range_counter)
    {
        if (lower_bound >= 1000)
        {
            std::cout << "$" << lower_bound << " and over: " << range << '\n';
        }
        else
        {
            std::cout << "$" << lower_bound << "-" << upper_bound << ": " << range << '\n';
            lower_bound += 100;
            upper_bound += 100;
        }
    }

    return 0;
}