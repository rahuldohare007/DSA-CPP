#include <bits/stdc++.h>
using namespace std;

// Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.

int kthElement(vector<int> &a, vector<int> &b, int k)
{
    int m = a.size();
    int n = b.size();

    if (k < 1 || k > m + n)
        return -1;

    // Binary search on the smaller array
    if (m > n)
    {
        swap(a, b);
        swap(m, n);
    }

    int low = max(0, k - n);
    int high = min(k, m);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int left = mid;
        int right = k - left;

        int aLeft = (left == 0) ? INT_MIN : a[left - 1];
        int aRight = (left == m) ? INT_MAX : a[left];

        int bLeft = (right == 0) ? INT_MIN : b[right - 1];
        int bRight = (right == n) ? INT_MAX : b[right];

        if (aLeft <= bRight && bLeft <= aRight)
        {
            return max(aLeft, bLeft);
        }
        else if (aLeft > bRight)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << kthElement(a, b, k) << endl;
    
    return 0;
}

// Example 1:
// Input: a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5
// Output: 6
// Explanation: The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

// Example 2:
// Input: a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7
// Output: 256
// Explanation: Final sorted array is - [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892], 7th element of this array is 256.

// Time Complexity: O(log(min(m, n)))
// Space Complexity: O(1)