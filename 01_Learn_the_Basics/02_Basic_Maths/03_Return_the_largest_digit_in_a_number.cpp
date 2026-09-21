#include <bits/stdc++.h>
using namespace std;

int largestDigit(int n)
{
    int res = 0;
    while (n > 0)
    {
        res = max(res, n % 10);
        n /= 10;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << largestDigit(n) << endl;

    return 0;
}

// Example 1:
// Input: n = 123
// Output: 3

// Example 2:
// Input: n = 999
// Output: 9

// Time Complexity: O(log(n))
// Space Complexity: O(1)