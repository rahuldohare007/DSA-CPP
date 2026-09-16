#include <bits/stdc++.h>
using namespace std;

void nextpermutation(vector<int> &nums)
{
    int n = nums.size();
    int i = n - 2;

    // Find the first element that is smaller than its next element
    while (i >= 0 && nums[i] >= nums[i + 1])
    {
        i--;
    }

    // If no such element is found, reverse the entire array
    if (i >= 0)
    {
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i])
        {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    // Reverse the subarray from i + 1 to the end
    reveres(nums.begin() + i + 1, nums.end());
}
int main()
{
    vector<int> nums = {1, 2, 3};
    nextpermutation(nums);

    return 0;
}

// Example 1:
// Input: nums = [1,2,3]
// Output: [1,3,2]

// Example 2:
// Input: nums = [3,2,1]
// Output: [1,2,3]

// Example 3:
// Input: nums = [1,1,5]
// Output: [1,5,1]

// Time Complexity: O(n)
// Space Complexity: O(1)