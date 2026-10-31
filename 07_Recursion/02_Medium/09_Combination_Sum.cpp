#include <bits/stdc++.h>
using namespace std;

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

vector<vector<int>> combinationSum(vector<int> &candidates, int target){
    vector<vector<int>> ans;
    vector<int> ds;

    function<void(int, int)> findCombinations = [&](int index, int target) {
        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // Include the current candidate
        if (candidates[index] <= target) {
            ds.push_back(candidates[index]);
            findCombinations(index, target - candidates[index]);
            ds.pop_back();
        }

        // Exclude the current candidate and move to the next
        findCombinations(index + 1, target);
    };

    findCombinations(0, target);
    return ans;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j != result[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != result.size() - 1)
            cout << ",";
    }

    return 0;
}

// Example 1:
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Example 2:
// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

// Example 3:
// Input: candidates = [2], target = 1
// Output: []

// Time Complexity: O(2^t * k), where t is the target value and k is the average length of each combination. The 2^t factor comes from the fact that for each candidate, we have two choices: include it or exclude it. The k factor accounts for the time taken to copy each valid combination to the answer list.
// Space Complexity: O(k * x), where k is the average length of each combination and x is the number of valid combinations. The space is used to store the combinations in the answer list. Additionally, there is a recursive call stack that can go up to a depth of t (the target value) in the worst case, which contributes to the space complexity as well.