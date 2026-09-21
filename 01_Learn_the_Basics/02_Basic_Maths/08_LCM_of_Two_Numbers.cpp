#include <bits/stdc++.h>
using namespace std;

// Iterative approach
int LCM_Iterative(int a, int b)
{
    int res = max(a, b);
    while (res % a != 0 || res % b != 0)
    {
        res += max(a, b);
    }
    return res;
}

// Recursive approach
int LCM(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return LCM(b, a % b);
}

int main()
{

    int a, b;
    cin >> a >> b;
    cout << LCM_Iterative(a, b) << endl;
    cout << LCM(a, b) << endl;

    return 0;
}

// Example Input: a = 48, b = 18
// Example Output: 144

// Time Complexity:
// Iterative: O(log(min(a, b)))
// Space Complexity: O(1)

// Time Complexity:
// Recursive: O(log(min(a, b)))
// Space Complexity: O(log(min(a, b)))
