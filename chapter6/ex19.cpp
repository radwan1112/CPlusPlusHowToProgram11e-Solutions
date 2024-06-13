#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

std::vector<std::string> digitToLetters = {
    "",
    "",
    "ABC",
    "DEF",
    "GHI",
    "JKL",
    "MNO",
    "PQRS",
    "TUV",
    "WXYZ"};

bool inValid(std::string number)
{
    if (number.length() != 7)
    {
        return true;
    }

    for (char digit : number)
    {
        if (digit < '2' || digit > '9')
        {
            return true;
        }
    }
    return false;
}

void generateWords(std::vector<std::string> &combinations, const std::string &phoneNumber, std::string currentWord, int index)
{
    if (index == phoneNumber.length())
    {
        combinations.push_back(currentWord);
        return;
    }

    int digit = phoneNumber[index] - '0';
    const std::string &letters = digitToLetters[digit];

    for (char letter : letters)
    {
        generateWords(combinations, phoneNumber, currentWord + letter, index + 1);
    }
}

int main()
{
    std::string number;
    do
    {
        std::cout << "Enter a 7 digit number: ";
        std::cin >> number;
    } while (inValid(number));
    std::vector<std::string> combinations;
    generateWords(combinations, number, "", 0);

    int i = 0;
    for (const std::string &word : combinations)
    {
        if (i % 4 == 0)
        {
            std::cout << '\n';
        }
        std::cout << word << '\t';
        i++;
    }
    
    std::cout << "Their are total " << i << " words" << '\n'
              << std::endl;

    return 0;
}