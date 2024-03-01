#include <iostream>
#include <string>
#include <sstream>

/* Convert double to string with specified number of places after the decimal. */
std::string prd(const double x, const int decDigits)
{
    std::stringstream ss;
    ss << std::fixed;
    ss.precision(decDigits); // set # places after decimal
    ss << x;
    return ss.str();
}

/* Convert double to string with specified number of places after the decimal
   and left padding. */
std::string left_prd(const double x, const int decDigits, const int width)
{
    std::stringstream ss;
    ss << std::fixed << std::right;
    ss.fill(' ');            // fill space around displayed #
    ss.width(width);         // set  width around displayed #
    ss.precision(decDigits); // set # places after decimal
    ss << x;
    return ss.str();
}

/*! Center-aligns string within a field of width w. Pads with blank spaces
    to enforce alignment. */
std::string center(const std::string s, const int w)
{
    std::stringstream ss, spaces;
    int padding = w - s.size(); // count excess room to pad
    for (int i = 0; i < padding / 2; ++i)
        spaces << " ";
    ss << spaces.str() << s << spaces.str(); // format with padding
    if (padding > 0 && padding % 2 != 0)     // if odd #, add 1 space
        ss << " ";
    return ss.str();
}

/* Right-aligns string within a field of width w. Pads with blank spaces
   to enforce alignment. */
std::string right(const std::string s, const int w)
{
    std::stringstream ss, spaces;
    int padding = w - s.size(); // count excess room to pad
    for (int i = 0; i < padding; ++i)
        spaces << " ";
    ss << spaces.str() << s; // format with padding
    return ss.str();
}

/*! Left-aligns string within a field of width w. Pads with blank spaces
    to enforce alignment. */
std::string left(const std::string s, const int w)
{
    std::stringstream ss, spaces;
    int padding = w - s.size(); // count excess room to pad
    for (int i = 0; i < padding; ++i)
        spaces << " ";
    ss << s << spaces.str(); // format with padding
    return ss.str();
}

long int factorial(int n)
{
    int i{1};
    long int total{1};
    while (i <= n)
    {
        total *= i; 
        i++;
    }
    return total;
}

int main()
{

    std::cout << center("Factorial numbers table", 40) << "\n\n";

    std::cout << center("n", 10) << " | "
              << center("n!", 10) << " | "
              << "\n";
    std::cout << std::string(10 * 2 + 2 * 3, '-') << "\n";

    for (long int i = 1; i < 21; i++)
    {
        std::cout << center(prd(i, 0), 15) << left(left_prd(factorial(i), 0, 0), 30) << '\n';
    }

    return 0;
}