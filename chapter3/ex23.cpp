#include <iostream>
#include <algorithm>

bool isTriangle(int s1, int s2, int s3)
{
    return (s1 + s2 > s3) && (s1 + s3 > s2) && (s2 + s3 > s1);
}

int main()
{
    double side1{10};
    double side2{6};
    double side3{5};

    std::cout << (isTriangle(side1, side2, side3) ? "is a triangle" : "not a triangle") << std::endl;

    return 0;
}