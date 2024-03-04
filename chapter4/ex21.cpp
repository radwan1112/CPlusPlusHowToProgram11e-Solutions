// fig04_08.cpp
// break statement exiting a for statement.
#include <iostream>
using namespace std;
int main()
{
    int count; // control variable also used after loop
    for (count = 1; count <= 10, count < 5; ++count)
    { // loop 10 times
        cout << count << " ";
    }
    cout << "\nBroke out of loop at count = " << count << "\n";
}