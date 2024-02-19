#include <iostream>

int main(){

    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << x << " is an " << ((x % 2)? "Odd":"Even") << " number" << std::endl;


}