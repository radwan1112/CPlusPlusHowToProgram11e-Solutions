#include <iostream>
#include <string>

int main()
{
    int number{};
    std::string str{};

    std::cout << "Enter a number: ";
    std::cin >> number;

    int n{number};

    while (n != 0)
    {
        str += std::to_string(n % 10);
        n /= 10;
    }

    int reverse_n{std::stoi(str)};

    if (number == reverse_n)
    {
        std::cout << number << " is a Palindrome" << std::endl;
    }
    else
    {
        std::cout << number << " is not a Palindrome" << std::endl;
    }

    return 0;
}