#include <bits/stdc++.h>
using namespace std;

// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

double myPow(double x, int n)
{
    long long binForm = n;
    long double base = x;

    if (binForm < 0)
    {
        base = 1.0L / base;
        binForm = -binForm;
    }

    long double ans = 1.0L;

    while (binForm > 0)
    {
        if (binForm % 2 == 1)
        {
            ans *= base;
        }

        base *= base;
        binForm /= 2;
    }

    return (double)ans;
}

// Recursive approach
double myPowRecursive(double x, int n){
    if(n == 0) return 1;
    if(n < 0) return myPowRecursive(1/x, -n);
    if(n % 2 == 0) return myPowRecursive(x * x, n / 2);
    return x * myPowRecursive(x * x, n / 2);
}

int main()
{
    double x;
    int n;

    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Result using iterative approach: " << myPow(x, n) << endl;
    cout << "Result using recursive approach: " << myPowRecursive(x, n) << endl;
    return 0;
}

// Example 1:
// Input: x = 2.00000, n = 10
// Output: 1024.00000

// Example 2:
// Input: x = 2.10000, n = 3
// Output: 9.26100

// Example 3:
// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

// Time Complexity:
// Iterative approach: O(log n)
// Recursive approach: O(log n)

// Space Complexity:
// Iterative approach: O(1)
// Recursive approach: O(log n)