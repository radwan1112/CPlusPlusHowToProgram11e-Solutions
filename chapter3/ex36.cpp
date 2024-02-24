#include <iostream>
#include <algorithm>

int encrypt(int n)
{
    int digits[4] = {};
    for (int i = 0; i < 4; i++)
    {
        digits[i] = ((n % 10) + 7) % 10;
        n /= 10;
    }
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);
    n = 0;
    for (int i = 0; i < 4; i++)
    {
        n *= 10;
        n += digits[i];
    }
    return n;
}

int decrypt(int n)
{
    int digits[4] = {};
    for (int i = 0; i < 4; i++)
    {
        digits[i] = n % 10;
        n /= 10;
    }
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);
    for (int i = 0; i < 4; i++)
    {
        if (digits[i] > 7)
        {
            digits[i] = digits[i] - 7;
        }
        else
        {
            digits[i] = (digits[i] + 10) - 7;
        }
    }
    n = 0;
    for (int i = 0; i < 4; i++)
    {
        n *= 10;
        n += digits[i];
    }
    return n;
}

int main()
{
    int n{};
    std::cout << "Enter a four digit integer: ";
    std::cin >> n;
    while (n < 1000 || n > 9999)
    {
        std::cout << "Invalid input!" << std::endl;
        std::cout << "Enter a four digit integer: ";
        std::cin >> n;
    }

    n = encrypt(n);
    std::cout << "Encrypted integer: " << n << std::endl;
    n = decrypt(n);
    std::cout << "Decrypted integer: " << n << std::endl;

    return 0;
}