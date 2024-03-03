#include <iostream>
#include <iomanip>

int main()
{
    int accuracy{1000000};
    std::cout << "Accuracy set at: " << accuracy << "\n\n";
    long double pi{};

    std::cout << "term \t\t" << "pi \n";

    for (int i = 0; i < accuracy; i++)
    {
        std::cout << i + 1 << "\t\t";
        if (i % 2)
        {
            pi -= 4.0 / (2.0 * i + 1.0);
        }
        else
        {
            pi += 4.0 / (2.0 * i + 1.0);
        }
        std::cout << std::fixed << std::setprecision(9) << pi << '\n';
    }

    return 0;
}