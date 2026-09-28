#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, find a subarray that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.
// Note that the product of an array with a single element is the value of that element.

int maxProduct(vector<int> &nums)
{
    int res = *max_element(nums.begin(), nums.end());
    int curMax = 1, curMin = 1;

    for (int n : nums)
    {
        int temp = curMax * n;
        curMax = max({temp, curMin * n, n});
        curMin = min({temp, curMin * n, n});

        res = max(res, curMax);
    }

    return res;
}

int main()
{
    vector<int> nums = {2, 3, -2, 4};
    cout << maxProduct(nums) << endl;

    return 0;
}

// Example 1:
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:
// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

// Time Complexity: O(n)
// Space Complexity: O(1)