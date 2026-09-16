#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &nums)
{
    vector<int> result;
    int max = nums[nums.size() - 1];
    result.push_back(max);

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] > max)
        {
            max = nums[i];
            result.push_back(max);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    vector<int> nums = {4, 7, 1, 0};
    vector<int> result = leaders(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }

    return 0;
}

// Example 1:
// Input: arr = [4, 7, 1, 0]
// Output: 7 1 0
// Explanation: The rightmost element (0) is always a leader.
// 7 and 1 are greater than the elements to their right, making them leaders as well.

// Example 2:
// Input: arr = [10, 22, 12, 3, 0, 6]
// Output: 22 12 6
// Explanation: 6 is a leader because there are no elements after it.
// 12 is greater than all the elements to its right (3, 0, 6), and 22 is greater than 12, 3, 0, 6, making them leaders as well.

// Time Complexity: O(n), where n is the number of elements in the input array nums.
// Space Complexity: O(1), as we are using a constant amount of space for variables max and result.