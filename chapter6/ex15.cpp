#include <iostream>
#include <array>
#include <stdexcept>

template <typename T, std::size_t N>             // note that this template parameter declaration matches the one for std::array
void outputArray(const std::array<T, N> &items); // display the array
template <typename T, std::size_t N>             // note that this template parameter declaration matches the one for std::array
void inputArray(std::array<T, N> &items);        // input values into the array

int main()
{
    std::array<int, 7> integers1{};  // 7-element array<int>
    std::array<int, 10> integers2{}; // 10-element array<int>

    // print integers1 size and contents
    std::cout << "Size of array integers1 is " << integers1.size() << "\narray after initialization: ";
    outputArray(integers1);

    // print integers2 size and contents
    std::cout << "\nSize of array integers2 is " << integers2.size() << "\narray after initialization: ";
    outputArray(integers2);

    std::cout << "\nEnter 17 integers: \n";
    inputArray(integers1);
    inputArray(integers2);

}

template <typename T, std::size_t N>
void outputArray(const std::array<T, N> &items)
{
    for (const int &item : items)
    {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}

template <typename T, std::size_t N>
void inputArray(std::array<T, N> &items)
{
    for (int &item : items)
    {
        std::cin >> item;
    }
}