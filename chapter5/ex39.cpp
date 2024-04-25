#include <iostream>

template <typename T>
T minimum(T a, T b)
{
    return ((a < b) ? a : b);
}

int main()
{
    char a{'a'};
    char b{'b'};

    int n1{10};
    int n2{20};

    float f1{20.3};
    float f2{20.43};

    std::cout << "Between " << a << " and " << b << " , " << minimum(a, b) << " is the smaller." << '\n';
    std::cout << "Between " << n1 << " and " << n2 << " , " << minimum(n1, n2) << " is the smaller." << '\n';
    std::cout << "Between " << f1 << " and " << f2 << " , " << minimum(f1, f2) << " is the smaller." << '\n';

    return 0;
}