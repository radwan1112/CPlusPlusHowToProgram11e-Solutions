#include <iostream>
#include <array>
#include <random>
#include <fstream>
#include <string>
#include <iomanip>

template <typename T>
T randomNumberGenerator(T x1, T x2)
{
    std::random_device rd;
    std::mt19937 engine(rd());

    if constexpr (std::is_integral<T>::value)
    {
        std::uniform_int_distribution<T> dist(x1, x2); // Uniform distribution between 10 and 100
        return dist(engine);
    }
    else
    {
        std::uniform_real_distribution<T> dist(x1, x2); // Uniform distribution between 10 and 100
        return dist(engine);
    }
}

void generateSalesData(int sales_persons, int products, int slips)
{
    std::ofstream myfile("sales_data.txt");
    if (!myfile)
    {
        std::cerr << "Unable to open file sales_data.txt";
        return;
    }

    for (int i{0}; i < slips; i++)
    {
        int salesperson_no{randomNumberGenerator(1, 4)};
        int product_no{randomNumberGenerator(1, 5)};
        double monetary_value{randomNumberGenerator(0.0, 100.0)};
        myfile << salesperson_no << " " << product_no << " " << monetary_value << '\n';
    }

    myfile.close();
}

int main()
{
    const int num_of_salespersons{4};
    const int num_of_products{5};
    const int num_of_slips{randomNumberGenerator(1, 1000)};

    generateSalesData(num_of_salespersons, num_of_products, num_of_slips);        // Create txt sales data file to read from
    std::array<std::array<double, num_of_salespersons>, num_of_products> sales{}; // Create a 2d array

    int salesperson_no, product_no;
    double monetary_value{};

    std::ifstream dataFile("sales_data.txt");
    if (dataFile.is_open())
    {
        while (dataFile >> salesperson_no >> product_no >> monetary_value)
        {
            // Check for valid data
            if (salesperson_no < 1 || salesperson_no > num_of_salespersons ||
                product_no < 1 || product_no > num_of_products ||
                monetary_value < 0)
            {
                std::cerr << "Invalid data encountered: "
                          << salesperson_no << " " << product_no << " " << monetary_value << '\n';
                continue; // Skip invalid data
            }
            sales[product_no - 1][salesperson_no - 1] += monetary_value;
        }
    }
    else
    {
        std::cout << "unable to open file";
    }
    dataFile.close();

    // Print the results in tabular format
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(15) << "Product\\Sales";
    for (int i = 0; i < num_of_salespersons; ++i)
    {
        std::cout << std::setw(15) << "Salesperson " << (i + 1);
    }
    std::cout << std::setw(15) << "Product Total" << '\n';

    for (int i = 0; i < num_of_products; ++i)
    {
        double product_total = 0.0;
        std::cout << std::setw(15) << "Product " << (i + 1);
        for (int j = 0; j < num_of_salespersons; ++j)
        {
            std::cout << std::setw(15) << sales[i][j];
            product_total += sales[i][j];
        }
        std::cout << std::setw(15) << product_total << '\n';
    }

    std::cout << std::setw(16) << "Total";
    for (int i = 0; i < num_of_salespersons; ++i)
    {
        double salesperson_total = 0.0;
        for (int j = 0; j < num_of_products; ++j)
        {
            salesperson_total += sales[j][i];
        }
        std::cout << std::setw(15) << salesperson_total;
    }
    std::cout << '\n' << std::endl;

    return 0;
}