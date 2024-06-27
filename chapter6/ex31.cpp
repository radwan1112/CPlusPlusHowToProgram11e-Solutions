#include <iostream>
#include <vector>

void printVector(const std::vector<int> &n, int start, int end)
{
    if (start == end)
        return;
    std::cout << n[start] << " ";
    printVector(n, start + 1, end);
}

int main()
{
    std::vector<int> numbers({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    int start{}, end{};
    std::cout << "Enter start index: ";
    std::cin >> start;
    std::cout << "Enter end index: ";
    std::cin >> end;

    printVector(numbers, start, end);

    return 0;
}