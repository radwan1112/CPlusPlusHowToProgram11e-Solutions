#include <iostream>
#include <string>

void stringRev(const std::string &str, int start)
{
    if (start == str.size())
    {
        return;
    }
    stringRev(str, start + 1);
    std::cout << str[start];
}

int main()
{
    std::string str{"This is a string"};
    int start{4};

    stringRev(str, start);

    return 0;
}