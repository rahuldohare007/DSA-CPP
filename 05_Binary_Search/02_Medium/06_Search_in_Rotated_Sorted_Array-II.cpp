#include <bits/stdc++.h>
using namespace std;

// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
// You must decrease the overall operation steps as much as possible.

bool search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++;
            high--;
        }
        else if (nums[low] <= nums[mid])
        {
            if (target >= nums[low] && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    bool result = search(nums, target);
    cout << (result ? "true" : "false") << endl;

    return 0;
}

// Example 1:
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true

// Example 2:
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false

// Time Complexity: O(log n)
// Space Complexity: O(1)