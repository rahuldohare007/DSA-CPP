#include <bits/stdc++.h>
using namespace std;

// Given two integers a and b, swap them in-place using only 2 variables (without using a temporary variable).
// Can you solve it using:
// Arithmetic operations?
// Bitwise XOR?

// Bitwise XOR
void swap(int &a, int &b)
{
    if (&a == &b)
        return;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// Arithmetic operations
void swap(int &a, int &b)
{
    if (&a == &b)
        return;

    a = a + b;
    b = a - b;
    a = a - b;
}

int main()
{
    int a, b;
    cin >> a >> b;

    swap(a, b);

    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}

// Example 1:
// Input: a = 5, b = 10
// Output: a = 10, b = 5

// Example 2:
// Input: a = -100, b = -200
// Output: a = -200, b = -100

// Time Complexity: O(1)
// Space Complexity: O(1)