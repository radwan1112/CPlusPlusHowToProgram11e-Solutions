#include <iostream>

int main()
{
    int count{1};
    
    while (count <= 10)
    {
        std::cout << (count % 2 == 1 ? "****" : "++++++++") << "\n";
        count++;
    }
    return 0;
}