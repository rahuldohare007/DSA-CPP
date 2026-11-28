#include <bits/stdc++.h>
using namespace std;

// You are given a positive integer n.
// Your task is to set the rightmost unset bit (0 bit) in the binary representation of n.
// Setting a bit means changing it from 0 to 1. Return the resulting integer after performing the operation.

int setRightmostUnsetBit(int n)
{
    if ((n & (n + 1)) == 0)
        return n;

    return n | (n + 1);
}

int main()
{
    int number;
    cin >> number;

    cout << setRightmostUnsetBit(number) << endl;

    return 0;
}

// Example 1:
// Input: n = 10
// Output: 11
// Explanation: 10 is 1010 in binary. The rightmost 0 bit is set to 1, producing 1011, which is 11.

// Example 2:
// Input: n = 13
// Output: 15
// Explanation: 13 is 1101. Its rightmost unset bit is changed to 1: 1101 -> 1111. Therefore, the result is 15.

// Time Complexity: O(1)
// Space Complexity: O(1)