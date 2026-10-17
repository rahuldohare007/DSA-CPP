#include <bits/stdc++.h>
using namespace std;

// Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.
// If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.

int rowWithMax1s(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int maxOnes = 0;
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        int low = 0, high = m - 1;
        int firstOne = m;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (mat[i][mid] == 1)
            {
                firstOne = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        int ones = m - firstOne;

        if (ones > maxOnes)
        {
            maxOnes = ones;
            ans = i;
        }
    }

    return ans;
}

// Staircase Approach

int rowWithMax1s_Staircase(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int row = 0, col = m - 1;
    int ans = -1;

    while (row < n && col >= 0) {
        if (mat[row][col] == 1) {
            ans = row;
            col--;       // Move left to find more 1s
        } else {
            row++;       // Move down to the next row
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 0}};

    cout << rowWithMax1s(mat) << endl;
    cout << rowWithMax1s_Staircase(mat) << endl;

    return 0;
}

// Example 1:
// Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]
// Output: 0
// Explanation: The row with the maximum number of ones is 0 (0 - indexed).

// Example 2:
// Input: mat = [ [0, 0], [0, 0] ]
// Output: -1
// Explanation: The matrix does not contain any 1. So, -1 is the answer.

// Time Complexity: O(N log M)
// Space Complexity: O(1)

// Staircase Approach-
// Time Complexity: O(N + M)
// Space Complexity: O(1)
