#include <bits/stdc++.h>
using namespace std;

// Given a positive integer n. Find and return its square root.
// If n is not a perfect square, then return the floor value of sqrt(n).

int floorSqrt(int n)
{

    if (n == 0 || n == 1)
    {
        return n;
    }

    int low = 1, high = n, ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid <= n / mid)
        {                  // To avoid overflow
            ans = mid;     // Update answer
            low = mid + 1; // Search in the right half
        }
        else
        {
            high = mid - 1; // Search in the left half
        }
    }

    return ans;
}

int main()
{
    int n = 36;
    int result = floorSqrt(n);

    cout << result << endl; // Output: 6
    return 0;
}

// Example 1:
//  Input: n = 36
//  Output: 6
//  Explanation: 6 is the square root of 36.

// Example 2:
// Input: n = 28
// Output: 5
// Explanation: The square root of 28 is approximately 5.292. So, the floor value will be 5.

// Time Complexity: O(log n)
// Space Complexity: O(1)