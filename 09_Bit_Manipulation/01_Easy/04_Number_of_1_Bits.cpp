#include <bits/stdc++.h>
using namespace std;

// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

// Bitwise AND
int hammingWeight(uint32_t n) {
    int res = 0;

    for (int i = 0; i < 32; i++) {
        res += (n >> i) & 1;
    }

    return res;
}

// Brian Kernighan's Algorithm
int hammingWeight(int n)
{
    int count = 0;

    while (n != 0)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}

// Alternative Approach 1 - Right Shift
int hammingWeight(int n)
{
    int count = 0;

    while (n != 0)
    {
        count += (n & 1);
        n = n >> 1;
    }

    return count;
} 

// Alternative Approach 2 — Built-in Function
int hammingWeight(int n)
{
    return __builtin_popcount(n);
}

int main()
{
    int number;
    cin >> number;

    cout << hammingWeight(number) << endl;

    return 0;
}

// Example 1:
// Input: n = 11
// Output: 3
// Explanation: The input binary string 1011 has a total of three set bits.

// Example 2:
// Input: n = 128
// Output: 1
// Explanation: The input binary string 10000000 has a total of one set bit.

// Example 3:
// Input: n = 2147483645
// Output: 30
// Explanation: The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

// ------------------Complexity Comparison -------------------------
// Approach	                         Time Complexity	Space Complexity
// Bitwise AND                             O(1) 	         O(1)
// Modulo and Division                   O(log n)	         O(1)
// Right Shift	                         O(log n)	         O(1)
// Brian Kernighan's Algorithm	            O(k)	         O(1)
// GCC Built-in Function	                O(1)*	         O(1)

// Here, k is the number of set bits.
// *For fixed-width integers. The built-in function is compiler-specific.