#include <bits/stdc++.h>
using namespace std;

// Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.

void helper(vector<int> &nums, int k, int index, int currentSum, int &count)
{
    if (index == nums.size())
    {
        if (currentSum == k)
            count++;
        return;
    }

    helper(nums, k, index + 1, currentSum + nums[index], count);
    helper(nums, k, index + 1, currentSum, count);
}

int countSubsequenceWithTargetSum(vector<int> &nums, int k){
    int count = 0;
    helper(nums, k, 0, 0, count);
    return count;
}

int main()
{
    vector<int> nums = {4, 9, 2, 5, 1};
    int k = 10;

    cout << countSubsequenceWithTargetSum(nums, k) << endl;
    return 0;
}

// Example 1:
// Input : nums = [4, 9, 2, 5, 1] , k = 10
// Output : 2
// Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].

// Example 2:
// Input : nums = [4, 2, 10, 5, 1, 3] , k = 5
// Output : 3
// Explanation : The possible subsets with sum k are [4, 1] , [2, 3] , [5].

// Time Complexity: O(2^n) where n is the size of the input array. This is because for each element, we have two choices: either include it in the subsequence or exclude it, leading to 2^n possible subsequences.
// Space Complexity: O(n) for the recursion stack, where n is the size of the input array.