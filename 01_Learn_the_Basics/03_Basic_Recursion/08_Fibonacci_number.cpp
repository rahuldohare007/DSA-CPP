#include <bits/stdc++.h>
using namespace std;

// Iterative Approach: Using Memorization
int fib(int n)
{
    vector<int> dp(n + 1, -1);
    return ans(n, dp);
}
int ans(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = ans(n - 1, dp) + ans(n - 2, dp);
    // Explanation: Dp[N] = ans(N - 1, Dp) + ans(N - 2, Dp);
    // In this approach, we are storing the results of the subproblems in a vector Dp to avoid recalculating them, which reduces the time complexity from exponential to linear.
}

// Iterative Approach: Without Memorization
int fibonacci_iterative(int N)
{
    if (N <= 1)
        return N;

    int prev = 0;
    int curr = 1;

    for (int i = 2; i <= N; i++)
    {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }

    return curr;
}

// Recursive Approach
int fibonacci_recursive(int N, vector<int> &Dp)
{
    if (N == 0)
        return 0;
    if (N == 1)
        return 1;
    return ans(N - 1, Dp) + ans(N - 2, Dp);
}

int main()
{
    vector<int> Dp(1000, -1);
    int N;
    cin >> N;

    cout << fib(N) << endl;
    cout << fibonacci_iterative(N) << endl;
    cout << fibonacci_recursive(N, Dp) << endl;

    return 0;
}

// Iterative Approach: Without Memorization:
// Time Complexity: O(N)
// Space Complexity: O(1)

// Iterative Approach: Using Memorization:
// Time Complexity: O(N)
// Space Complexity: O(N) (due to the dp vector)

// Recursive Approach:
// Time Complexity: O(2^N)
// Space Complexity: O(N) (due to recursion stack)