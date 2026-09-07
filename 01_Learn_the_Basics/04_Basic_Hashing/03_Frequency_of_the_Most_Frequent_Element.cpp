#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    long long total = 0;
    int left = 0, result = 1;
    for (int right = 1; right < nums.size(); ++right)
    {
        total += (long long)(nums[right] - nums[right - 1]) * (right - left);
        while (total > k)
        {
            total -= nums[right] - nums[left];
            left++;
        }
        result = max(result, right - left + 1);
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 4};
    int k = 5;

    cout << maxFrequency(nums, k) << endl;

    return 0;
}

// Input: nums = [1,4,8,13], k = 5
// Output: 2
// Explanation: There are multiple optimal solutions:
// - Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
// - Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
// - Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.

// Time Complexity: O(n log n), where n is the number of elements in the input array.
//  This is due to the sorting step, which takes O(n log n) time. The two-pointer approach runs in O(n) time, but the overall complexity is dominated by the sorting step.

// Space Complexity: O(1), as we are using a constant amount of extra space for variables and pointers, regardless of the input size.
//  The sorting is done in-place, so no additional space is required for that step.