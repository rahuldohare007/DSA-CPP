#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int j = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    return 0;
}

// Example:
// Input: nums = [0, 1, 0, 3, 12]
// Output: [1, 3, 12, 0, 0]

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are modifying the array in place and not using any additional data structures.