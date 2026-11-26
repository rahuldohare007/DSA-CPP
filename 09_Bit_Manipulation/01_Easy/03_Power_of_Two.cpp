#include <bits/stdc++.h>
using namespace std;

// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2x.

bool isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

// Alternative - Repeated Division
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    while (n % 2 == 0)
    {
        n /= 2;
    }

    return n == 1;
}
// Time Complexity: O(log n)
// Space Complexity: O(1)

int main()
{
    int number;
    cin >> number;

    cout << boolalpha << isPowerOfTwo(number) << endl;

    return 0;
}

// Example 1:
// Input: n = 1
// Output: true
// Explanation: 20 = 1

// Example 2:
// Input: n = 16
// Output: true
// Explanation: 24 = 16

// Example 3:
// Input: n = 3
// Output: false

// Time Complexity: O(1)
// Space Complexity: O(1)