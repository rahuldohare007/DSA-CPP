#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> nums)
{

    int n = nums.size();
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0)
            nums[index] = -nums[index];
        else
            result.push_back(abs(nums[i]));
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            result.push_back(i + 1);
    }
    return result;
}

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{

    long long n = grid.size();
    long long N = n * n;

    long long expectedSum = N * (N + 1) / 2;
    long long expectedSquareSum = N * (N + 1) * (2 * N + 1) / 6;

    long long actualSum = 0;
    long long actualSquareSum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long long x = grid[i][j];

            actualSum += x;
            actualSquareSum += x * x;
        }
    }

    long long diff = actualSum - expectedSum;
    // a - b

    long long squareDiff = actualSquareSum - expectedSquareSum;
    // a² - b²

    long long sum = squareDiff / diff;
    // a + b

    long long repeated = (diff + sum) / 2;
    long long missing = sum - repeated;

    return {(int)repeated, (int)missing};
}

int main()
{

    vector<int> nums = {3, 5, 4, 1, 1};
    vector<vector<int>> grid = {{1, 3}, {2, 2}};

    vector<int> result = findMissingRepeatingNumbers(nums);
    vector<int> result2 = findMissingAndRepeatedValues(grid);

    for (int num : result)
    {
        cout << num << " ";
    }

    for (int num : result2)
    {
        cout << num << " ";
    }

    return 0;
}

// Example 1:
// Input: nums = [3, 5, 4, 1, 1]
// Output: [1, 2]
// Explanation: 1 appears two times in the array and 2 is missing from nums

// Example 2:
// Input: nums = [1, 2, 3, 6, 7, 5, 7]
// Output: [7, 4]
// Explanation: 7 appears two times in the array and 4 is missing from nums.

// Time Complexity: O(n)
// Space Complexity: O(1)

// --------------------------------------------------------------------------------

// Example 1:
// Input: grid = [[1,3],[2,2]]
// Output: [2,4]
// Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].

// Example 2:
// Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
// Output: [9,5]
// Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].

// Time Complexity: O(n^2)
// Space Complexity: O(1)