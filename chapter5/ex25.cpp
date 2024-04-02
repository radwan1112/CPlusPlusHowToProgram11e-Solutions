#include <iostream>

using namespace std;

long fibonacci(long n);

int main()
{
    for (int counter{0}; counter <= 10; ++counter)
    {
        cout << "fibonacci (" << counter << ") = " << fibonacci(counter) << endl;
    }

    cout << "\nfibonacci (20) = " << fibonacci(20) << endl
         << "fibonacci (30) = " << fibonacci(30) << endl
         << "fibonacci (35) = " << fibonacci(35) << endl;

    return 0;
}

long fibonacci(long n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        long prev{0};
        long curr{1};
        long next{};
        for (int i{1}; i < n; i++)
        {
            next = curr + prev;
            prev = curr;
            curr = next;
        }
        return curr;
    }
}