#include <iostream>

int main()
{
    std::cout << "Enter two integers: ";
    int x{};
    int y{};
    std::cin >> x >> y;

    if(x == y){
        std::cout << "These numbers are equal" << std::endl;
    }
    else if(x > y){
        std::cout << x << " is larger" << std::endl;
    }
    else{
        std::cout << y << " is larger" << std::endl;
    }
}