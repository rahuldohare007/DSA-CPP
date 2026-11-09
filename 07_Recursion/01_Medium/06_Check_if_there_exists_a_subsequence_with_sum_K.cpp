#include <bits/stdc++.h>
using namespace std;

// Given an array nums and an integer k. Return true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.

void helper(vector<int> &nums, int k, int index, int currentSum, bool &found)
{
    if (index == nums.size())
    {
        if (currentSum == k)
            found = true;
        return;
    }

    helper(nums, k, index + 1, currentSum + nums[index], found);
    helper(nums, k, index + 1, currentSum, found);
}

bool checkSubsequenceSum(vector<int> &nums, int k){
    bool found = false;
    helper(nums, k, 0, 0, found);
    return found;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 8;

    if (checkSubsequenceSum(nums, k))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

// Example 1:
// Input : nums = [1, 2, 3, 4, 5] , k = 8
// Output : Yes
// Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.

// Example 2:
// Input : nums = [4, 3, 9, 2] , k = 10
// Output : No
// Explanation : No subsequence can sum up to 10.

// Time Complexity: O(2^n) where n is the size of the input array. This is because for each element, we have two choices: either include it in the subsequence or exclude it, leading to 2^n possible subsequences.
// Space Complexity: O(n) for the recursion stack, where n is the size of the input array.