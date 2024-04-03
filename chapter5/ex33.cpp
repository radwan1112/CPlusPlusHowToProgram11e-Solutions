#include <iostream>
#include <cmath>
#include <numbers>

int main()
{
    int x{2};
    int y{4};

    std::cout << "cmath \n";
    std::cout << ceil(x) << '\n';
    std::cout << cos(x) << '\n';
    std::cout << exp(x) << '\n';
    std::cout << fabs(x) << '\n';
    std::cout << floor(x) << '\n';
    std::cout << fmod(x, y) << '\n';
    std::cout << log(x) << '\n';
    std::cout << log10(x) << '\n';
    std::cout << pow(x, y) << '\n';
    std::cout << sin(x) << '\n';
    std::cout << sqrt(x) << '\n';
    std::cout << tan(x) << '\n';
    std::cout << ceil(x) << '\n';
    std::cout << ceil(x) << '\n';
    std::cout << ceil(x) << '\n';

    std::cout << "numbers \n";
    std::cout << std::numbers::e << '\n';
    std::cout << std::numbers::log2e << '\n';
    std::cout << std::numbers::log10e << '\n';
    std::cout << std::numbers::ln2 << '\n';
    std::cout << std::numbers::ln10 << '\n';
    std::cout << std::numbers::pi << '\n';
    std::cout << std::numbers::inv_pi << '\n';
    std::cout << std::numbers::inv_sqrtpi << '\n';
    std::cout << std::numbers::sqrt2 << '\n';
    std::cout << std::numbers::sqrt3 << '\n';
    std::cout << std::numbers::inv_sqrt3 << '\n';
    std::cout << std::numbers::egamma << '\n';
    std::cout << std::numbers::phi << '\n';

    return 0;
}