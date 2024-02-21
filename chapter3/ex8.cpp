#include <iostream>

int main()
{
    std::cout << "N\t10*N\t100*N\t1000*N\n"
              << std::endl;

    for (int i = 1; i < 6; i++)
    {
        std::cout << i << "\t" << 10 * i << '\t' << 100 * i << '\t' << 1000 * i << std::endl;
    }

    return 0;
}