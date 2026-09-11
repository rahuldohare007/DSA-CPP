#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        int compliment = target - nums[i];
        auto it = mp.find(compliment);
        if (it != mp.end())
        {
            return {it->second, i};
        }
        mp[nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]

// Time Complexity: O(n), where n is the number of elements in the input array nums.
// We traverse the array once, and each lookup and insertion operation in the unordered_map takes O(1) on average.

// Space Complexity: O(n), where n is the number of elements in the input array nums.
// In the worst case, we may store all n elements in the unordered_map.
