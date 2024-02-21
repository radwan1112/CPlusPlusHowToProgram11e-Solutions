#include <iostream>
#include <iomanip>

int main()
{

    std::cout << std::setprecision(2) << std::fixed;

    int account{};
    while (account != -1)
    {
        std::cout << "Enter account number: ";
        std::cin >> account;

        if (account == -1)
        {
            break;
        }

        float balance{};
        std::cout << "Enter beginning balance: ";
        std::cin >> balance;

        float total_charges{};
        std::cout << "Enter total charges: ";
        std::cin >> total_charges;

        float total_credit{};
        std::cout << "Enter total credits: ";
        std::cin >> total_credit;

        float credit_limit{};
        std::cout << "Enter credit limit: ";
        std::cin >> credit_limit;

        float new_balance{balance + total_charges - total_credit};
        std::cout << "New balance is " << new_balance << std::endl;

        if (new_balance > credit_limit)
        {
            std::cout << "Account: " << account << std::endl;
            std::cout << "Credit limit: " << credit_limit << std::endl;
            std::cout << "Balance: " << balance << std::endl;
            std::cout << "Credit Limit Exceeded" << std::endl;
        }
    }
    return 0;
}