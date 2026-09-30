#include <bits/stdc++.h>
using namespace std;

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

int subarraySum()
{
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;

    int currentSum = 0;
    int count = 0;

    for (int num : nums)
    {
        currentSum += num;

        if (prefixSum.find(currentSum - k) != prefixSum.end())
        {
            count += prefixSum[currentSum - k];
        }

        prefixSumCount[currentSum]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << subarraySum(nums, k) << endl;

    return 0;
}

// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2

// Time Complexity: O(n)
// Space Complexity: O(n)