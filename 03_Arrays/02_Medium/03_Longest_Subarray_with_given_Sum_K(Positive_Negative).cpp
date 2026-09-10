#include <bits/stdc++.h>
using namespace std;

// Prefix Sum + HashMap Approach
int longestSubarrayWithSumK(vector<int> &nums, int k)
{
    unordered_map<long long, int> mp;

    long long sum = 0;
    int maxLength = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        // If sum itself is K
        if (sum == k)
            maxLength = i + 1;

        // Check for previous prefix sum
        if (mp.find(sum - k) != mp.end())
        {
            maxLength = max(maxLength, i - mp[sum - k]);
        }

        // Store only first occurrence
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }

    return maxLength;
}

int main()
{
    vector<int> nums = {-1, 1, 1};
    int targetSum = 1;
    int result = longestSubarrayWithSumK(nums, targetSum);
    cout << "The length of the longest subarray with sum " << targetSum << " is: " << result << endl;
    return 0;
}

// Example 1:
// Input Format: N = 3, k = 5, array[] = {2,3,5}
// Result: 2
// Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

// Example 2:
// Input Format: N = 3, k = 1, array[] = {-1, 1, 1}
// Result: 3
// Explanation: The longest subarray with sum 1 is {-1, 1, 1}. And its length is 3.

// Time Complexity: O(n)
// Space Complexity: O(n)

// ------------------------------Approach: Prefix Sum + HashMap--------------------------
// * sum → current prefix sum.
// * Store {prefixSum → first index} in hashmap.
// * Check sum - k.
// * If sum - k exists:   length = i - mp[sum - k];
// * Store only the first occurrence of a prefix sum → gives the longest length.
// * Handles positive, zero, and negative numbers.