#include <iostream>

int main()
{
    int n[5] = {};
    std::cout << "Enter five numbers between 1 - 30: ";
    std::cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n[i]; j++)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}