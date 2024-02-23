#include <iostream>
#include <algorithm>
#include <cmath>

bool isRightTriangle(int s1, int s2, int s3)
{
    s1 = std::pow(s1, 2);
    s2 = std::pow(s2, 2);
    s3 = std::pow(s3, 2);

    int hypotenuse{std::max({s1, s2, s3})};
    int sum_other_2_sides = s1 + s2 + s3 - hypotenuse;

    return (hypotenuse == sum_other_2_sides);
}

int main()
{
    int side1{14};
    int side2{48};
    int side3{50};

    std::cout << ((isRightTriangle(side1, side2, side3))? "is right angle triangle" : "not a right angle triangle") << std::endl;

    return 0;
}