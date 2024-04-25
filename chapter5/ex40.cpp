#include <iostream>

template <typename T>
T maximum(T a, T b)
{
    return ((a > b) ? a : b);
}

int main()
{
    char a{'a'};
    char b{'b'};

    int n1{10};
    int n2{20};

    float f1{20.3};
    float f2{20.43};

    std::cout << "Between " << a << " and " << b << " , " << maximum(a, b) << " is bigger." << '\n';
    std::cout << "Between " << n1 << " and " << n2 << " , " << maximum(n1, n2) << " is bigger." << '\n';
    std::cout << "Between " << f1 << " and " << f2 << " , " << maximum(f1, f2) << " is bigger." << '\n';

    return 0;
}