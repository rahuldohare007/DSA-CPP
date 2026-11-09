#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

vector<vector<int>> subsets(vector<int> &nums)
{

    vector<vector<int>> result;
    vector<int> currentSubset;

    function<void(int)> backtrack = [&](int index)
    {
        result.push_back(currentSubset);

        for (int i = index; i < nums.size(); i++)
        {
            currentSubset.push_back(nums[i]);
            backtrack(i + 1);
            currentSubset.pop_back();
        }
    };

    backtrack(0);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

// Time Complexity: O(2^n), where n is the number of elements in the input array.
// This is because for each element, we have two choices: either include it in the current subset or exclude it.

// Space Complexity: O(n), where n is the number of elements in the input array.
// This is because we are using a recursive approach, and the maximum depth of the recursion tree can go up to n. Additionally, we are storing the current subset in a vector, which can also take up to O(n) space in the worst case.
