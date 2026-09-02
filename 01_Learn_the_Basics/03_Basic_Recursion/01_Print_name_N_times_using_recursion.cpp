#include <bits/stdc++.h>
using namespace std;

// Iterative Approach
void printNameNTimes_iterative(string name, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << name << endl;
    }
}

// Recursive Approach
void printNameNTimes_recursive(string name, int n)
{
    if (n <= 0)
    {
        return;
    }
    cout << name << endl;
    printNameNTimes(name, n - 1);
}

int main()
{
    string name;
    int n;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter the number of times to print your name: ";
    cin >> n;

    cout << "Printing name using Iterative Approach:" << endl;
    printNameNTimes_iterative(name, n);

    cout << "Printing name using Recursive Approach:" << endl;
    printNameNTimes_recursive(name, n);

    return 0;
}

// Iterative Approach
// Time Complexity: O(n)
// Space Complexity: O(1)

// Recursive Approach
// Time Complexity: O(n)
// Space Complexity: O(n) (due to recursion stack)