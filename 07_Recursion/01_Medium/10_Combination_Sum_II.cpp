#include <bits/stdc++.h>
using namespace std;

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(candidates.begin(), candidates.end());

    function<void(int, int)> findCombinations = [&](int index, int target) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            ds.push_back(candidates[i]);
            findCombinations(i + 1, target - candidates[i]); 
            ds.pop_back();
        }
    };

    findCombinations(0, target);
    return ans;
}

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> result = combinationSum2(candidates, target);

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
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

// Time Complexity : O(2ⁿ × n) — worst case, including copying valid combinations into the answer
// Space Complexity : O(n) — auxiliary recursion stack and temporary combination, excluding the output array.