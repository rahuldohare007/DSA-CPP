#include <bits/stdc++.h>
using namespace std;

// Given two integers n and i, return true if the ith bit in the binary representation of n (counting from the least significant bit, 0-indexed) is set (i.e., equal to 1). Otherwise, return false.

bool checkIthBit(int n, int i)
{
    return (n & (1U << i)) != 0;

    // Alternative
    return ((static_cast<unsigned int>(n) >> i) & 1) != 0;
}

int main()
{
    int n, i;

    cout << "Enter n and i: ";
    cin >> n >> i;

    cout << boolalpha << checkIthBit(n, i) << endl;

    return 0;
}

// Example 1:
// Input: n = 5, i = 0
// Output: true
// Explanation: Binary representation of 5 is 101. The 0-th bit from LSB is set (1).

// Example 2:
// Input: n = 10, i = 1
// Output: true
// Explanation: Binary representation of 10 is 1010. The 1-st bit from LSB is set (1).

// Time Complexity: O(1)
// Space Complexity: O(1)