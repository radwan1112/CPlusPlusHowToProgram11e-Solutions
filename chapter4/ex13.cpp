#include <iostream>

int main()
{
    char option{};
    int product_num{}, quantity{};
    double total_value{};

    do
    {
        std::cout << "Enter product number and quantity: ";
        std::cin >> product_num >> quantity;

        switch (product_num)
        {
        case 1:
            total_value += 2.98 * quantity;
            break;
        case 2:
            total_value += 4.50 * quantity;
            break;
        case 3:
            total_value += 9.98 * quantity;
            break;
        case 4:
            total_value += 4.49 * quantity;
            break;
        case 5:
            total_value += 6.87 * quantity;
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
            break;
        }
        std::cout << "Add a new product(y/n): ";
        std::cin >> option;
    } while (option == 'y');

    std::cout << "Total cost: " << total_value << '\n';

    return 0;
}