#include <numbers> // std::numbers
#include <iomanip>
#include <iostream>

int main()
{
	std::cout << std::fixed << std::setprecision(20);
	std::cout << "float       " << std::numbers::pi_v<float> << std::endl;
	std::cout << "double      " << std::numbers::pi << std::endl;
	std::cout << "long double " << std::numbers::pi_v<long double> << std::endl;
	std::cout << "exact       "
			  << "3.141592653589793238462643383279502884197169399375105820974944" << std::endl;
}