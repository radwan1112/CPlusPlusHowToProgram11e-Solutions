#include <iostream>
#include <cmath>
#include <iomanip>

struct Customer
{
	int no{};
	float hours{};
	float charge{};
};

float calculate_charge(float hours)
{
	if (hours > 0 && hours <= 3)
	{
		return 20.00;
	}
	if (hours > 9)
	{
		return 50.00;
	}

	return 20.00 + (5.00 * ceil(hours - 3));
}

int main()
{
	int no_customers{3};
	Customer customer[no_customers];

	int i{};
	while (i < no_customers)
	{
		customer[i].no = i + 1;
		std::cout << "Cutomer no " << customer[i].no << '\n';
		std::cout << "Enter the hours parked: ";
		std::cin >> customer[i].hours;
		customer[i].charge = calculate_charge(customer[i].hours);
		i++;
	}

	std::cout << '\n';
	std::cout << "Cars \t Hours \t Charge" << '\n';

	float total_charge{};
	float total_hours{};
	std::cout << std::fixed;
	for (int i = 0; i < no_customers; i++)
	{
		std::cout << i + 1 << " \t " << std::setprecision(1) << customer[i].hours << " \t " << std::setprecision(2) << customer[i].charge << std::endl;
		total_hours += customer[i].hours;
		total_charge += customer[i].charge;
	}
	std::cout << "Total \t " << std::setprecision(1) << total_hours << " \t " << std::setprecision(2) << total_charge << '\n';

	return 0;
}