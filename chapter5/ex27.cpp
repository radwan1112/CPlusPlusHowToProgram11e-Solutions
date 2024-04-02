#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <algorithm>

void displayColumns(std::stack<int> columnOne, std::stack<int> columnTwo, std::stack<int> columnThree);

void moveDisk(std::stack<int> &s1, std::stack<int> &s2)
{
    if (s2.empty() || (!s1.empty() && s1.top() < s2.top()))
    {
        s2.push(s1.top());
        s1.pop();
    }
    else
    {
        moveDisk(s2, s1);
    }
}

void solveTower(int n, std::stack<int> &source, std::stack<int> &aux, std::stack<int> &dest, char a, char b, char c)
{
    int totalMoves{static_cast<int>(std::pow(2, n) - 1)};
    if (n % 2 == 0)
    {
        std::swap(dest, aux);
    }

    for (int i{1}; i <= totalMoves; i++)
    {
        if (i % 3 == 0)
        {
            moveDisk(aux, dest);
            displayColumns(source, aux, dest);
        }
        else if (i % 3 == 1)
        {
            moveDisk(source, dest);
            displayColumns(source, aux, dest);
        }
        else
        {
            moveDisk(source, aux);
            displayColumns(source, aux, dest);
        }
    }
}

int main()
{
    std::stack<int> source, destination, auxiliary;
    int disks{3};
    for (int i{disks}; i > 0; i--)
    {
        source.push(i);
    }

    solveTower(disks, source, auxiliary, destination, 'A', 'B', 'C');

    return 0;
}

void displayColumns(std::stack<int> columnOne,
                    std::stack<int> columnTwo,
                    std::stack<int> columnThree)
{

    // Holds the value of which 'row' is currently being read.
    // This is set to whichever column is the largest.
    int currentRow = 0;

    // If columnOne is larger than columnTwo and columnThree.
    if ((columnOne.size() >= columnTwo.size()) && (columnOne.size() >= columnThree.size()))
    {
        // Set currentRow to be equal to the size of columnOne.
        currentRow = columnOne.size();
    }
    // Else if, columnTwo is larger than columnOne and columnThree.
    else if ((columnTwo.size() >= columnOne.size()) && (columnTwo.size() >= columnThree.size()))
    {
        // Set currentRow to be equal to the size of columnTwo.
        currentRow = columnTwo.size();
    }
    // Else, by process of elimination, columnThree must be the largest.
    else
    {
        // Set currentRow to be equal to the soze of columnThree.
        currentRow = columnThree.size();
    }

    // Formatting for the console.
    std::cout << "-------------------" << std::endl;

    // While our current row is not equal to zero, then continue
    // to loop. Everything within this loop is printed on the same
    // line, the loop is to format each line individually.
    while (currentRow != 0)
    {

        // Formatting for the console.
        std::cout << "|  ";

        // If columnOne is equal in size to the currentRow, output the
        // top of the column then delete the top element.
        if (columnOne.size() == currentRow)
        {
            // Display the top element to the console.
            std::cout << columnOne.top();
            // Pop off the top element.
            columnOne.pop();
        }
        else
        {
            // Add a single space to help keep the columns the same size.
            std::cout << " ";
        }

        // Formatting for the console.
        std::cout << "  |  ";

        // If columnTwo is equal in size to the currentRow, output the
        // top of the column then delete the top element.
        if (columnTwo.size() == currentRow)
        {
            // Display the top element to the console.
            std::cout << columnTwo.top();
            // Pop off the top element.
            columnTwo.pop();
        }
        else
        {
            // Add a single space to help keep the columns the same size.
            std::cout << " ";
        }

        // Formatting for the console.
        std::cout << "  |  ";

        // If columnThree is equal in size to the currentRow, output the
        // top of the column then delete the top element.
        if (columnThree.size() == currentRow)
        {
            // Display the top element to the console.
            std::cout << columnThree.top();
            // Pop off the top element.
            columnThree.pop();
        }
        else
        {
            // Add a single space to help keep the columns the same size.
            std::cout << " ";
        }

        // Formatting for the console.
        std::cout << "  |";

        // Create a new line.
        std::cout << std::endl;

        // Subtract one from currentRow.
        --currentRow;
    }

    // Formatting for the console.
    std::cout << "-------------------" << std::endl;
    std::cout << "   A     B     C   " << std::endl;

    // Nothing left to do, so this function is over. return 0;
}