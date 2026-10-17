#include <bits/stdc++.h>
using namespace std;

// Given a sorted array arr of size n, containing integer positions of n gas stations on the X-axis, and an integer k, place k new gas stations on the X-axis.
// The new gas stations can be placed anywhere on the non-negative side of the X-axis, including non-integer positions.
// Let dist be the maximum distance between adjacent gas stations after adding the k new gas stations.
// Find the minimum value of dist.
// Your answer will be accepted if it is within 1e-6 of the true value.

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    long double low = 0.0;
    long double high = 0.0;

    for (int i = 1; i < arr.size(); i++)
    {
        high = max(high, (long double)(arr[i] - arr[i - 1]));
    }

    while (high - low > 1e-7)
    {
        long double mid = low + (high - low) / 2.0;
        int stations = 0;

        for (int i = 1; i < arr.size(); i++)
        {
            int needed = ceil((arr[i] - arr[i - 1]) / mid) - 1;
            stations += needed;

            if (stations > k)
                break;
        }

        if (stations > k)
            low = mid;
        else
            high = mid;
    }

    return high;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 10;

    cout << fixed << setprecision(5) << minimiseMaxDistance(arr, k) << '\n';
    return 0;
}

// Example 1:
// Input: n = 10, arr = [1, 2, 3, 4, 5, 6 ,7, 8, 9, 10], k = 10
// Output: 0.50000
// Explanation:
// There are initially 10 gas stations from 1 to 10. We need to add 10 new gas stations.
// Place the new stations at: [1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5]
// The resulting positions are: [1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10, 10.5]
// The maximum distance between adjacent gas stations is 0.5.
// Hence, the minimum possible value of dist is 0.5.

// Example 2:
// Input : n = 10, arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 1
// Output: 1.00000
// Explanation:
// One of the possible ways to place 1 gas station is [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].
// New Gas Station is at 11.
// Thus the maximum difference between adjacent gas stations is still 1.
// Hence, the value of dist is 1.
// It can be shown that there is no possible way to add 1 gas station in such a way that the value of dist is lower than this.

// Time Complexity: O(n log (D/e)), where D is the largest initial gap and e is the precision.
// Space Complexity: O(1)