#include <bits/stdc++.h>
using namespace std;

// Given two numbers N and M, find the Nth root of M.
// The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M.
// If the Nth root is not an integer, return -1.

// Returns 1 if mid^N == M,
//        0 if mid^N < M,
//       -1 if mid^N > M
int powerCompare(int mid, int N, int M)
{
    long long result = 1;

    for (int i = 0; i < N; i++)
    {
        result *= mid;

        if (result > M)
            return -1;
    }

    if (result == M)
        return 1;

    return 0;
}

int NthRoot(int N, int M)
{
    int low = 1, high = M;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int check = powerCompare(mid, N, M);

        if (check == 1)
            return mid;
        else if (check == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int N = 3, M = 27;
    int result = NthRoot(N, M);

    cout << result << endl;
    return 0;
}

// Example 1:
// Input: N = 3, M = 27
// Output: 3
// Explanation: The cube root of 27 is equal to 3.

// Example 2:
// Input: N = 4, M = 69
// Output:-1
// Explanation: The 4th root of 69 does not exist. So, the answer is -1.

// Time Complexity: O(N log M)
// Space Complexity: O(1)