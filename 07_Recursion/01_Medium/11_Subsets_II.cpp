#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

vector<vector<int>> subsetsWithDup(vector<int> &nums){
    vector<vector<int>> result;
    vector<int> currentSubset;

    sort(nums.begin(), nums.end());

    function<void(int)> backtrack = [&](int start) {
        result.push_back(currentSubset);

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
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
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = subsetsWithDup(nums);

    for (const auto &subset : result)
    {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i)
        {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}

// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

// Time Complexity: O(2^n), where n is the number of elements in the input array. In the worst case, we may generate all possible subsets.
// Space Complexity: O(n), where n is the number of elements in the input array. The space complexity is due to the recursion stack and the space used to store the current subset.