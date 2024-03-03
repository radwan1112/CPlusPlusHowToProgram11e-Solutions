#include <iostream>

int main()
{
    int max{500};

    std::cout << "Max range: " << max << "\n";
    std::cout << "Valid Pythogorean triples\n\n";

    for (int a = 1; a <= max; a++)
    {
        for (int b = 1; b <= max; b++)
        {
            for (int c = 1; c <= max; c++)
            {
                if ((c * c) == (a * a) + (b * b))
                {
                    std::cout << "(" << a << ", " << b << ", " << c << ")" << '\n';
                }
            }
        }
    }
    return 0;
}