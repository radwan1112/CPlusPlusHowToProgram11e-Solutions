#include <iostream>
#include <string>
#include <vector>

bool isUnique(std::string str, const std::vector<std::string> &combinations)
{
    for (const std::string &word : combinations)
    {
        if (word == str)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string word;
    do
    {
        std::cout << "Enter a 5 letter word: ";
        std::cin >> word;
    } while (word.length() != 5);

    std::vector<std::string> combinations;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == i)
                continue;
            for (int k = 0; k < 5; k++)
            {
                if (k == i || k == j)
                    continue;
                std::string three_letter_str = {word[i], word[j], word[k]};
                if (isUnique(three_letter_str, combinations))
                {
                    combinations.push_back(three_letter_str);
                }
            }
        }
    }

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

    std::cout << '\n' << std::endl;

    return 0;
}