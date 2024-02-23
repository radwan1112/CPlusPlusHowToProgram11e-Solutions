#include <iostream>
#include <cmath>

int main()
{
    int i{1};
    //infinte loop
    while (true)
    {
        std::cout << std::pow(2, i) << std::endl;
        i++;
    }

    return 0;
}