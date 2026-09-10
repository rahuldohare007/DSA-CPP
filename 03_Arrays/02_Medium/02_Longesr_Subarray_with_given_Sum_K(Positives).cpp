#include <bits/stdc++.h>
using namespace std;

// Sliding Window Approach
int longestSubarrayWithSumK(vector<int> &nums, int targetSum)
{
    int left = 0, currentSum = 0, maxLength = 0;

    for (int right = 0; right < nums.size(); ++right)
    {
        currentSum += nums[right];

        while (currentSum > targetSum && left <= right)
        {
            currentSum -= nums[left];
            ++left;
        }

        if (currentSum == targetSum)
        {
            maxLength = max(maxLength, right - left + 1);
        }
    }

    return maxLength;
}

int main()
{
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int targetSum = 15;

    int result = longestSubarrayWithSumK(nums, targetSum);
    cout << "The length of the longest subarray with sum " << targetSum << " is: " << result << endl;

    return 0;
}

// Example:
// Input: nums = [10, 5, 2, 7, 1, 9], targetSum = 15
// Output: 4 (The longest subarray is [5, 2, 7, 1])

// Time Complexity: O(n)
// Space Complexity: O(1)

// ---------------Longest Subarray with Sum K — Sliding Window---------------------------------
// Approach: Two Pointers / Sliding Window
// left → starting index of window.
// right → expands the window.
// currentSum → sum of current window.
// maxLength → stores maximum length found.
// ----------------------------------Logic------------------
// 1. Initialize left = 0, currentSum = 0, maxLength = 0.
// 2. Iterate right from 0 to n-1:
//    a. Add nums[right] to currentSum.
//    b. While currentSum > targetSum and left <= right:
//       i. Subtract nums[left] from currentSum.
//       ii. Increment left.
//    c. If currentSum == targetSum:
//       i. Update maxLength = max(maxLength, right - left + 1).
// 3. Return maxLength.