#include <iostream>
#include <string>
#include <array>

bool testPalindrome(const std::string &str, int i)
{
    if (i > str.size() / 2)
    {
        return true;
    }
    return str[i] == str[str.size() - i - 1] && testPalindrome(str, i + 1);
}

int main()
{
    std::string str;
    std::cout << "Enter a string: ";
    std::cin >> str;

    if (testPalindrome(str, 0))
    {
        std::cout << "String is a palindrome" << '\n';
    }
    else
    {
        std::cout << "String is NOT a palindrome" << '\n';
    }

    return 0;
}