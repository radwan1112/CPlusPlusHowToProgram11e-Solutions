#include <iostream>

int tripleByValue(int count)
{
    return 3 * count;
}

void tripleByReference(int &count)
{
    count *= 3;
}

int main()
{
    int count{3};
    std::cout << "Triple by value " << tripleByValue(count) << '\n';
    tripleByReference(count);
    std::cout << "Triple by reference " << count << '\n';
    return 0;
}