#include <bits/stdc++.h>
using namespace std;

// Given two intergers r and c, return the value at the rth row and cth column (1 - indexed) in a Pascal's triangle.
int pascalTriangle(int r, int c)
{
    // Convert to 0-indexed
    r--;
    c--;

    c = min(c, r - c);

    long long ans = 1;

    for (int i = 0; i < c; i++)
    {
        ans = ans * (r - i) / (i + 1);
    }

    return ans;
}

int main()
{
    int r = 5;
    int c = 3;

    cout << pascalTriangle(r, c);
}

// Example:
// Input: r = 4, c = 2
// Output: 3

// Example:
// Input: r = 5, c = 3
// Output: 6

// Time Complexity: O(n)
// Space Complexity: O(1)
