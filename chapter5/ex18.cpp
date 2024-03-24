#include <iostream>

int reverseNumber(int n)
{
    int reverse_n{};
    while (n > 0)
    {
        reverse_n = (reverse_n * 10) + (n % 10);
        n /= 10;
    }
    return reverse_n;
}

int main()
{
    int number{};
    std::cout << "Enter a number: ";
    std::cin >> number;

    std::cout << "Number before: " << number << '\n';
    number = reverseNumber(number);
    std::cout << "Number after: " << number << '\n';

    return 0;
}