#include <bits/stdc++.h>
using namespace std;

// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Find maximum element in the middle column
        int row = 0;
        for (int i = 1; i < m; i++)
        {
            if (mat[i][mid] > mat[row][mid])
            {
                row = i;
            }
        }

        int left = (mid > 0) ? mat[row][mid - 1] : -1;
        int right = (mid + 1 < n) ? mat[row][mid + 1] : -1;

        // Found a peak
        if (mat[row][mid] > left && mat[row][mid] > right)
        {
            return {row, mid};
        }

        // Move toward the larger neighbor
        if (left > mat[row][mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}};

    vector<int> ans = findPeakGrid(mat);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}

// Example 1:
// Input: mat = [[1,4],[3,2]]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

// Example 2:
// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.

// Time Complexity: O(m log(n)) or O(n log(m)), where m is the number of rows and n is the number of columns in the matrix. This is because we perform a binary search on either the rows or columns, and for each step, we find the maximum element in that row or column which takes linear time. 
// Space Complexity: O(1)