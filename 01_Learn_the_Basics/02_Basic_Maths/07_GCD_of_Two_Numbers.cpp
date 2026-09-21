#include <bits/stdc++.h>
using namespace std;

// Recursive Approach
int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}

int GCD_Iterative(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int main()
{

    int a, b;
    cin >> a >> b;
    cout << GCD(a, b) << endl;
    cout << GCD_Iterative(a, b) << endl;

    return 0;
}

// Example Input: a = 48, b = 18
// Example Output: 6

// Time Complexity:
// Iterative: O(log(min(a, b)))
// Space Complexity: O(1)

// Time Complexity:
// Recursive: O(log(min(a, b)))
// Space Complexity: O(log(min(a, b)))