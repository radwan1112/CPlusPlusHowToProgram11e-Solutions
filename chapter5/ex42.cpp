#include <iostream>

int main()
{
    enum class AccountType
    {
        savings,
        checking,
        investment
    };
    AccountType account = AccountType::savings; // Assigning the savings enum value to the account variable
    std::cout << static_cast<int>(account);     // This will print out the integer value of the enumerator
    return 0;
}