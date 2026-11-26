#include <bits/stdc++.h>
using namespace std;

// Given a non-negative integer n, determine whether it is odd.
// Return true if the number is odd, otherwise return false.
// A number is odd if it is not divisible by 2 (i.e., n % 2 != 0).

bool isOdd(int n)
{
    return (n & 1) != 0;

    // Alternative
    return n % 2 != 0;
}

int main()
{
    int number;
    cin >> number;

    cout << boolalpha << isOdd(number) << endl;

    return 0;
}

// Example 1:
// Input: n = 7
// Output: true
// Explanation: 7 is not divisible by 2. Hence, it is odd.

// Example 2:
// Input: n = 0
// Output: false
// Explanation: 0 is divisible by 2. Hence, it is not odd.

// Time Complexity: O(1)
// Space Complexity: O(1)