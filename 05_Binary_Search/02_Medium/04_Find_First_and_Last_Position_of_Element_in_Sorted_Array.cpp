#include <bits/stdc++.h>
using namespace std;

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

int findFirst(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            ans = mid;
            high = mid - 1; // Search left
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int findLast(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            ans = mid;
            low = mid + 1; // Search right
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int first = findFirst(nums, target);
    if (first == -1)
        return {-1, -1};

    int last = findLast(nums, target);
    return {first, last};
}

// Using STL lower_bound and upper_bound to find the first and last position of target in nums.
vector<int> searchRange(vector<int> &nums, int target)
{
    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

    if (first == nums.size() || nums[first] != target)
    {
        return {-1, -1};
    }

    int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

    return {first, last};
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = searchRange(nums, target);
    cout << "First Position: " << result[0] << ", Last Position: " << result[1] << endl;

    return 0;
}

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]

// Time Complexity: O(log n)
// Space Complexity: O(1)

