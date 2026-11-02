#include <bits/stdc++.h>
using namespace std;

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

vector<vector<int>> combinationSum3(int k, int n){
    vector<vector<int>> result;
    vector<int> currentCombination;

    function<void(int, int, int)> backtrack = [&](int start, int remainingSum, int remainingCount) {
        if (remainingSum == 0 && remainingCount == 0) {
            result.push_back(currentCombination);
            return;
        }
        if (remainingSum < 0 || remainingCount < 0) {
            return;
        }

        for (int i = start; i <= 9; ++i) {
            currentCombination.push_back(i);
            backtrack(i + 1, remainingSum - i, remainingCount - 1);
            currentCombination.pop_back();
        }
    };

    backtrack(1, n, k);
    return result;
}

int main()
{
    int k = 3, n = 7;

    vector<vector<int>> result = combinationSum3(k, n);

    for (const auto &combination : result)
    {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i)
        {
            cout << combination[i];
            if (i < combination.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}

// Example 1:
// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

// Example 2:
// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.

// Example 3:
// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

// Time Complexity: O(2^9), since we are exploring all combinations of numbers from 1 to 9. The maximum number of combinations is 2^9.
// Space Complexity: O(k), where k is the number of elements in the current combination.